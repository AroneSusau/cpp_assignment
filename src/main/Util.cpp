
#include <iostream>

#include "../headers/Types.h"
#include "../headers/Trail.h"
#include "../headers/Util.h"

Util::Util() {}
Util::~Util() {}

void Util::readMazeStdin(Maze maze) {
    char placeholder = ' ';
    
    for (int row = 0; row < MAZE_DIM; ++row) {
        for (int col = 0; col < MAZE_DIM; ++col) {
            if (!std::cin.eof()) {
                std::cin >> maze[row][col];
            }
        }
    }

    std::cin >> placeholder;

    // File is oversized if EOF hasn't been reached yet. 
    // Invalidate the maze with a bad character.
    if (!std::cin.eof()) {
        maze[0][0] = 'X';
    }
}

void Util::printMazeStdout(Maze maze, Trail* solution) {    
    if (solution != nullptr && solution->size() > 0) {
        
        for (int row = 0; row < MAZE_DIM; ++row) {
            for (int col = 0; col < MAZE_DIM; ++col) {
                
                Breadcrumb* b = solution->find(col, row);
                bool validPath = 
                    b != nullptr 
                    && !b->isStale()
                    && maze[row][col] != 'S'
                    && maze[row][col] != 'E';
                
                if (validPath) {
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
