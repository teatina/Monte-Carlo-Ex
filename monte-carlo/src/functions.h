/// @file functions.h
/// @author Tina Eghdam Zamiri
/// @date Jun 30, 2022
/// @brief Module for writing the functions for the 1D Nagel-Schreckenberg traffic flow.


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;


#define MAX 5

float increase_velocity(float velocity);
float no_accidents(float velocity, float distance);
float random_decrease(float velocity);
float circular_move(float velocity);





#endif
