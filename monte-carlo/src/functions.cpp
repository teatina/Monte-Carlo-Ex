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
	float *velocity;
	float *position;
	public: 
		Car(int numPos, int numSteps, int numCars, float Probability, double Seed): uniform(0,1) {
			num_pos = numPos;
			num_steps = numSteps;
			num_cars = numCars;
			probability = Probability;
			seed = Seed;	
			velocity = new float[numCars];
			positions = new float[numPos];
		}

		void start(int seed){
			engine.seed(seed)
		}

		void run(){
			for( int i = 0; i < num_steps; i++ ){
				for ( int j = 0; j < num_cars; j++ ){
					velocity[j] = increase_velocity(velocity[j]);
					float distance = j != (num_cars - 1) ? podition[j+1] - position[j] : 0; 
					velocity[j] = no_accidents(velocity[j], distance);
					velocity[j] = random_decrease(velocity[j], probability);
					position[j] = circular_move(velocity[j], position[j]);
					cout << "Car number: " << j << " at position: " << position[j] << " with speed: " << velocity[j] << endl; 
				}
			}
		}
		~Car(){
			delete[] velocity;
			delete[] position;
		}
	private:
	  std::uniform_int_distribution<int> uniform;
	  std::mt19937 engine;
	  float random_decrease(float velocity, float probability){
          	if (velocity =< 0) return velocity;
                // generate a random number to move
                int temp = uniform(engine);
                // rejection scheme
                return (temp >= probability) ? velocity - 1 : velocity;
	   }
           float increase_velocity(float velocity){
		 return std:min(velocity + 1, MAX);
           }

	  float no_accidents(float velocity, float distance){
		 return std::min(velocity, distance - 1);
	  }

          float circular_move(float velocity, float position){
          	return std::min(velocity + position, position);
	  }



}





