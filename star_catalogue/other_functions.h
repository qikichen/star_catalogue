#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>

/*

Template functions used as there are two classes. Singular bodies and galaxies. File was called other_functions.h because they did not have a
general category of functionality which I could class them in.

- Qi Nohr Chen

*/

template <typename T> //Simple search algorithm for galaxies and singular bodies using a template function
int search(const std::vector<std::shared_ptr<T>>& data_vector, const std::string& search_key) { //Intended to accept multiple data types 
    //Lambda function finds another iterator comparing the pointer to the search key input above
    auto it = std::find_if(data_vector.begin(), data_vector.end(), [&](const std::shared_ptr<T>& ptr){return ptr->get_name() == search_key;});
    if (it != data_vector.end()) {
        return std::distance(data_vector.begin(), it);
    }
    else {
        std::cout << "Object not found" << std::endl;
        return -1; // not found
    }
};

template <typename T> //Deletes an object from a vector
void delete_object(std::vector<std::shared_ptr<T>>& data_vector, const std::string& delete_key) {
    int deletion_index = search(data_vector, delete_key);
    if (deletion_index != -1) {
        data_vector.erase(data_vector.begin() + deletion_index);
        std::cout << "Object deleted successfully" << std::endl;
    }
    else{
        std::cout << "Object wasn't found or doesn't exist!" << std::endl;
    }
}

template <typename T> //Print the names of the constituents vector to make the user interface easier
void print_names(std::vector<std::shared_ptr<T>>& data_vector)
{
    std::cout << "Your options are: " << std::endl;
    for(auto it = data_vector.begin(); it != data_vector.end(); ++it){
        std::cout << (*it)->get_name() << std::endl;
        }
}