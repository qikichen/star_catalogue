#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include "celestialbodies.h"
#include "singularobjects.h"
#include "stars.h" 
#include "planets.h"
#include "neutronstars.h"
#include "galaxy.h"

/*

Functions that make up the interface of the code declared here

- Qi Nohr Chen

*/

void menu_one();

void filter_menu();

void obj_menu(std::shared_ptr<Galaxy> &gal);

int get_choice(int i, int j);

void sort_menu(std::shared_ptr<Galaxy> &gal);
