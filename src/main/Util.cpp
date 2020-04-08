
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
        
        bool goodCrumb = b != nullptr && !b->isStale();
        bool notStart = maze[row][col] != 'S';
        bool notEnd = maze[row][col] != 'E';
        bool validPath = goodCrumb && notStart && notEnd;

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
  Breadcrumb* initial = solution->getPtr(0);
  int prevX = initial->getX();
  int prevY = initial->getY();
  
  for (int i = 1; i < solution->size(); ++i) {
    Breadcrumb* current = solution->getPtr(i);
    int currX = current->getX();
    int currY = current->getY();

    int finalX = prevX - currX;
    int finalY = prevY - currY;

    bool movedNorth = finalX == 0 && finalY == -1;
    bool movedEast = finalX == 1 && finalY == 0;
    bool movedSouth = finalX == 0 && finalY == 1;
    bool movedWest = finalX == -1 && finalY == 0;

    if (movedNorth) {
      std::cout << "North" << std::endl;
    } else if (movedEast) {
      std::cout << "East" << std::endl;
    } else if (movedSouth) {
      std::cout << "South" << std::endl;
    } else if (movedWest) {
      std::cout << "West" << std::endl;
    } else {
      std::cout << "Unexpectd Movement Direction" << std::endl;
    }
  }
}