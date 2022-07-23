/// @file functions.h
/// @author Tina Eghdam Zamiri
/// @date Julu 01, 2022
/// @brief Module for writing the functions for monte carlo molecular motion.


#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;


/// @brief Function to initialize the mersenne twister engine.
void initialization();


/// @brief Function to random generate a number for x or y coordinate of a molecule using the mersenne twister engine.
/// This function returns a random integer.
int generate_position();


/// @brief Function to calculate the energy of the system at the beginning.
/// This function return the initial total energy of the system
/// @param molecules_x the x position of the molecules
/// @param molecules_y the y position of the molecules
/// @param count number of molecules
double system_energy_initialization(int *molecules_x, int *molecules_y,int count);


/// @brief Function to calculate the energy of the system at every step.
/// This function return the total energy of the system at a certain step.
/// @param molecules_x the x position of the molecules
/// @param molecules_y the y position of the molecules
/// @param count number of molecules
/// @param energy the energy of the system at the previous step.
/// @param temperature the temperature of the system
double total_energy(int *molecules_x, int *molecules_y, int count, double energy, float temperature);


#endif
