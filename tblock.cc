#include "tblock.h"
using namespace std;

TBlock::TBlock() {
	row = 0;
	col = 0;
	orientation = 'N'; // default orientation 
	blockName = 'T';
	blockCoord(orientation);
}

void TBlock::blockCoord(char ori) { 
	if (ori == 'N') { 
		block_coord[0][0] = 0;
		block_coord[1][0] = 1;
		block_coord[2][0] = 1;
		block_coord[3][0] = 2;
		// row to print on
		block_coord[0][1] = 2;
		block_coord[1][1] = 2;
		block_coord[2][1] = 3;
		block_coord[3][1] = 2;
	}
	else if (ori == 'E') {
		block_coord[0][0] = 0;
		block_coord[1][0] = 1;
		block_coord[2][0] = 1;
		block_coord[3][0] = 1;
		// spaces from top of board
		block_coord[0][1] = 2;
		block_coord[1][1] = 1;
		block_coord[2][1] = 2;
		block_coord[3][1] = 3;
	}
	else if (ori == 'S') {
		block_coord[0][0] = 0;
		block_coord[1][0] = 1;
		block_coord[2][0] = 1;
		block_coord[3][0] = 2;
		// spaces from top of board
		block_coord[0][1] = 3;
		block_coord[1][1] = 3;
		block_coord[2][1] = 2;
		block_coord[3][1] = 3;
	}
	else {
		block_coord[0][0] = 0;
		block_coord[1][0] = 0;
		block_coord[2][0] = 0;
		block_coord[3][0] = 1;
		// spaces from top of board
		block_coord[0][1] = 1;
		block_coord[1][1] = 2;
		block_coord[2][1] = 3;
		block_coord[3][1] = 2;
	}
}
	
