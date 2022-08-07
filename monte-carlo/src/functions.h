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
#include <random>

using namespace std;


class Car{
	int num_pos;
        int num_steps;
        int num_cars;
        float probability;
        double seed;
        float *velocity;
        float *position;
        public:
		Car(int numPos, int numSteps, int numCars, float Probability, double Seed);
		void start(int seed);
		void run();
	private:
		float increase_velocity(float velocity);
		float no_accidents(float velocity, float distance);
		float random_decrease(float velocity, float probability);
		float circular_move(float velocity, float position);

};


#endif
