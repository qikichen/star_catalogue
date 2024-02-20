#include "data.h"

void string_formatter(std::string &in)
//Formats strings to have no space and upper case them
{
    in.erase(remove_if(in.begin(), in.end(), ::isspace), in.end());
    transform(in.begin(), in.end(), in.begin(), ::toupper);
    while (std::cin.fail()==true || std::cin.peek() != '\n'){ //Validation
        std::cout << "Please input a valid input (eg. no spaces)" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> in;
        }

}

double double_validation()
//valdiates doubles
{
    //validates integer values
    double unvalidated{};
    bool failure{true};
    while(failure == true ){
        std::cout << "That was invalid, please try again" << std::endl;;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> std::scientific >>unvalidated;
        //Conditions required to pass the validation
        if (std::cin.fail()==false && std::cin.peek() != '.' && unvalidated > 0 && std::cin.peek() == '\n'){
            failure = false;   
        }
        
    }
    return unvalidated;
}

std::string star_type_validator(std::string& in) 
//Validation for star types
{
    std::set<std::string> valid_types{"O", "B", "A", "F", "G", "K", "M"}; // Set for efficiency and valid types available

    while (valid_types.count(in) == 0) { //While loop for invalidity
        std::cout << "That was not valid! Please enter one of the following: O, B, A, F, G, K, or M." << std::endl;
        std::string validated_input;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> validated_input;
        string_formatter(validated_input);
        in = validated_input;
    }

    return in;
}

void create(std::vector<std::shared_ptr<Galaxy>>& data_vector)
//Function creates a file from the main vector aka save function
{
    std::ofstream fout;
    fout.open(ask_filename(), std::ios::out);
    if (!fout.is_open()) {
        fout.close(); // close the file before throwing
        throw std::runtime_error("Error opening file.");
    } // add this closing curly brace

    for (auto it = data_vector.begin(); it != data_vector.end(); ++it) {
        const std::string& name = (*it)->get_name();
        const auto& contents = (*it)->get_contents();
        for(auto it_2 = contents.begin(); it_2 != contents.end(); ++it_2){
            const std::string& object_type{(*it_2)->get_object_type()};
            const std::string& singular_obj_name{(*it_2)->get_name()};
            const double& mass{(*it_2)->get_mass()};
            const double& redshift{(*it_2)->get_redshift()};
            const double& radius{(*it_2)->get_radius()};
            std::string orbit{"NA"};
            std::string star_type{"NA"};
            if (object_type == "PLANET") {
                auto planet = std::dynamic_pointer_cast<Planets>(*it_2);
                if (planet) {
                    orbit = planet->get_orbiting_star();
                }
            }
            if (object_type == "STAR") {
                auto star = std::dynamic_pointer_cast<Stars>(*it_2);
                if (star) {
                    star_type = star->get_star_type();
                }
            }
            fout << name << ","
                << object_type << ","
                << singular_obj_name << ","
                << mass << ","
                << redshift << ","
                << radius << ",";
            if (object_type == "STAR") {
                fout << star_type << ",";
            } else {
                fout << "NA,";
            }
            if (object_type == "PLANET") {
                fout << orbit;
            } else {
                fout << "NA";
            }
            fout << "\n";
        }
    }
    fout.close();
}

std::string ask_filename()
//Function asks for file name 
{
    std::string name;
    std::cout << "What is the name of the file? (please add .csv towards the end)" << std::endl;
    std::cin >> name;
    return name;
};


void read_data(std::vector<std::shared_ptr<Galaxy>>& data_vector) 
// The file reading function stores the data in the data vector
{
    std::string file_name;
    std::ifstream myfile;
    std::string string_stored;
    file_name = ask_filename();

    std::fstream my_file(file_name, std::ios::in);
    if (my_file.is_open()) {
        while (std::getline(my_file, string_stored)) {
            if (string_stored.empty()) {
                continue;
            }
            std::string gala, type, name, orbital, st;
            double mass, rs, radius;
            std::stringstream str(string_stored);
            std::getline(str, gala, ',');
            std::getline(str, type, ',');
            std::getline(str, name, ',');
            str >> mass;
            if (str.peek() == ',') str.ignore();
            str >> rs;
            if (str.peek() == ',') str.ignore();
            str >> radius;
            if (str.peek() == ',') str.ignore();
            std::getline(str, orbital, ',');
            std::getline(str, st);

            std::shared_ptr<SingularObjects> ob;
            if (type == "NEUTRONSTAR") {
                ob = std::make_shared<NeutronStars>(name, mass, rs, radius);
            }
            else if (type == "STAR") {
                std::string validated_input = star_type_validator(st);
                ob = std::make_shared<Stars>(name, mass, rs, radius, validated_input);
            }
            else if (type == "PLANET") {
                ob = std::make_shared<Planets>(name, mass, rs, radius, orbital);
            }
            std::shared_ptr<Galaxy> galaxy_ptr = std::make_shared<Galaxy>(gala);
            auto it = std::find_if(data_vector.begin(), data_vector.end(), [&](const std::shared_ptr<Galaxy>& ptr) { return ptr->get_name() == galaxy_ptr->get_name(); });
            if (it != data_vector.end()) {
                int gal_index = std::distance(data_vector.begin(), it);
                data_vector.at(gal_index)->add_singular_objects(std::move(ob));
            }
            else {
                std::cout << "GalaxyAdded" << std::endl;
                galaxy_ptr->add_singular_objects(std::move(ob));
                data_vector.emplace_back(std::move(galaxy_ptr));
            }
        }
    }
    myfile.close();
}


