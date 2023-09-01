/*
STAR CATALOGUE:

The C++ code is the final project of the Object Oriented Programming in C++ module from the University of Manchester. 
The code can read data in from CSV files and can write data and turn them into CSV files. 
The functionality of the code:
    - Search galaxies and singular objects
    - Filter and Sort the data
    - Delete Galaxies and Singular Objects
    - Add galaxies or singular Objects

Singular Objects:
    - Planets
    - Neutronstars
    - Stars

It should be noted: Most galaxies and singular bodies are imaginary/made up and parameters may be unphysical. They do however prove the concepts
learned in the OOP module and takes advantage of all the features.

- written by Qi Nohr Chen
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include "other_functions.h"
#include "celestialbodies.h"
#include "singularobjects.h"
#include "stars.h" 
#include "planets.h"
#include "neutronstars.h"
#include "galaxy.h"
#include "sorting.h"
#include "data.h"
#include "menu.h"


int main()
//MAIN FUNCTION: Calls all the functions of the program
{

    std::vector<std::shared_ptr<Galaxy>> data_vector; //The main vector: All the data will be stored in here from reading and writing
    bool program_start{true};
    while(program_start){ //While loop starts the program
        menu_one();
        int second_choice{get_choice(1,9)};
        if(second_choice == 1){ //Adds Galaxy to main vector
            add_galaxy(data_vector);
            }
        else if(second_choice == 2){//Add singular Object to a galaxy
            std::cout << "Enter which Galaxy you would like to add objects to: " << std::endl;
            print_names<Galaxy>(data_vector);
            std::string galaxy_search;
            std::cin >> galaxy_search;
            while (std::cin.fail()==true || std::cin.peek() != '\n'){ //Validation
                        std::cout << "Please input a valid input (eg. no spaces)" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> galaxy_search;
                     }
            add_to_galaxy(data_vector, galaxy_search);
            }
        else if(second_choice == 3){//Search Galaxy to get to SPECIFIC Galaxy Tab
            std::cout << "Please type in the Galaxy to search for:" << std::endl;
            print_names<Galaxy>(data_vector);
            std::string galaxy_search;
        
            std::cin >> galaxy_search; 
            while (std::cin.fail()==true || std::cin.peek() != '\n'){ //Validation
                        std::cout << "Please input a valid input (eg. no spaces)" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> galaxy_search;
                     }
            int galaxy_search_key{search<Galaxy>(data_vector, galaxy_search)};
            if(galaxy_search_key != -1){
            while(true){
                obj_menu(data_vector.at(galaxy_search_key)); //Fifth menu called 
                int third_choice(get_choice(1,6));
                if(third_choice == 1){ //Descening: STARS IN THE GALAXY OF THEIR CHOICE
                    sort_menu(data_vector.at(galaxy_search_key));
                    int ascend_choice{get_choice(1,6)};
                    while(true){
                        if(ascend_choice == 1){ //SORT BY MASS
                            std::vector<std::shared_ptr<SingularObjects>>& temp = data_vector.at(galaxy_search_key)->get_contents();
                            mass::sort_up<SingularObjects>(temp);
                            data_vector.at(galaxy_search_key)->set_contents(temp);
                            break;
                        }
                        else if(ascend_choice == 2){ //SORT BY NAME
                            std::vector<std::shared_ptr<SingularObjects>>& temp = data_vector.at(galaxy_search_key)->get_contents();
                            name::sort_up<SingularObjects>(temp);
                            data_vector.at(galaxy_search_key)->set_contents(temp);
                            break;
                        }
                        else if(ascend_choice == 3){ //SORT BY REDSHIFT
                            std::vector<std::shared_ptr<SingularObjects>>& temp = data_vector.at(galaxy_search_key)->get_contents();
                            redshift::sort_up(temp);
                            data_vector.at(galaxy_search_key)->set_contents(temp);
                            break;
                        }
                        else if(ascend_choice == 4){ //SORT BY OBJECT TYPE 
                            std::vector<std::shared_ptr<SingularObjects>>& temp = data_vector.at(galaxy_search_key)->get_contents();
                            object_type::sort_up(temp);
                            data_vector.at(galaxy_search_key)->set_contents(temp);
                            break;
                        }
                        else if(ascend_choice == 5){ //SORT BY RADIUS
                            std::vector<std::shared_ptr<SingularObjects>>& temp = data_vector.at(galaxy_search_key)->get_contents();
                            radius::sort_up(temp);
                            data_vector.at(galaxy_search_key)->set_contents(temp);
                            break;
                        }
                        else if(ascend_choice == 6){ //GO BACK
                            break;
                        }
                    }
                }
                else if(third_choice == 2){ //ASCENDING: STARS IN THE GALAXY OF THEIR CHOICE
                    sort_menu(data_vector.at(galaxy_search_key));
                    int descend_choice{get_choice(1,6)};
                    while(true){
                        if(descend_choice == 1){ //SORT BY MASS
                            std::vector<std::shared_ptr<SingularObjects>>& temp = data_vector.at(galaxy_search_key)->get_contents();
                            mass::sort_down<SingularObjects>(temp);
                            data_vector.at(galaxy_search_key)->set_contents(temp);
                            break;
                        }
                        else if(descend_choice == 2){ //SORT BY NAME
                            std::vector<std::shared_ptr<SingularObjects>>& temp = data_vector.at(galaxy_search_key)->get_contents();
                            name::sort_down<SingularObjects>(temp);
                            data_vector.at(galaxy_search_key)->set_contents(temp);
                            break;
                        }
                        else if(descend_choice == 3){ //SORT BY REDSHIFT
                            std::vector<std::shared_ptr<SingularObjects>>& temp = data_vector.at(galaxy_search_key)->get_contents();
                            redshift::sort_down(temp);
                            data_vector.at(galaxy_search_key)->set_contents(temp);
                            break;
                        }
                        else if(descend_choice == 4){ //SORT BY OBJECT TYPE 
                            std::vector<std::shared_ptr<SingularObjects>>& temp = data_vector.at(galaxy_search_key)->get_contents();
                            object_type::sort_down(temp);
                            data_vector.at(galaxy_search_key)->set_contents(temp);
                            break;
                        }
                        else if(descend_choice == 5){ //SORT BY RADIUS
                            std::vector<std::shared_ptr<SingularObjects>>& temp = data_vector.at(galaxy_search_key)->get_contents();
                            radius::sort_down(temp);
                            data_vector.at(galaxy_search_key)->set_contents(temp);
                            break;
                            
                        }
                        else if(descend_choice == 6){ //GO BACK
                            break;
                        }
                    }
                }
               
                else if(third_choice == 3){ //SEARCH STAR
                    std::cout << "Which Object are you looking for?" << std::endl;
                    print_names<SingularObjects>(data_vector.at(galaxy_search_key)->get_contents());
                    std::string star_search;
                    std::cin >> star_search;
                    while (std::cin.fail()==true || std::cin.peek() != '\n'){ //Validation
                        std::cout << "Please input a valid input (no spaces)" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> star_search;
                     }
                    int star_search_key{search<SingularObjects>(data_vector.at(galaxy_search_key)->get_contents(), star_search)}; //Search key used to direct to a singular object
                    if(star_search_key != -1){ 
                        data_vector.at(galaxy_search_key)->specific_object(star_search_key);
                    }
                    else{
                        std::cout << "Star doesn't exist!" << std::endl;
                    }
                    
                }
                else if(third_choice == 4){ // Delete Object
                    std::cout << "Which Object are you looking to delete?" << std::endl;
                    print_names<SingularObjects>(data_vector.at(galaxy_search_key)->get_contents());
                    std::string object_delete_search;
                    std::cin >> object_delete_search;
                    delete_object<SingularObjects>(data_vector.at(galaxy_search_key)->get_contents(), object_delete_search);


                }
                else if(third_choice == 5){ //Filter Function 
                    std::cout <<"What would you like to filter? STAR, PLANET or NEUTRONSTAR" << std::endl;
                    std::string filter;
                    std::cin >> filter;
                    string_formatter(filter);
                    if (filter == "STAR"){
                        std::vector<std::shared_ptr<SingularObjects>> filter_vector{data_vector.at(galaxy_search_key)->filter_by_type("STAR")};
                        for(auto it = filter_vector.begin(); it != filter_vector.end(); ++it){
                            (*it)->celestial_body_info();}
                    }
                    else if(filter == "PLANET"){
                        std::vector<std::shared_ptr<SingularObjects>> filter_vector{data_vector.at(galaxy_search_key)->filter_by_type("PLANET")};
                        for(auto it = filter_vector.begin(); it != filter_vector.end(); ++it){
                            (*it)->celestial_body_info();}
                    }
                    else if(filter == "NEUTRONSTAR"){
                        std::vector<std::shared_ptr<SingularObjects>> filter_vector{data_vector.at(galaxy_search_key)->filter_by_type("NEUTRONSTAR")};
                        for(auto it = filter_vector.begin(); it != filter_vector.end(); ++it){
                            (*it)->celestial_body_info();}
                        }
                    else{ 
                        std::cout << "Category not found!" << std::endl;
                    }
                }
                else if(third_choice == 6){
                    break;
                }
                
            }
        }
        else if(galaxy_search_key == -1){
            std::cout<< "Galaxy not found" << std::endl;
        }
            
        }

        else if(second_choice == 4){ // Filter and Sort Galaxy
            filter_menu();
            int galaxy_sort_choice{get_choice(1,7)};
            if(galaxy_sort_choice == 1){
                name::sort_up<Galaxy>(data_vector);
            }
            else if(galaxy_sort_choice == 2){
                name::sort_down<Galaxy>(data_vector);

            }
            else if(galaxy_sort_choice == 3){
                mass::sort_up<Galaxy>(data_vector);
            }
            else if(galaxy_sort_choice == 4){
                mass::sort_down<Galaxy>(data_vector);
            }
            else if(galaxy_sort_choice == 5){
                size_galaxy::sort_up(data_vector);
            }
            else if(galaxy_sort_choice == 6){
                size_galaxy::sort_down(data_vector);
            }
            else if(galaxy_sort_choice == 7){
                
            }
            
        }

        else if(second_choice == 5){ //PRINT ALL GALAXIES
            for(auto it = data_vector.begin(); it != data_vector.end(); ++it){
            (*it)->celestial_body_info();
            }
        }
        else if(second_choice == 6){ //ADD FILE
            std::cout << "Standard CSV file is test.csv" << std::endl;
            read_data(data_vector);
        }
        else if(second_choice==8){ // SAVE FILE
            create(data_vector);
        }
        else if(second_choice==7){
            std::string delete_search;
            std::cout << "Which Galaxy would you like to delete?" << std::endl;
            std::cin >> delete_search;
            while (std::cin.fail()==true || std::cin.peek() != '\n'){ //Validation
                        std::cout << "Please input a valid input (no spaces)" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> delete_search;
                     }
            delete_object<Galaxy>(data_vector, delete_search);
        }
        else if(second_choice == 9){ //END PROGRAMM
            break;
        }
    }     
    
    return 0;
}
