#include "game.h"

using namespace std;

bool Game::loss() {
	// easier to call our conflict method to see if there is a conflict
	// between the block and the top row
	return b.conflict(0,0);
}

void Game::restart() {
	char block;
	b.clearBoard();
	b.open_file.close();
	b.open_file.open(b.filename.c_str());
	b.open_file >> block;
	b.blockmaker(block);
	b.next();
}

void Game::levelup() {
	// cant go above level 4
	if (b.level <= 3) { 
		b.level++; 
	}
}

void Game::leveldown() {
	// cant go below level 0
	if (b.level >= 1) { 
		b.level--; 
	}
}

void Game::changeFileName (string fname) {
	// just change the file name
	b.filename = fname;
}

ostream &operator<<(ostream &out, Game &g) {
	// prints the board
	out << g.b;
	if (g.loss() == true && g.b.graphics == true) {
		g.b.w.drawString(150, 200, "Game Over", 0);
		g.b.w.drawString(150, 220, "Continue?", 0);
	}

	return out;
}
