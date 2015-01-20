#include "board.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// decides on the colour given to each block
int decideColour(char block_type) {
	if (block_type == 'I') { return 8; } //orange
	else if (block_type == 'J') { return 2; } // red 
	else if (block_type == 'L') { return 5; } // cyan
	else if (block_type == 'O') { return 9; } // brown 
	else if (block_type == 'S') { return 3; } // green
	else if (block_type == 'Z') { return 6; } // yellow
	else if (block_type == 'T') { return 7; } // magenta
	else { return 1; }
}	

void Board::left() { // check horizontal changes
	int col_block = current_block->getCol();
	int row_block = current_block->getRow();
	// checks if there is a conflict to the left
	bool conflict_val = !conflict(row_block, col_block - 1);
	if (col_block > 0 && conflict_val) { 
		current_block->shiftLeft(); 
	}
}

void Board::right() { // check horizontal changes
	int col_block = current_block->getCol();
	int row_block = current_block->getRow();
	// checks if there is a conflict to the right
	bool conflict_val = !conflict(row_block, col_block + 1);
	if (col_block < max_col && conflict_val) { 
		current_block->shiftRight(); 
	}
}
void Board::down() {    // check vertical changes
	int col_block = current_block->getCol();
	int row_block = current_block->getRow();
	// chceks if there is a conflict below
	bool conflict_val = !conflict(row_block + 1, col_block);
	if (row_block < max_row && conflict_val) { 
		current_block->shiftDown(); 
	}
}


void Board::drop() {
	// keep going down until a conflict is reached
	while (!conflict(current_block->getRow(),current_block->getCol())){
		current_block->shiftDown();
	}
	// we tested drop and the block went 1 row pass the border, so we
	// move it back up one row
	if (current_block->row > 0) {
		current_block->row--;
	}
	
	// this sets the board's coortinates to the character of the block
	for (int i = 0; i < 4; i++){ 
		gameBoard[current_block->getRow() + current_block->block_coord[i][1]][current_block->getCol() + current_block->block_coord[i][0]] = current_block->getBlockName();
        }
	
	blockmaker(next_block); // get next block
	next(); // determine next block 
}

void Board::CCW() {
	// rotate only if there isnt a conflict
	if (!conflict(current_block->getRow(), current_block->getCol())) { 
		current_block->rotateCCW(); 
	}
}

void Board::CW() {
	// rotate if there is isnt a conflict
	if (!conflict(current_block->getRow(), current_block->getCol())) { 
		current_block->rotateCW(); 
	}
}


bool Board::conflict(int row, int col) {
	bool value = false;
	for (int i = 0; i < 4; i++) {
		// in 2d array col 1 was set up for row, 0 for col
		// goes through the block and sees if there is another block
		// or the column max is reached
		if (gameBoard[row + current_block->block_coord[i][1]][col + current_block->block_coord[i][0]] != ' ' || col + current_block->block_coord[i][0] >= max_col) {
			return !value;
		}
	}
	return value;
}


