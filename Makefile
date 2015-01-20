CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = quadris
OBJECTS = main.o game.o board.o block.o window.o interface.o interpreter.o iblock.o jblock.o lblock.o oblock.o sblock.o zblock.o tblock.o
DEPENDS = ${OBJECTS:.o=.d}
X11 = -lX11

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} ${X11}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
