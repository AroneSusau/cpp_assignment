
#include "../headers/MazeSolver.h"
#include "../headers/Trail.h"
#include "../headers/Types.h"

MazeSolver::MazeSolver() :
   solution(new Trail()),
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

void MazeSolver::solve(Maze maze) {
   validateStartingPositions(maze);
   validateCharacters(maze);

   if (!error) {
      bool endNotReached = maze[y][x] != 'E';

      setStartingPosition(maze);

      while (endNotReached && !error) {

         addBreadcrumb(x, y);

         bool canMove = mazeMove(maze);

         if (!canMove) {
            startBacktracking(maze);
         }

         endNotReached = maze[y][x] != 'E';
      }
   }
}

bool MazeSolver::mazeMove(Maze maze) {
   // Directional values in order: NORTH, SOUTH, EAST, WEST.
   int directions = 4;
   int xMove[] = {0, +1, 0, -1};
   int yMove[] = {-1, 0, +1, 0};

   bool searching = true;
   bool canMove = false;
   int index = 0;

   while (searching && index < directions) {
      int newX = x + xMove[index];
      int newY = y + yMove[index];
      bool moveable = checkNewPosition(newX, newY, maze);
      
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

void MazeSolver::startBacktracking(Maze maze) {
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

void MazeSolver::validateStartingPositions(Maze maze) {
   bool startFound = false;
   bool endFound = false;
   
   for (int row = 0; row < MAZE_DIM; ++row) {
      for (int col = 0; col < MAZE_DIM; ++col) {
         char point = maze[row][col];
         
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

bool MazeSolver::checkNewPosition(int x, int y, Maze maze) {
   bool xInBounds = 0 <= x && x < MAZE_DIM;
   bool yInBounds = 0 <= y && y < MAZE_DIM;
   bool validMazeChar = maze[y][x] == OPEN || maze[y][x] == 'E' || maze[y][x] == 'S';
   bool empty = !solution->contains(x, y);
   bool result = false;
   
   if (xInBounds && yInBounds && validMazeChar && empty) {
      result = true;
   }

   return result;
}

void MazeSolver::validateCharacters(Maze maze) {
   
   for (int row = 0; row < MAZE_DIM; ++row) {
      for (int col = 0; col < MAZE_DIM; ++col) {
         char point = maze[row][col];
         bool invalidCharacter = 
            point != 'S' && 
            point != 'E' && 
            point != WALL && 
            point != OPEN; 
         
         if (invalidCharacter) {
            error = true;
         } 
      }
   }
}

void MazeSolver::setStartingPosition(Maze maze) {
   for (int row = 0; row < MAZE_DIM; ++row) {
      for (int col = 0; col < MAZE_DIM; ++col) {
         char point = maze[row][col];
         
         if (point == 'S') {
            Breadcrumb* b = new Breadcrumb(col, row, false);
            
            solution->addCopy(b);
            position = b;
            x = position->getX();
            y = position->getY();
         }
      }
   }
}

Trail* MazeSolver::getSolution() {
   Trail* clone = nullptr;

   if (solution != nullptr) {
      clone = new Trail(solution);
   }
   
   return clone;
}
