#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include "celestialbodies.h"
#include "singularobjects.h"

/*
Galaxy Class:

inherits from celstialbodies

- Qi Nohr Chen
*/

class Galaxy: public CelestialBodies
{
protected: 

    std::string name;
    std::vector<std::shared_ptr<SingularObjects>> contents; //Use of shared pointer to store singularobjects
public:
    Galaxy() = default;
    Galaxy(std::string n) 
    : name{n}{};
    ~Galaxy(){};

    bool operator==(Galaxy &other) const;

    std::string get_name() override;

    void add_singular_objects(std::shared_ptr<SingularObjects> content);

    void celestial_body_info();

    double get_mass();
    
    std::vector<std::shared_ptr<SingularObjects>>& get_contents();
    
    const std::vector<std::shared_ptr<SingularObjects>>& get_const_contents() const;
    
    void set_contents(std::vector<std::shared_ptr<SingularObjects>> new_content);

    void specific_object(int key);
    
    std::vector<std::shared_ptr<SingularObjects>> filter_by_type(std::string type);

};