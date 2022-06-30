/// @file functions.cpp
/// @author Tina Eghdam Zamiri
/// @date Jun 30, 2022
/// @brief Module for writing the functions for the 1D Nagel-Schreckenberg traffic flow.



#include "functions.cpp"


float increase_velocity(float velocity);
float no_accidents(float velocity, float distance);
float random_decrease(float velocity);
float circular_move(float velocity);


float increase_velocity(float velocity){
	return std:min(velocity + 1, MAX);	
}

float no_accidents(float velocity, float distance){
	

}