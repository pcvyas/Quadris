#ifndef _GAME_H_
#define _GAME_H_
#include "board.h"
#include <fstream>
#include <iostream>
#include <string>

class Game {
	public:
		Board b;
		void levelup();
		void leveldown();
		void restart();
		bool loss();
		void changeFileName(std::string fname);
		void seed(int num);
	        friend std::ostream &operator<<(std::ostream &out, Game &g);
};

#endif
