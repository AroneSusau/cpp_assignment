
#include "../headers/Util.h"

#include <iostream>

#include "../headers/Trail.h"
#include "../headers/Types.h"

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
        bool notEmpty = b != nullptr;
        bool notStale = !b->isStale();
        bool notStart = maze[row][col] != 'S';
        bool notEnd = maze[row][col] != 'E';
        bool validPath = notEmpty && notStale && notStart && notEnd;

        if (validPath) {
          std::cout << ROUTE;
        } else {
          std::cout << maze[row][col];
        }
      }
      std::cout << std::endl;
    }

    printMovementDirections(solution);

  } else {
    std::cout << "ERROR: Invalid maze passed in." << std::endl;
  }
}

void Util::printMovementDirections(Trail* solution) {
  for (int row = 0; row < MAZE_DIM; ++row) {
    for (int col = 0; col < MAZE_DIM; ++col) {
      Breadcrumb* b = solution->find(col, row);
      bool validPath = b != nullptr && !b->isStale() && maze[row][col] != 'S' &&
                       maze[row][col] != 'E';

      if (validPath) {
        std::cout << ROUTE;
      } else {
        std::cout << maze[row][col];
      }
    }
    std::cout << std::endl;
  }
}