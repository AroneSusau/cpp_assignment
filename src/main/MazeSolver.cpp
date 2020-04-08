
#include "../headers/MazeSolver.h"

#include "../headers/Trail.h"
#include "../headers/Types.h"
#include "../headers/Breadcrumb.h"
#include "../headers/milestone4.h"

MazeSolver::MazeSolver(): 
  solution(nullptr), 
  position(nullptr), 
  x(0), 
  y(0), 
  error(false) 
{}

MazeSolver::~MazeSolver() {
  if (solution != nullptr) {
    delete solution;
    solution = nullptr;
  }
}

void MazeSolver::solve(MazeManager* mazeManager) {
  int maxLength = mazeManager->getRows() * mazeManager->getColumns();
  solution = new Trail(maxLength);

  validateStartingPositions(mazeManager);
  validateCharacters(mazeManager);

  if (!error) {
    bool endNotReached = mazeManager->getValue(y, x) != 'E';

    setStartingPosition(mazeManager);

    while (endNotReached && !error) {
      
      addBreadcrumb(x, y);

      bool canMove = mazeMove(mazeManager);

      if (!canMove) {
        startBacktracking();
      }

      endNotReached = mazeManager->getValue(y, x) != 'E';
    }

    // Add final breadcrumb.
    if (!error) {
      addBreadcrumb(x, y);
    }

  }
}

bool MazeSolver::mazeMove(MazeManager* mazeManager) {
  int directions = 4;
  int xMove[] = {0, +1, 0, -1};
  int yMove[] = {-1, 0, +1, 0};

  bool searching = true;
  bool canMove = false;
  int index = 0;

  while (searching && index < directions) {
    int newX = x + xMove[index];
    int newY = y + yMove[index];
    bool moveable = checkNewPosition(newX, newY, mazeManager);

    if (moveable) {
      x = newX;
      y = newY;
      canMove = true;
      searching = false;
    }

    ++index;
  }

  return canMove;
}

void MazeSolver::addBreadcrumb(int x, int y) {
  if (!solution->contains(x, y)) {
    position = new Breadcrumb(x, y, false);
    solution->addCopy(position);
  }
}

void MazeSolver::startBacktracking() {
  int lastIndex = solution->size() - 1;

  bool searchingGoodBreadcrum = true;
  bool noMoreFreshCrumbs = lastIndex == -1;

  position->setStale(true);

  while (searchingGoodBreadcrum && lastIndex >= 0) {
    Breadcrumb* lastGoodPosition = solution->getPtr(lastIndex);
    bool isGood = !lastGoodPosition->isStale();

    if (isGood) {
      searchingGoodBreadcrum = false;
      position = lastGoodPosition;
      x = position->getX();
      y = position->getY();
    } else {
      --lastIndex;
    }

    noMoreFreshCrumbs = lastIndex == -1;
  }

  if (noMoreFreshCrumbs) {
    error = true;
    delete solution;
    solution = nullptr;
  }
}

void MazeSolver::validateStartingPositions(MazeManager* mazeManager) {
  bool startFound = false;
  bool endFound = false;

  for (int row = 0; row < mazeManager->getRows(); ++row) {
    for (int col = 0; col < mazeManager->getColumns(); ++col) {
      char point = mazeManager->getValue(row, col);

      if (point == 'S') {
        startFound = true;
      } else if (point == 'E') {
        endFound = true; 
      }
    }
  }

  if (!(startFound && endFound)) {
    error = true;
  }
}

bool MazeSolver::checkNewPosition(int x, int y, MazeManager* mazeManager) {
  char character = mazeManager->getValue(y, x);
  
  bool xInBounds = 0 <= x && x < mazeManager->getColumns();
  bool yInBounds = 0 <= y && y < mazeManager->getRows();
  bool isOpen = character == OPEN;
  bool isEnd = character == 'E';
  bool isStart = character == 'S';
  bool validMazeChar = isOpen || isEnd || isStart;
  bool empty = !solution->contains(x, y);
  bool result = false;

  if (xInBounds && yInBounds && validMazeChar && empty) {
    result = true;
  }

  return result;
}

void MazeSolver::validateCharacters(MazeManager* mazeManager) {
for (int row = 0; row < mazeManager->getRows(); ++row) {
    for (int col = 0; col < mazeManager->getColumns(); ++col) {
      char point = mazeManager->getValue(row, col);

      bool notStart = point != 'S';
      bool notEnd = point != 'E';
      bool notWall = point != WALL;
      bool notOpen = point != OPEN;
      bool invalidCharacter = notStart && notEnd && notWall && notOpen;

      if (invalidCharacter) {
        error = true;
      }
    }
  }
}

void MazeSolver::setStartingPosition(MazeManager* mazeManager) {
  for (int row = 0; row < mazeManager->getRows(); ++row) {
    for (int col = 0; col < mazeManager->getColumns(); ++col) {
      char point = mazeManager->getValue(row, col);

      if (point == 'S') {
        Breadcrumb* b = new Breadcrumb(col, row, false);
        position = b;

        solution->addCopy(b);
        x = position->getX();
        y = position->getY();
      }
    }
  }
}

Trail* MazeSolver::getSolution(MazeManager* mazeManager) {
  Trail* clone = nullptr;

  if (solution != nullptr) {
    int maxLength = mazeManager->getRows() * mazeManager->getColumns();

    clone = new Trail(solution, maxLength);
  }

  return clone;
}
