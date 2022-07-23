/// @file functions.h
/// @author Tina Eghdam Zamiri
/// @date Julu 01, 2022
/// @brief Module for writing the functions for monte carlo molecular motion.


#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void initialization();
int generate_position();
double system_energy_initialization(int *molecules_x, int *molecules_y,int count);
double total_energy(int *molecules_x, int *molecules_y, int count, double *energy);


