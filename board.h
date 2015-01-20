#ifndef _BOARD_H_
#define _BOARD_H_

#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "window.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

class Board {
	public:
		bool graphics, help;
		int max_row, max_col;
		std::string filename;
		std::ifstream open_file;
		char gameBoard[15][10];
		int level, score, hiscore, lifeline;
		char next_block;
		Xwindow w;
		Block *current_block;
		
		void left();
		void right();
		void down();
		void drop();
		void CCW();
		void CW();
		
		void linesCompleted();
		void clearLines(int row); // clears the line row
		
		void next();
		void blockmaker(char block_name);
		
		// bool loss();
		bool conflict(int row, int col);
		
		// void addScore(int line);
		void clearBoard();
		
		Board();
		~Board();
		

		void seed(int n);
		friend std::ostream &operator<<(std::ostream &out, std::string &s);
		friend std::ostream &operator<<(std::ostream &out, Board &b);
		
};

#endif
