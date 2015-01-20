#include "block.h"
using namespace std;

int maxRows = 15;
int maxCols = 10;

int Block::getRow() {
	return row;
}

int Block::getCol() {
	return col;
}

char Block::getBlockName() {
	return blockName;
}

void Block::rotateCCW() {
	if (orientation == 'N') {
		orientation = 'W';
	}
	else if (orientation == 'S') {
		orientation = 'E';
	}
	else if (orientation == 'E') {
		orientation = 'N';
	}
	else {
		orientation = 'S';
	}
	// the above sets the orientation, then call blockCoord
	// to set the coordinates of the block (I, J, L, O, S, Z, or T)
	blockCoord(orientation);
}

void Block::rotateCW() {
	if (orientation == 'N') {
		orientation = 'E';
	}
	else if (orientation == 'S') {
		orientation = 'W';
	}
	else if (orientation == 'E') {
		orientation = 'S';
	}
	else {
		orientation = 'N';
	}
	blockCoord(orientation);
}

void Block::shiftLeft() {
	// can shift left if col of block is 1 or more
	if (col >= 1) {
		col--;
	}
	else { return; };
}

void Block::shiftRight() {
	// can move right if col of block is 9 or less
	if (col <= maxCols - 1) {
		col++;
	}
	else { return; };
}

void Block::shiftDown() {
	if (row <= maxRows - 1) {
		// moving down, rows increase
		row++;
	}
	else {
		return;
	}
}


Block::~Block() {
	for (int i = 0; i < 4; i++) {
		delete [] block_coord[i];
	}
	delete []block_coord;
}
