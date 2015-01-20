#include "oblock.h"
using namespace std;

OBlock::OBlock() {
	row = 0;
	col = 0;
	orientation = 'N'; // default orientation 
	blockName = 'O';
	blockCoord(orientation);
}

void OBlock::blockCoord(char ori) {   
	// either rotate will always result in the same thing, square
	block_coord[0][0] = 0;
	block_coord[1][0] = 0;
	block_coord[2][0] = 1;
	block_coord[3][0] = 1;
	// spaces from top of board
	block_coord[0][1] = 2;
	block_coord[1][1] = 3;
	block_coord[2][1] = 2;
	block_coord[3][1] = 3;
	
}
	