// next will be called to get the next block
// the next block will be determined by the level
void Board::next() {
	if (level == 0) {
		open_file >> next_block;
	}
	else if (level == 1) {
		// equal prob for all blocks
		int prob = rand()%71 + 1;
		// total of 72 numbers, 12 given to I, J, L, O, T (12/72)
		// 6 given to S, Z (6/72)
		if (prob >= 1 && prob <= 12) {
			next_block = 'I';
		}
		else if (prob >= 13 && prob <= 24) {
			next_block = 'J';
		}
                else if (prob >= 25 && prob <= 36) {
                        next_block = 'L';
                }
                else if (prob >= 37 && prob <= 48) {
                        next_block = 'O';
                }
                else if (prob >= 49 && prob <= 54) {
                        next_block = 'S';
                }
                else if (prob >= 55 && prob <= 60) {
                        next_block = 'Z';
                }
                else if (prob >= 61 && prob <= 72) {
                        next_block = 'T';
                }
	}
	else if (level == 2) {
                int prob = rand()%7;
                if (prob == 0) {
                        next_block = 'I';
                }
                else if (prob == 1) {
                        next_block = 'J';
                }
                else if (prob == 2) {
                        next_block = 'L';
                }
                else if (prob == 3) {
                        next_block = 'O';
                }
                else if (prob == 4) {
                        next_block = 'S';
                }
                else if (prob == 5) {
                        next_block = 'Z';
                }
                else if (prob == 6) {
                        next_block = 'T';
                }
	}
        else if (level == 3) {
                // equal prob for all blocks
                int prob = rand()%80 + 1;
		// 81 numbers
		// I, J, L, O, T have 9 numbers (9/81)
		// S, Z have 18 numbers (18/81)
                if (prob >= 1 && prob <= 9) {
                        next_block = 'I';
                }
                else if (prob >= 10 && prob <= 18) {
                        next_block = 'J';
                }
                else if (prob >= 19 && prob <= 27) {
                        next_block = 'L';
                }
                else if (prob >= 28 && prob <= 36) {
                        next_block = 'O';
                }
                else if (prob >= 37 && prob <= 54) {
                        next_block = 'S';
                }
                else if (prob >= 55 && prob <= 72) {
                        next_block = 'Z';
                }
                else if (prob >= 73 && prob <= 81) {
                        next_block = 'T';
                }
        }
        else if (level == 4) {
                int prob = rand()%1000 + 1;
                if (prob >= 1 && prob <= 50) {
                        next_block = 'I';
                }
                else if (prob >= 51 && prob <= 150) {
                        next_block = 'J';
                }
                else if (prob >= 151 && prob <= 250) {
                        next_block = 'L';
                }
                else if (prob >= 251 && prob <= 300) {
                        next_block = 'O';
                }
                else if (prob >= 301 && prob <= 600) {
                        next_block = 'S';
                }
                else if (prob >= 601 && prob <= 900) {
                        next_block = 'Z';
                }
                else if (prob >= 901 && prob <= 1000) {
                        next_block = 'T';
                }
        }
}

// random generator seed for the probabilities as indicated in assignment
void Board::seed(int n) {
	if (n < 0) {
		srand(time(NULL));
	}
	else {
		srand(n);
	}
}

// method to clear the given row
void Board::clearLines(int row) {
	// clears the given line
	for (int j = 0; j < max_col; j++) {
		// since I'm clearing the line, the above value
		gameBoard[row][j] = ' ';	// is in the line cleared
	}

	// moves the block down one row
	for (int i = row; i > 0; i--) {
		for (int j = 0; j < max_col; j++) {
			gameBoard[i][j] = gameBoard[i - 1][j];
		}
	}
	
}

// goes through the whole board to see which lines are complete
// if lines are complete, then call clearLines
void Board::linesCompleted() {
	bool completed;
	int l = 0;
	int prev_level = level;
	for (int i = 0; i < max_row; i++) {
		completed = true;
		for (int j = 0; j < max_col; j++) {
			if (gameBoard[i][j] == ' ') {  // there is a space not a full row of chars
				completed = false; 
			}
		      
		}
		// clears the line if that line has no ' '
		if (completed == true) {
			clearLines(i);
			l++;
			lifeline++;
		}
	}
	// changing the score to appropriate number
	if (l != 0) {
		score = score + (level + l) * (level + l);
		if (score >= hiscore) {
			hiscore = score;
		}
	}
	level = prev_level;
}

// blocks must be made on the heap, otherwise it won't work
void Board::blockmaker(char block_name) {
	if (block_name == 'I') { 
		current_block = new IBlock(); 
	}
	else if (block_name == 'J') { 
		current_block = new JBlock(); 
	}
	else if (block_name == 'L') { 
		current_block = new LBlock(); 
	}
	else if (block_name == 'O') { 
		current_block = new OBlock(); 
	}
	else if (block_name == 'S') { 
		current_block = new SBlock(); 
	}
	else if (block_name == 'Z') { 
		current_block = new ZBlock(); 
	}
	else if (block_name == 'T') { 
		current_block = new TBlock(); 
	}
}


