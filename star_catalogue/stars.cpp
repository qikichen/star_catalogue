#include "stars.h"

void Stars::celestial_body_info() 
    {
        std::cout << "The Star: " << name << " of type " << type << std::endl;
        std::cout << "Mass: " << mass << std::endl;
        std::cout << "Redshift: " << redshift << std::endl;
    };

std::string Stars::get_object_type() 
    {
        return "STAR";
    };

std::string Stars::get_star_type() const
    {
        return type;
    }