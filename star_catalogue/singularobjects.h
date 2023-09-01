#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "celestialbodies.h"



//FORWARD DECLERATION OF CLASS
class Galaxy;


/*
Singular bodies class:

inherits from celestialbodies class

- Qi Nohr Chen
*/

class SingularObjects : public CelestialBodies 
{
protected:
    std::string name;
    double mass;
    double redshift;
    double radius;
    
public:
    SingularObjects() = default;
    SingularObjects(std::string obj_name, double obj_mass, double obj_redshift, double obj_radius)
        : name{obj_name}, mass{obj_mass}, redshift{obj_redshift}, radius{obj_radius}{};
    virtual ~SingularObjects(){};


    virtual std::string get_object_type() = 0;

    double get_volume() const;

    double get_density() const;

    std::string get_name() override;

    double get_redshift() const;

    double get_mass() const;

    double get_radius() const;
  
};
