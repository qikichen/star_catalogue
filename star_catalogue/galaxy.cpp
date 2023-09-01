#include "galaxy.h"

bool Galaxy::operator==(Galaxy &other) const
//Overload the operator == to compare galaxy names
{
    return name == other.name;
}

std::string Galaxy::get_name()
//Getter function : Name
{
    return name;
}

void Galaxy::add_singular_objects(std::shared_ptr<SingularObjects> content)
//Adds singular objects to the galaxy
{
    bool exists = false;
    for (const auto& ptr : contents) {
        if (ptr->get_name() == content->get_name()) { //Validate
            std::cout << "Object already exists in the galaxy" << std::endl;
            exists = true;
            break;
        }
    }
    if (!exists) {
        contents.emplace_back(std::move(content));
    }
}

void Galaxy::celestial_body_info()
//Prints celestial body info
{
    std::cout << "The Galaxy: " << name << std::endl;
    std::cout << "Mass: " << get_mass() << std::endl;

    if (contents.size() > 0) {
        std::cout << "The Galaxy has the following constituents:" << std::endl;
        for (const auto& ptr : contents) {
            std::cout << ptr->get_name() << std::endl;
        }
    } else {
        std::cout << "The Galaxy has no constituents" << std::endl;
    }
}

double Galaxy::get_mass()
//Calculates the mass of a galaxy from the constituents
{
    double total_mass = 0.0;
    for (const auto& ptr : contents) {
        total_mass += ptr->get_mass();
    }
    return total_mass;
}

std::vector<std::shared_ptr<SingularObjects>>& Galaxy::get_contents()
//Getter function : contents
{
    return contents;
}

const std::vector<std::shared_ptr<SingularObjects>>& Galaxy::get_const_contents() const
//Getter function : const contents
{
    return contents;
}

void Galaxy::set_contents(std::vector<std::shared_ptr<SingularObjects>> new_content)
//Setter function : contents
{
    contents = std::move(new_content);
}

void Galaxy::specific_object(int key)
//Prints the celestial body info of a specific object
{
    if (key < 0 || key >= contents.size()) {
        std::cout << "Invalid index, please try again" << std::endl;
        return;
    }
    contents.at(key)->celestial_body_info();
}

std::vector<std::shared_ptr<SingularObjects>> Galaxy::filter_by_type(std::string type)
//Filters the contetns array by type
{
    std::vector<std::shared_ptr<SingularObjects>> filtered_objects;
    for (const auto& ptr : contents) {
        if (ptr->get_object_type() == type) {
            std::cout << "Filtered object: " << ptr->get_name() << std::endl;
            filtered_objects.push_back(ptr);
        }
    }
    return filtered_objects;
}