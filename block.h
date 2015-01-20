#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>

class Block {
	public:
		int row, col;
		char orientation, blockName;
		// blockName is either I, j, L, O, S, Z, T

		int block_coord[4][2]; // first one is for col and the second for row
		virtual void blockCoord(char ori) = 0;
		int getRow();
		int getCol();
		char getBlockName();
		
		// block movement
		void rotateCCW();
		void rotateCW();
		void shiftLeft();
		void shiftRight();
		void shiftDown();
		
		// Block();
		~Block();
};
		
#endif
