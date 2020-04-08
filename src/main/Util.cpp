
#include "../headers/Util.h"

#include <iostream>

#include "../headers/Trail.h"
#include "../headers/Types.h"
#include "../headers/Breadcrumb.h"
#include "../headers/milestone4.h"

Util::Util() {}
Util::~Util() {}

void Util::readMazeStdin(MazeManager* mazeManager) {

  int row = 1;
  int col = 1;

  std::string tmp = "";

  while(!std::cin.eof()) {
    char c;
    std::cin.get(c);

    if (c == '\n') {      
      ++row;
      col = -1;
    } else {
      tmp += c;
      ++col;
    } 
  }

  mazeManager->updateMaze(tmp, row, col);
}

void Util::printMazeStdout(MazeManager* mazeManager, Trail* solution) {

  bool solutionExits = solution != nullptr && solution->size() > 0;
  
  if (solutionExits) {

    for (int row = 0; row < mazeManager->getRows(); ++row) {
      for (int col = 0; col < mazeManager->getColumns(); ++col) {
        
        Breadcrumb* b = solution->find(col, row);
        char character = mazeManager->getValue(row, col);
        
        bool goodCrumb = b != nullptr && !b->isStale();
        bool notStart = character != 'S';
        bool notEnd = character != 'E';
        bool validPath = goodCrumb && notStart && notEnd;

        if (validPath) {
          std::cout << ROUTE;
        } else {
          std::cout << character;
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

  std::cout << "Movement Directions" << std::endl;

  Breadcrumb* initial = solution->getPtr(0);
  int prevX = initial->getX();
  int prevY = initial->getY();
  
  for (int i = 1; i < solution->size(); ++i) {
    Breadcrumb* current = solution->getPtr(i);
    
    if (current != nullptr && !current->isStale()) {
      int currX = current->getX();
      int currY = current->getY();

      int finalX = prevX - currX;
      int finalY = prevY - currY;

      bool movedNorth = finalX == 0 && finalY == 1;
      bool movedEast = finalX == -1 && finalY == 0;
      bool movedSouth = finalX == 0 && finalY == -1;
      bool movedWest = finalX == 1 && finalY == 0;

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

      prevX = currX;
      prevY = currY;
    }

  }
}