// sets the board back to the original way
void Board::clearBoard() {
	for (int i = 0; i < max_row; i++) {
		for (int j = 0; j < max_col; j++) {
			gameBoard[i][j] = ' ';
		}
	}
	level = 0;
	score = 0;
	lifeline = 0;
	// hiscore is still persistent after a cleared board
}

Board::Board() {
	max_row = 15;
	max_col = 10;
	hiscore = 0;
	lifeline = 0;
	graphics = true;
	help = false;
	// default file to read blocks from
	filename = "sequence.txt";
	clearBoard();
}

Board::~Board() {
		for (int i = 0; i < max_row; i++) {
			delete [] gameBoard[i];
		}
		delete [] gameBoard;
		delete current_block;
		if (graphics == true) {
			delete &w; 
		}
}

ostream &operator<<(ostream &out, string &s) {  // operator<< overload to print the block in a special way
	if (s[0] == 'I') { out << "IIII" << endl; }
	else if (s[0] == 'J') { out << "J" << endl << "JJJ" << endl; }
	else if (s[0] == 'L') { out << "  L" << endl << "LLL" << endl; }
	else if (s[0] == 'O') { out << "OO" << endl << "OO" << endl; }
	else if (s[0] == 'S') { out << " SS" << endl << "SS" << endl; }
	else if (s[0] == 'Z') { out << "ZZ" << endl << " ZZ" << endl; }
	else if (s[0] == 'T') { out << "TTT" << endl << " T" << endl; }
	return out;
}

