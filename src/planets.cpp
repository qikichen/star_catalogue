#include "planets.h"

void Planets::celestial_body_info() 
//Function prints out all the necessary informaiton of the planet
    {
        std::cout << "The Planet: " << name << std::endl;
        std::cout << "Mass: " << mass << std::endl;
        std::cout << "Redshift: " << redshift << std::endl;
        std::cout << "Orbiting around: " << orbital_star << std::endl;
    };

std::string Planets::get_object_type()
//Returns object type for filtering
    {
        return "PLANET";
    };

std::string Planets::get_orbiting_star()
//Getter Function to print orbital star
    {
        return orbital_star;
    }