void add_galaxy(std::vector<std::shared_ptr<Galaxy>>& data_vector)
//Function to add galaxies
{
    std::cout << "How many Galaxies would you like to add?" << std::endl;
    int galaxy_number;
    std::cin >> galaxy_number;

    while (std::cin.fail() || std::cin.peek() != '\n') {
        std::cout << "Please input a valid number" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> galaxy_number;
    }

    for (int i = 0; i < galaxy_number; i++) {
        std::cout << "Enter a galaxy: " << std::endl;
        std::string gal;
        std::cin >> gal;
        string_formatter(gal);

        bool exists = false; //BOOLEAN CHECKING FOR THE EXISTANCE OF A GALAXY
        for (const auto& galaxy : data_vector) {
            if (galaxy->get_name() == gal) {
                exists = true;
                break;
            }
        }

        if (exists) {
            std::cout << "Galaxy " << gal << " already exists." << std::endl;
        } else {
            std::shared_ptr<Galaxy> galaxy_ptr = std::make_shared<Galaxy>(gal);
            data_vector.emplace_back(std::move(galaxy_ptr));
            std::cout << "Galaxy added" << std::endl;
        }
    }
}


void add_to_galaxy(std::vector<std::shared_ptr<Galaxy>> &data_vector, std::string galaxy_name)
//adds a galaxy to the master 
{
    int key{search<Galaxy>(data_vector, galaxy_name)};
    if(key == -1){
        std::cout << "No Galaxy called " << galaxy_name << " found!" << std::endl;
    }
    else{
        std::cout << "Key found!" << std::endl;
        //ALL YOU NEED TO DO IS ADD APPROPRIATE OBJECT IN THERE!!!!!
        std::string type, name, orbital, st;
        double mass, rs, radius;

        std::cout << "Enter a body type (STAR, PLANET, NEUTRONSTAR): " << std::endl;
        std::string body_type;
        std::cin.clear();
        std::cin.ignore();
        std::cin >> body_type;
        string_formatter(body_type);
        if(body_type == "STAR" || body_type ==  "PLANET" || body_type == "NEUTRONSTAR"){
            std::cout << "Enter a name:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> name;
            string_formatter(name);

            std::cout << "Enter a mass in kg (you can use scientific notation eg: 2E3):" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> std::scientific >>mass;
            if (std::cin.fail()==true || std::cin.peek() == '.' || std::cin.peek() != '\n' || mass <= 0){
                mass = double_validation();
            }

            std::cout << "Enter a redshift" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> std::scientific>>rs;
            if (std::cin.fail()==true || std::cin.peek() == '.' || std::cin.peek() != '\n' || rs <= 0){
                rs = double_validation();
            }

            std::cout << "Enter a radius in m (you can use scientific notation eg: 2E3):" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> std::scientific >>radius;
            if (std::cin.fail()==true || std::cin.peek() == '.' || std::cin.peek() != '\n' || radius <= 0){
                radius = double_validation();
            }

            if (body_type == "STAR") {
            std::cout << "Enter a Star Type (OBAFGKM): " << std::endl;
            std::string star_type;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> star_type;
            string_formatter(star_type);
            st = star_type_validator(star_type);
            std::shared_ptr<Stars> star_ptr = std::make_shared<Stars>(name, mass, rs, radius, st);
            data_vector.at(key)->add_singular_objects(std::move(star_ptr));
        }

            else if (body_type == "PLANET") {
                std::cout << "Enter which Star the Planet is orbiting: " << std::endl;
                std::string orbit;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> orbit;
                string_formatter(orbit);
                std::shared_ptr<Planets> planet_ptr = std::make_shared<Planets>(name, mass, rs, radius, orbital);
                data_vector.at(key)->add_singular_objects(std::move(planet_ptr));
            }
            else if(body_type == "NEUTRONSTAR"){
                std::shared_ptr<NeutronStars> neutron_ptr = std::make_shared<NeutronStars>(name, mass, rs, radius);
                data_vector.at(key)->add_singular_objects(std::move(neutron_ptr));

            }
        }
        else{
            std::cout << "Invalid body type choice" << std::endl;
        }
    }
}