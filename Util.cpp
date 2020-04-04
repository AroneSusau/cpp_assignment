
#include <iostream>

#include "Types.h"
#include "Trail.h"
#include "Util.h"

Util::Util() {}
Util::~Util() {}

void Util::readMazeStdin(Maze maze) {
    for (int row = 0; row < MAZE_DIM; ++row) {
        for (int col = 0; col < MAZE_DIM; ++col) {
            if (!std::cin.eof()) {
                std::cin >> maze[row][col];
            }
        }
    }
}

void Util::printMazeStdout(Maze maze, Trail* solution) {    
    if (solution->size() > 0) {
        
        for (int row = 0; row < MAZE_DIM; ++row) {
            for (int col = 0; col < MAZE_DIM; ++col) {
                
                int index = row * col;
                bool pathExistsAndNotStale = 
                    solution->contains(row, col) 
                    && !solution->getPtr(index)->isStale();
                
                if (pathExistsAndNotStale) {
                    std::cout << ROUTE;
                } else {
                    std::cout << maze[row][col];
                }
                
            }
            std::cout << std::endl;
        }

    } else {
        std::cout << "ERROR: Invalid maze passed in." << std::endl;
    }
}
