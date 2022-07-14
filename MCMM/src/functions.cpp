/// @file functions.cpp
/// @author Tina Eghdam Zamiri
/// @date July 14, 2022
/// @brief Module for writing the functions for monte carlo molecular motion.



#include <functions.h>

Class Molecule(){
	public:
		Molecule(): uniform(0, 1){}
		void start(int seed){
			engine.seed(seed);
		}

		int generate_position(){
			return uniform(engine);
		}

	private:
	  std::uniform_int_distribution<int> uniform;
	  std:mt19937 engine;







}




