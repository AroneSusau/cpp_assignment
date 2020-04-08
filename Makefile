vpath %.cpp src/main

OBJECTS = main.o Util.o Tests.o MazeSolver.o Trail.o Breadcrumb.o MazeManager.o

.default: all

all: MazeSolver

test: 
	sh ./scripts/run_tests.sh

clean:
	rm -f MazeSolver objs/*.o

MazeSolver: $(OBJECTS)
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $(addprefix objs/, $(OBJECTS))

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^ -o objs/$@
