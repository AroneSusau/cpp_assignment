.default: all

all: MazeSolver

clean:
	rm -f MazeSolver *.o

MazeSolver: main.o Util.o Tests.o MazeSolver.o Trail.o Breadcrumb.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
