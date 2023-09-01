#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>
#include<iomanip>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include "celestialbodies.h"
#include "singularobjects.h"
#include "stars.h" 
#include "planets.h"
#include "neutronstars.h"
#include "galaxy.h"
#include "other_functions.h"

/*
Functions are all related to creating data, saving data and reading data.

- Qi Nohr Chen
*/

void string_formatter(std::string &in);

std::string star_type_validator(std::string& in);

void create(std::vector<std::shared_ptr<Galaxy>>& data_vector);

std::string ask_filename();

void read_data(std::vector<std::shared_ptr<Galaxy>> &data_vector);

//FILE WRITING
void add_galaxy(std::vector<std::shared_ptr<Galaxy>> &data_vector);

void add_to_galaxy(std::vector<std::shared_ptr<Galaxy>> &data_vector, std::string galaxy_name);

void save_file(std::vector<std::shared_ptr<Galaxy>> &data_vector);
