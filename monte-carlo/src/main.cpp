/// @file main.cpp
/// @author Tina Eghdam Zamiri
/// @date Jun 30, 2022
/// @brief Module for executing the 1D Nagel-Schreckenberg traffic flow.


#include "functions.cpp"


int main(){
	//Car(int numPos, int numSteps, int numCars, float Probability, double Seed)	
	Car car(3, 5, 3, 0.5, 555);	

	car.run();




}
