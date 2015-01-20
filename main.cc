#include "game.h"
#include "window.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "interpreter.h"
#include "interface.h"

using namespace std;


int main (int argc, char* argv[]) {
	string command;
	// Board b;
	Game g;
	int text = 0;
	int seed = 0;
	int sf = 0;
	int sl = 0;
	if (argc >= 2) { // this ensures that there is a cl operation
		// loops so multiple cl operations can be passed
		for (int i = 1; i < argc; i++) {
			string c = argv[i];
			if (c == "-text") {
				cl_interface(argv[i], 0, "", g);
				if (sf == 0 && argc == 2) {
					g.b.open_file.open("sequence.txt");
					g.b.open_file >> g.b.next_block;
					g.b.blockmaker(g.b.next_block);
					g.b.next();
				}
				text++;
			}
			else if (c == "-seed") {
				cl_interface(argv[i], atoi(argv[i + 1]), "", g);
				if (sf == 0) {
					g.b.open_file.open("sequence.txt");
					g.b.open_file >> g.b.next_block;
					g.b.blockmaker(g.b.next_block);
					g.b.next();
				}
				seed++;
			}
			else if (c == "-scriptfile") {
				string f = argv[i + 1];
				cl_interface(argv[i], 0, argv[i + 1], g);
				if (argc >= 2) {
					g.b.open_file.open(f.c_str());
					g.b.open_file >> g.b.next_block;
					g.b.blockmaker(g.b.next_block);
					g.b.next();
				}
				sf++;
			}
			else if (c == "-startlevel") {
				cl_interface(argv[i], atoi(argv[i + 1]), "", g);
				if (sf == 0) {
					g.b.next();
					g.b.blockmaker(g.b.next_block);
					g.b.next();
				}
				sl++;
			}
		}
 	}
	else {
		g.b.open_file.open("sequence.txt");
		g.b.open_file >> g.b.next_block;
		g.b.blockmaker(g.b.next_block);
		g.b.next();
	}

	cout << g;
	cout << "Enter a command: " << endl;

	while (cin >> command) {
		if (command == "exit") {
			exit(EXIT_FAILURE);
		}
		int first_num = atoi(command.c_str());
		if (first_num >= 1 && first_num <= 10) {
			command = command.substr(1, command.length());
			for (int i = 0; i < first_num; i++) {
				interpreter(command, g);
			}
			cout << endl << g;
		}
		else if (first_num == 0) {
			interpreter(command, g);
			cout << endl << g;
		}
		else {
			cout << "Invalid Command" << endl;
		}
		
		// interpreter(command, b);
		
		if (g.loss() == true) {
			cout << endl << "Game Over" << endl;
			cout << "Continue? (y/n)" << endl;
			cin >> command;
			if (command == "yes" || command == "y") { 
				g.restart();
				cout << g; 
			}
			else { exit(EXIT_FAILURE); }
			//cout << g;
		}
		
		cout << endl << "Enter a command: " << endl;
	}
	// create Game destructor
	// delete &g.b;

}
			
	
