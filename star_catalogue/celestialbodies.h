
#pragma once
#include <iostream>

const double PI = atan(1)*4;
//ABSTRACT INTERFACE CLASS
class CelestialBodies 
//Abstract class for ObservedObjects
{
protected:
    std::string name;
public:
    virtual ~CelestialBodies(){} //Virtual destructor
    virtual void celestial_body_info() = 0;
    virtual std::string get_name() = 0;
};
