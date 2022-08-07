/// @file functions.cpp
/// @author Tina Eghdam Zamiri
/// @date Jun 30, 2022
/// @brief Module for writing the functions for the 1D Nagel-Schreckenberg traffic flow.



#include "functions.h"
	


Car::Car(int numPos, int numSteps, int numCars, float Probability, double Seed){
	num_pos = numPos;
	num_steps = numSteps;
	num_cars = numCars;
	probability = Probability;
	seed = Seed;	
	velocity = new float[numCars];
	position = new float[numPos];
}

void Car::start(int seed){
        std::normal_distribution<double> distribution(5.0,2.0);
	std::mt19937 engine;
	engine.seed(seed);
	for( int i = 0; i < num_cars; i++ ){
		velocity[i] = 1;
		std::cout << i << " " <<  velocity[i] << endl;
	}
	for ( int i = 0; i < num_pos; i++ ){
		position[i] = i;
		std::cout << "at position: " << i << " " <<  velocity[i] << endl;
	}
}

void Car::run(){
	start(seed);
	cout << "before \n";
	for( int i = 0; i < num_steps; i++ ){
		cout << "ff\n"; 
		for ( int j = 0; j < num_cars; j++ ){
			velocity[j] = increase_velocity(velocity[j]);
			float distance = (j != (num_cars - 1)) ? position[j+1] - position[j] : 0; 
			velocity[j] = no_accidents(velocity[j], distance);
			velocity[j] = random_decrease(velocity[j], probability);
			position[j] = circular_move(velocity[j], position[j]);
			cout << "Car number: " << j << " at position: " << position[j] << " with speed: " << velocity[j] << endl; 
		}
	}
}

//~Car(){
//	delete[] velocity;
//	delete[] position;
//}

float Car::random_decrease(float velocity, float probability){
        std::normal_distribution<double> distribution(5.0,2.0);
	std::mt19937 engine;
        engine.seed(seed);
	if (velocity <= 0){
		 return velocity;
	}
	// generate a random number to move
        double temp = distribution(engine);
        // rejection scheme
	std::cout << temp;
        return (temp >= probability) ? velocity - 1 : velocity;
}

float Car::increase_velocity(float velocity){
	cout << velocity;
	 return std::min(velocity + 1, float(10));
}

float Car::no_accidents(float velocity, float distance){
	 return std::min(velocity, distance - 1);
}

float Car::circular_move(float velocity, float position){
	return std::min(velocity + position, position);
}





