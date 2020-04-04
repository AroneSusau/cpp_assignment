#ifndef UTIL_H
#define UTIL_H

#include "Types.h"
#include "Trail.h"

class Util {
    public: 

        Util();
        ~Util();

        void readMazeStdin(Maze maze);
        void printMazeStdout(Maze maze, Trail* solution);
};

#endif
