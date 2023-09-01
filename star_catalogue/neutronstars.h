#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "celestialbodies.h"
#include "galaxy.h"
#include "singularobjects.h"
#include "stars.h"

/*

Neutron Star Class:

Inherits functions from SingularObjects. 
Member functions declared in this file.

- Qi Nohr Chen

*/

class NeutronStars: public SingularObjects
{
protected:
public:
    NeutronStars() = default;
    NeutronStars(std::string star_name, double m, double rs, double r)
    : SingularObjects(star_name, m, rs, r) {};        
    ~NeutronStars(){};

    void celestial_body_info() override;
    
    double number_of_neutrons();
    
    std::string get_object_type();

};