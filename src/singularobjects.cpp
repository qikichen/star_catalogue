#include "singularobjects.h"

double SingularObjects::get_volume() const
//calculates the volume
    {
        double volume = (4.0/3.0)*PI*pow(radius,3);
        return volume;
    };

double SingularObjects::get_density() const
//Calculates the density
    {
        double density = mass/get_volume();
        return density;
    };

std::string SingularObjects::get_name() 
//Getter function : Name
    {
        return name;
    };

double SingularObjects::get_redshift() const
//Getter function : Red Shift
    {
        return redshift;
    };

double SingularObjects::get_mass() const
//Getter function : Mass
    {
        return mass;
    }

double SingularObjects::get_radius() const
//Getter function : radius
    {
        return radius;
    }