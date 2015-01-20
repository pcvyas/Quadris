#include "zblock.h"
using namespace std;

ZBlock::ZBlock() {
	row = 0;
	col = 0;
	orientation = 'N'; // default orientation 
	blockName = 'Z';
	blockCoord(orientation);
}

void ZBlock::blockCoord(char ori) { 
	// z block is symmetric 
	if (ori == 'N' || ori == 'S') {  
		block_coord[0][0] = 0;
		block_coord[1][0] = 1;
		block_coord[2][0] = 1;
		block_coord[3][0] = 2;
		// row to print on
		block_coord[0][1] = 2;
		block_coord[1][1] = 2;
		block_coord[2][1] = 3;
		block_coord[3][1] = 3;
	}
	else {
		// col to print on
		block_coord[0][0] = 0;
		block_coord[1][0] = 0;
		block_coord[2][0] = 1;
		block_coord[3][0] = 1;
		// row to print on
		block_coord[0][1] = 2;
		block_coord[1][1] = 3;
		block_coord[2][1] = 1;
		block_coord[3][1] = 2;
	}
}
	
