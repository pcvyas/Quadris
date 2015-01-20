#ifndef _IBLOCK_H_
#define _IBLOCK_H_
#include "block.h"

class IBlock: public Block {
	public:
		IBlock();
		void blockCoord(char ori);
};

#endif
