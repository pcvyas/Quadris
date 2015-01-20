#include "interpreter.h"
#include "window.h"
#include "board.h"

using namespace std;


void interpreter (string command, Game &g) {
        if (command == "left" || command == "lef") {
                g.b.left();
        }
        else if (command == "right" || command == "ri" || command == "righ" || command == "r") {
                g.b.right();
        }
        else if (command == "down" || command == "dow" || command == "do") {
                g.b.down();
        }
        else if (command == "drop" || command == "dr" || command == "dro") {
                g.b.drop();
        }
        else if (command == "counterclockwise" || command == "ccw" || command == "cc" || command == "counterclock" || command == "ccwise") {
                g.b.CCW();
        }
        else if (command == "clockwise" || command == "cw" || command == "clockw" || command == "cwise") {
                g.b.CW();
        }
        else if (command == "levelup" || command == "lu" || command == "lup" || command == "levelu" || command == "lvlup" || command == "lvlu") {
		g.levelup();
        }
        else if (command == "leveldown" || command == "ld" || command == "leveld" || command == "ldown" || command == "lvldown" || command == "lvld") {
                g.leveldown();
        }
	else if (command == "restart" || command == "re" || command == "reset" || command == "restar") {
		g.restart();
	}
	// special feature to help the player
	else if (command == "cheat") {
		if (g.b.lifeline > 0) {
			int prev_lvl = g.b.level;
			int prev_score = g.b.score;
			g.b.lifeline--;
			// clears the 15th line (bottom)
			g.b.clearLines(14);
			g.b.level = prev_lvl;
			g.b.score = prev_score;
			// g.b.w.drawString(150,200,"1 used",0);	
		}
		else {
			cout << "Sorry, no cheats available. You're on your own!" << endl;
		}
	}
	else if (command == "changenextblock" || command == "cnb") {
		char block;
		cin >> block;
		if (g.b.lifeline > 0) {
			int prev_lvl = g.b.level;
			int prev_score = g.b.score;
			g.b.lifeline--;
			g.b.next_block = block;
			g.b.level = prev_lvl;
			g.b.score = prev_score;
		}
		else {
			cout << "Sorry, no cheats available. You're on your own!" << endl;
		}
	}		
        else {
                cout << "Invalid Command" << endl;
        }
        g.b.linesCompleted();
}

