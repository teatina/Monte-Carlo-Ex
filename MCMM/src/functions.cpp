/// @file functions.cpp
/// @author Tina Eghdam Zamiri
/// @date July 14, 2022
/// @brief Module for writing the functions for monte carlo molecular motion.



#include "functions.h"


void initialization(int seed){
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> uniform(1, 6);
}

int generate_position(){
	//std::uniform_int_distribution<int> uniform;
	return uniform(engine());
}

double system_energy_initialization(int *molecules_x, int *molecules_y, int count){
	double sigma, epsilon;
        sigma = 120;
        epsilon = 34e-11 ;
        double sum = 0;
        for(int i = 0; i < count; i++){
		for (int j= i; j < count; j++){
                	double distance = sqrt( pow ((molecules_x[i] - molecules_x[j]), 2) + pow( (molecules_y[i] - molecules_y[j]), 2) );
                	sum += 4 * epsilon * ( pow(distance, 12 ) - pow(distance, 6) );
		}
	}
	return sum;
}

double total_energy(int *molecules_x, int *molecules_y, int count, double energy, int temperature){
	double sigma, epsilon;	
	sigma = 120;
	epsilon = 34e-11 ;
	double tot_sum = 0;
	double sum_rand_pos, molecule_sum;
	double new_energy[count]; 
	for(int i = 0; i < count; i++){
		sum_rand_pos = 0;
		int new_x = generate_position();
		int new_y = generate_position();
                for (int j= i; j < count; j++){
			molecule_sum = 0;
                        double distance = sqrt( pow ((molecules_x[i] - molecules_x[j]), 2) + pow( (molecules_y[i] - molecules_y[j]), 2) );
                        molecule_sum += 4 * epsilon * ( pow(distance, 12 ) - pow(distance, 6) );
                	double distance_rand = sqrt( pow( (new_x - molecules_x[j]), 2) + pow( (new_y - molecules_y[j]), 2) );
                        sum_rand_pos += 4 * epsilon * ( pow(distance_rand, 12 ) - pow(distance_rand, 6) );
			if ( sum_rand_pos < molecule_sum || sum_rand_pos < exp( (sum_rand_pos - molecule_sum )/ temperature ) ){
				molecules_x[i] = new_x;
				molecules_y[i] = new_y;
				tot_sum += sum_rand_pos;
		
			}
			else {
				tot_sum += molecule_sum;
			}
		}
        }

	return tot_sum;

}






