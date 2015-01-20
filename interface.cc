#include "interface.h"

using namespace std;

void cl_interface (string command, int value, string val, Game &g) {
        if (command == "-text") {
                // closes the window, since we don't need it
                g.b.w.~Xwindow();
                // sets the graphics to false,
                // so not graphics are printed in operator<<
                g.b.graphics = false;
        }

        else if (command == "-seed") {
        //      g.b.seed(value);
        }

        else if (command == "-scriptfile") {
                g.changeFileName(val);
        }

        else if (command == "-startlevel") {
                g.b.level = value;
        }
}

