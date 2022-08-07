/// @file main.cpp
/// @author Tina Eghdam Zamiri
/// @date July 23, 2022
/// @brief Module for executing the functions for monte carlo molecular motion.


#include "functions.h"




int main(){
	int molecule_count = 5;
	int molecule_x[molecule_count], molecule_y[molecule_count];
	float temperature = 1.0;
	int num_steps = 5;
	double energy[num_steps];

	initialization();
	for ( int i = 0; i < molecule_count; i++ ){
		molecule_x[i] = generate_position();
		molecule_y[i] = generate_position();

	}
	
	energy[0] = system_energy_initialization(molecule_x, molecule_y, molecule_count);


	for ( int j = 1; j < num_steps; j++){
		energy[j] = total_energy(molecule_x, molecule_y, molecule_count, energy[j-1], temperature);
		cout << "Energy of the system at step " << j << " is: " << energy[j] << endl;
	}
	

	return 0;
}


