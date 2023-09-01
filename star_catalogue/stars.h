#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "celestialbodies.h"
#include "galaxy.h"
#include "singularobjects.h"



class Stars: public SingularObjects
//Class for stars inheriting from SingularObjects
{
protected:
    std::string type; //THE OBAFGKM classes for a star
public:
    Stars() = default;
    Stars(std::string star_name, double m, double rs, double r, std::string star_type)
    : SingularObjects(star_name, m, rs, r), type{star_type}{};
    ~Stars(){};

    void celestial_body_info() override;

    std::string get_object_type() override;

    std::string get_star_type() const;

};
