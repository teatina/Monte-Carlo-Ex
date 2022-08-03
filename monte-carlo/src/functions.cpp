/// @file functions.cpp
/// @author Tina Eghdam Zamiri
/// @date Jun 30, 2022
/// @brief Module for writing the functions for the 1D Nagel-Schreckenberg traffic flow.



#include "functions.cpp"
	


class Car{
	int num_pos;
	int num_steps;
	int num_cars;
	float probability;
	double seed;
	public: 
		Car(int numPos, int numSteps, int numCars, float Probability, double Seed): uniform(0,1), {
			num_pos = numPos;
			num_steps = numSteps;
			num_cars = numCars;
			probability = Probability;
			seed = Seed;	
		}

		void start(int seed){
			engine.seed(seed)
		}

		int random_decrease(float velocity, float probability){
			if (velocity < 0) return velocity;
			// generate a random number to move
			int temp = uniform(engine);
			// rejection scheme
			while (temp >= probability){
				temp = uniform(engine);
			}
			velocity -=1;
			return velocity;
		}	
		float increase_velocity(float velocity){
        		return std:min(velocity + 1, MAX);
		}		

		float no_accidents(float velocity, float distance){
       			 return std::min(velocity, distance - 1);

		}	

		float circular_move(float velocity){

		}	

	private:
	  std::uniform_int_distribution<int> uniform;
	  std::mt19937 engine;
}