ostream &operator<<(ostream &out, Board &b) {
	int colour;
	char block_type, next_b;
	// makes the board black
	if (b.graphics == true) { 
		b.w.fillRectangle(0,80,500,575,0);
		b.w.fillRectangle(47,95,3,450,5);
		b.w.fillRectangle(350,95,3,450,5);
		b.w.fillRectangle(50,92,300,3,5);
		b.w.fillRectangle(50,545,300,3,5);
	}
	ostringstream num_string; // sstream to convert int to string
	
	num_string << b.level; // getting ready to convert int to string
	string s_level = "Level: " + num_string.str(); // appends the value to sentence
	out << "Level: " << num_string.str() << endl;
	num_string.str(""); // clears the previous string
	
	num_string << b.score;
	string s_score = "Score: " + num_string.str(); // appends the value to sentence
	out << "Score: " << num_string.str() << endl;
	num_string.str(""); // clears the previous string
	
	num_string << b.hiscore;
	string s_hiscore = "HiScore: " + num_string.str(); // appends the value to sentence
	out << "HiScore: " << num_string.str() << endl;
	num_string.str(""); // clears the previous string

	num_string << b.lifeline;
	string s_lifeline = "Cheats: " + num_string.str();
	out << "Cheats: " << num_string.str() << endl;
	num_string.str("");
	
        // out << "TEST 123" << endl;

        next_b = b.next_block;
        colour = decideColour(next_b);
        string name;
	// graphics for the next block
        if (b.graphics == true) { // only does this if user wants graphics
                b.w.fillRectangle(400,250,80,50,0); // prints white, so past block colour is not left behind 
		if (next_b == 'I') {
                        b.w.fillRectangle(400, 250, 80, 20, colour);
			b.w.fillRectangle(400, 250, 1, 20, 0); //
			b.w.fillRectangle(420, 250, 1, 20, 0); //
			b.w.fillRectangle(440, 250, 1, 20, 0); //
			b.w.fillRectangle(460, 250, 1, 20, 0); //
			b.w.fillRectangle(480, 250, 1, 20, 0); //
			b.w.fillRectangle(400, 250, 80, 1, 0); //
			b.w.fillRectangle(400, 270, 80, 1, 0); //
                }
                else if (next_b == 'J') {
                        b.w.fillRectangle(400, 250, 20, 20, colour);
			b.w.fillRectangle(400, 250, 20, 1, 0); //
			b.w.fillRectangle(420, 250, 1, 20, 0); //
			b.w.fillRectangle(400, 250, 1, 40, 0); //
                        b.w.fillRectangle(400, 270, 60, 20, colour);
			b.w.fillRectangle(400, 270, 60, 1, 0);
			b.w.fillRectangle(400, 290, 60, 1, 0);
			b.w.fillRectangle(420, 270, 1, 20, 0);
			b.w.fillRectangle(440, 270, 1, 20, 0);
			b.w.fillRectangle(460, 270, 1, 20, 0);
                }
                else if (next_b == 'L') {
                        b.w.fillRectangle(440, 250, 20, 20, colour);
			b.w.fillRectangle(440, 250, 1, 40, 0);
			b.w.fillRectangle(440, 250, 20, 1, 0);
                        b.w.fillRectangle(400, 270, 60, 20, colour);
			b.w.fillRectangle(400, 270, 60, 1, 0);
			b.w.fillRectangle(400, 290, 60, 1, 0);
			b.w.fillRectangle(400, 270, 1, 20, 0);
			b.w.fillRectangle(420, 270, 1, 20, 0);
			b.w.fillRectangle(440, 270, 1, 20, 0);
                }
                else if (next_b == 'O') {
                        b.w.fillRectangle(400, 250, 40, 20, colour);
                        b.w.fillRectangle(400, 270, 40, 20, colour);
			b.w.fillRectangle(400, 250, 40, 1, 0);
			b.w.fillRectangle(400, 270, 40, 1, 0);
			b.w.fillRectangle(400, 290, 40, 1, 0);
			b.w.fillRectangle(400, 250, 1, 40, 0);
			b.w.fillRectangle(420, 250, 1, 40, 0);
			b.w.fillRectangle(440, 250, 1, 40, 0);
		
                }
                else if (next_b == 'S') {
                        b.w.fillRectangle(420, 250, 40, 20, colour);
			b.w.fillRectangle(420, 250, 40, 1, 0);
			b.w.fillRectangle(400, 270, 40, 1, 0);
			b.w.fillRectangle(400, 290, 40, 1, 0);
                        b.w.fillRectangle(400, 270, 40, 20, colour);
			b.w.fillRectangle(400, 270, 1, 20, 0);
			b.w.fillRectangle(420, 250, 1, 40, 0);
			b.w.fillRectangle(440, 250, 1, 40, 0);
			b.w.fillRectangle(460, 250, 1, 20, 0);
			b.w.fillRectangle(400, 270, 60, 1, 0);
                }
                else if (next_b == 'Z') {
                        b.w.fillRectangle(400, 250, 40, 20, colour);
                        b.w.fillRectangle(420, 270, 40, 20, colour);
			b.w.fillRectangle(400, 250, 40, 1, 0);
			b.w.fillRectangle(400, 270, 40, 1, 0);
			b.w.fillRectangle(420, 290, 40, 1, 0);
			b.w.fillRectangle(400, 250, 1, 20, 0);
			b.w.fillRectangle(420, 250, 1, 40, 0);
			b.w.fillRectangle(440, 250, 1, 40, 0);
			b.w.fillRectangle(460, 270, 1, 20, 0);
			b.w.fillRectangle(420, 270, 40, 1, 0);
                }
                else if (next_b == 'T') {
                        b.w.fillRectangle(400, 250, 60, 20, colour);
                        b.w.fillRectangle(420, 270, 20, 20, colour);
			b.w.fillRectangle(400, 250, 60, 1, 0);
			b.w.fillRectangle(400, 270, 60, 1, 0); 
			b.w.fillRectangle(420, 290, 20, 1, 0);
			b.w.fillRectangle(400, 250, 1, 20, 0);
			b.w.fillRectangle(420, 250, 1, 40, 0);
			b.w.fillRectangle(440, 250, 1, 40, 0);
			b.w.fillRectangle(460, 250, 1, 20, 0);
                }
        }
	
	if(b.graphics == true) {
		b.w.fillRectangle(0, 30, 550, 40, 1);
		
		b.w.drawString(200, 50, "Q", 2);
		b.w.drawString(220, 60, "U", 3);
                b.w.drawString(240, 50, "A", 4);
                b.w.drawString(260, 60, "D", 5);
                b.w.drawString(280, 50, "R", 6);
                b.w.drawString(300, 60, "I", 7);
                b.w.drawString(320, 50, "S", 8);
                


		// clears the previous strings because we do not want overlap
		// in score like before, so print white background then
		// print string again
		b.w.fillRectangle(400, 140, 150, 70, 0);
		
		b.w.drawString(400,150,s_level, colour);
		b.w.drawString(400,170,s_score, colour);
		b.w.drawString(400,190,s_hiscore, colour);
		b.w.drawString(400,210,s_lifeline, colour);
		b.w.drawString(400,230, "Next Block: ");
		
		b.w.drawString(380,330,"Commands", colour);
		b.w.drawString(400,350,"left", 1);
		b.w.drawString(400,370,"right", 1);
		b.w.drawString(400,390,"down", 1);
		b.w.drawString(400,410,"clockwise", 1);
		b.w.drawString(400,430,"counterclockwise", 1);
		b.w.drawString(400,450,"drop", 1);
		b.w.drawString(400,470,"levelup", 1);
		b.w.drawString(400,490,"leveldown", 1);
		b.w.drawString(400,510,"restart", 1);
		b.w.drawString(380,530,"Life Saving Commands", colour);
		b.w.drawString(400,550,"cheat", 1);
		b.w.drawString(400,570,"changenextblock", 1); 
	}
	
	out << " -QUADRIS!-" << endl;
	
	// prints the board, if ' ' then prints black, otherwise, prints its respective colour	
	for (int i = 0; i < b.max_row; i++) {
		out << "|";
		for (int j = 0; j < b.max_col; j++) {
			bool block_at_r_c = false;
			// checks if there is a block at that position,
			// if there is a block, then we must print it
			for (int z = 0; z < 4; z++) { 
				if (j == b.current_block->getCol() + b.current_block->block_coord[z][0]) {
					if (i == b.current_block->getRow() + b.current_block->block_coord[z][1]) {
						block_at_r_c = true;
					}
	
				}
			}
			// if there is a block at that spot, must print out the thing
			if (block_at_r_c == true) {
				block_type = b.current_block->getBlockName();
			}
			else {
				block_type = b.gameBoard[i][j];
			}
			
			out << block_type;
			colour = decideColour(block_type);

			// set up graphical 
			if (b.graphics == true) {
				//b.w.fillRectangle((j * 30) + 50, (i * 30) + 95, 30, 30, 0);
				b.w.fillRectangle((j * 30) + 50, (i * 30) + 95, 30, 30, colour);
				if (colour != 1) { 
					b.w.fillRectangle((j * 30) + 50, (i * 30) + 95, 1, 30, 1); 
					b.w.fillRectangle((j * 30) + 50, (i * 30) + 95, 30, 1, 1);
				}
			}
		}
		out << "|";
		out << endl;
	}
	
	out << " ----------" << endl;
	
	// displays the next block as needed
	
	// does the following regardless of graphics or no graphics
	cout << "Next: " << endl;
	if (next_b == 'I') {
		name = "I";
		out << name;   // calls overloaded constructor
		// out << "IIII" << endl;
	}
	else if (next_b == 'J') {
		name = "J";
		out << name;   // calls overloaded constructor
	//	out << "J" << endl << "JJJ" << endl;
	}
	else if (next_b == 'L') {
		name = "L";
		out << name;   // calls overloaded constructor
	}
	else if (next_b == 'O') {
		name = "O";
		out << name;   // calls overloaded constructor
	}
	else if (next_b == 'S') {
		name = "S";
		out << name;   // calls overloaded constructor
	}
	else if (next_b == 'Z') {
		name = "Z";
		out << name;   // calls overloaded constructor
	}
	else if (next_b == 'T') {
		name = "T";
		out << name;   // calls overloaded constructor
	}
	out << endl;
	return out;
}


