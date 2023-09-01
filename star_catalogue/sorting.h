
#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include "celestialbodies.h"
#include "singularobjects.h"
#include "stars.h"
#include "planets.h"
#include "neutronstars.h"
#include "galaxy.h"
#include "data.h"

/*

Namespace functions for sorting. Use of namespace is justified as they all perform the same task, (sorting up and down) which means 
I would like to keep the name the same, hence it was chosen to use namespaces
Functions sort vectors up and down (ascending and decending)

- Qi Nohr Chen

*/

namespace name //namespace name sorts the name data member
{
    template<typename object_container> //template function sorting descendingly according to the name
    void sort_up(std::vector<std::shared_ptr<object_container>>& data_vector) {
        auto compare = [&](const auto& a, const auto& b) { return a->get_name() < b->get_name(); }; //lambda function for comparison
        std::sort(data_vector.begin(), data_vector.end(), compare);
    };

    template<typename object_container>//template function sorting ascendingly according to the name
    void sort_down(std::vector<std::shared_ptr<object_container>>& data_vector) {
        auto compare = [&](const auto& a, const auto& b) { return a->get_name() > b->get_name(); }; //lambda function for comparison
        std::sort(data_vector.begin(), data_vector.end(), compare);
    };
}

namespace mass
{
    template<typename object_container>
    void sort_up(std::vector<std::shared_ptr<object_container>>& data_vector) {
        auto compare = [&](const auto& a, const auto& b) { return a->get_mass() < b->get_mass(); };
        std::sort(data_vector.begin(), data_vector.end(), compare);
    };

    template<typename object_container>
    void sort_down(std::vector<std::shared_ptr<object_container>>& data_vector) {
        auto compare = [&](const auto& a, const auto& b) { return a->get_mass() > b->get_mass(); };
        std::sort(data_vector.begin(), data_vector.end(), compare);
    };
}

namespace size_galaxy
{
    void sort_up(std::vector<std::shared_ptr<Galaxy>>& data_vector) {
        std::sort(data_vector.begin(), data_vector.end(), [](const std::shared_ptr<Galaxy>& x, const std::shared_ptr<Galaxy>& y) {
            return x->get_const_contents().size() < y->get_const_contents().size();});
    }

    void sort_down(std::vector<std::shared_ptr<Galaxy>>& data_vector) {
        std::sort(data_vector.begin(), data_vector.end(), [](const std::shared_ptr<Galaxy>& x, const std::shared_ptr<Galaxy>& y) {
            return x->get_const_contents().size() > y->get_const_contents().size();});
    }
}


namespace redshift
{
    template<typename object_container>
    void sort_up(std::vector<std::shared_ptr<object_container>>& data_vector) {
        auto compare = [&](const auto& a, const auto& b) { return a->get_redshift() < b->get_redshift(); };
        std::sort(data_vector.begin(), data_vector.end(), compare);
    };

    template<typename object_container>
    void sort_down(std::vector<std::shared_ptr<object_container>>& data_vector) {
        auto compare = [&](const auto& a, const auto& b) { return a->get_redshift() > b->get_redshift(); };
        std::sort(data_vector.begin(), data_vector.end(), compare);
    };
}

namespace radius
{
    void sort_up(std::vector<std::shared_ptr<SingularObjects>>& data_vector) {
        auto compare = [&](const auto& a, const auto& b) { return a->get_radius() < b->get_radius(); };
        std::sort(data_vector.begin(), data_vector.end(), compare);
    };

    void sort_down(std::vector<std::shared_ptr<SingularObjects>>& data_vector) {
        auto compare = [&](const auto& a, const auto& b) { return a->get_radius() > b->get_radius(); };
        std::sort(data_vector.begin(), data_vector.end(), compare);
    };
}

namespace object_type
{
    void sort_up(std::vector<std::shared_ptr<SingularObjects>>& data_vector) {
        auto compare = [&](const auto& a, const auto& b) { return a->get_object_type() < b->get_object_type(); };
        std::sort(data_vector.begin(), data_vector.end(), compare);
    };

    void sort_down(std::vector<std::shared_ptr<SingularObjects>>& data_vector) {
        auto compare = [&](const auto& a, const auto& b) { return a->get_object_type() > b->get_object_type(); };
        std::sort(data_vector.begin(), data_vector.end(), compare);
    };

}

