#include <iostream>
#include <cmath>
#include <vector>

//ABSTRACT INTERFACE CLASS
class CelestialBodies 
//Abstract class for ObservedObjects
{
    protected:
        string name;
    public:
        virtual ~CelestialBodies(){} //Virtual destructor
        virtual void celestial_body_info() = 0;
};

//CLASS FOR BIGGER OBJECTS SUCH AS CLUSTERS

class Clusters: public CelestialBodies
{
    protected:
         std::vector<SingularObjects*> cluster_contents;
    public:
        virtual double cluster_mass() = 0;
        virtual void add_objects() = 0; //THIS FUNCTION WILL ADD OBJECTS
}

class Galaxy: public Clusters
{
    protected: 
        string id;
        //INCLUDE SIZE AND WHAT NOT
    public:
        Galaxy() = default;
        Galaxy(string i) : id{i};
        ~Galaxy(){};
}


//CLASSES FOR SINGULAR OBJECTS IN SPACE
class SingularObjects: CelestialBodies
{
    protected:
    public:
        virtual double body_mass_calculation() = 0;
}

class Stars: public SingularObjects
//Class for stars inheriting from Celestial Bodies
{
    protected:
        char type; //THE OBAFGKM classes for a star
    public:
        Stars() = default;
        Stars(string star_name, char star_type) : name{star_name}, type{star_type}{};
        ~Stars(){};
}

class NeutronStars: public Stars
{
    protected:
    public:
        NeutronStars() = default;
        //PARAMETRIZED CONSTRUCTOR
        ~NeutronStars(){};
}