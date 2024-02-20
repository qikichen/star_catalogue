#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "celestialbodies.h"
#include "galaxy.h"
#include "singularobjects.h"
#include "stars.h"


/*
Planets class:

Inherits from Singular Objects

- Qi Nohr Chen
*/

class Planets: public SingularObjects
{
protected:
    std::string orbital_star;
public:
    Planets(std::string planet_name, double m, double rs, double r, std::string os) 
    : SingularObjects(planet_name, m, rs, r), orbital_star(os) {};
    ~Planets() {};

    void celestial_body_info() override;

    std::string get_object_type();

    std::string get_orbiting_star();
};