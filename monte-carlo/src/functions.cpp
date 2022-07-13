/// @file functions.cpp
/// @author Tina Eghdam Zamiri
/// @date Jun 30, 2022
/// @brief Module for writing the functions for the 1D Nagel-Schreckenberg traffic flow.



#include "functions.cpp"
	


class Car{
	public: 
		Car(): uniform(0,1){}
		void start(int seed){
			engine.seed(seed)
		}

		int random_decrease(float velocity, float probability){
			int temp =  
		
	
		}	
	

	private:
	  std::uniform_int_distribution<int> uniform;
	  std::mt19937 engine;
}




float increase_velocity(float velocity){
	return std:min(velocity + 1, MAX);	
}

float no_accidents(float velocity, float distance){
	return std::min(velocity, distance - 1);	

}


float random_decrease(float velocity, float probability){

}

float circular_move(float velocity){

}





