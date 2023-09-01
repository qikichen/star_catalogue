#include "neutronstars.h"

void NeutronStars::celestial_body_info() 
//Prints of the information for the star catalogue
    {
        std::cout << "The Neutron Star: " << name  << std::endl;
        std::cout << "Mass: " << mass << std::endl;
        std::cout << "Redshift: " << redshift << std::endl;
        std::cout << "Radius: " << radius << std::endl;
        std::cout << "Density: " << get_density()<< std::endl;
        std::cout << "Contains " << number_of_neutrons() <<  " Neutrons" << std::endl;
    };

double NeutronStars::number_of_neutrons()
//Calculation required for the number of neutrons
    {
        return mass/(1.674*pow(10,-27));
    };
    
std::string NeutronStars::get_object_type()
//Returns the object type for filtering
    {
        return "NEUTRONSTAR";
    };