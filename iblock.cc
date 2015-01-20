#include "iblock.h"
using namespace std;

IBlock::IBlock() {
	row = 0;
	col = 0;
	orientation = 'N'; // default orientation 
	blockName = 'I';
	blockCoord(orientation);
}

void IBlock::blockCoord(char ori) {    // default placement of I is horizontal IIII
	if (ori == 'N' || ori == 'S') {    // horizontal IIII 
		block_coord[0][0] = 0;
		block_coord[1][0] = 1;
		block_coord[2][0] = 2;
		block_coord[3][0] = 3;
		// spaces from top of board
		block_coord[0][1] = 3;
		block_coord[1][1] = 3;
		block_coord[2][1] = 3;
		block_coord[3][1] = 3;
	}
	else {
		block_coord[0][0] = 0;
		block_coord[1][0] = 0;
		block_coord[2][0] = 0;
		block_coord[3][0] = 0;
		// spaces from top of board
		block_coord[0][1] = 0;
		block_coord[1][1] = 1;
		block_coord[2][1] = 2;
		block_coord[3][1] = 3;
	}
}
	
