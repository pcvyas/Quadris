#include "sblock.h"
using namespace std;

SBlock::SBlock() {
	row = 0;
	col = 0;
	orientation = 'N'; // default orientation 
	blockName = 'S';
	blockCoord(orientation);
}

void SBlock::blockCoord(char ori) {
	// s block is symmetric    
	if (ori == 'N' || ori == 'S') {  
		// col to print on
		block_coord[0][0] = 0;
		block_coord[1][0] = 1;
		block_coord[2][0] = 1;
		block_coord[3][0] = 2;
		// row to print on
		block_coord[0][1] = 3;
		block_coord[1][1] = 3;
		block_coord[2][1] = 2;
		block_coord[3][1] = 2;
	}
	else {
		// columns to print block on
		block_coord[0][0] = 0;
		block_coord[1][0] = 0;
		block_coord[2][0] = 1;
		block_coord[3][0] = 1;
		// corresponding row to print on
		block_coord[0][1] = 1;
		block_coord[1][1] = 2;
		block_coord[2][1] = 2;
		block_coord[3][1] = 3;
	}
}
	
