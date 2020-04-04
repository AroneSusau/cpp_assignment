
#include "MazeSolver.h"
#include "Trail.h"
#include "Types.h"

MazeSolver::MazeSolver() :
   solution(new Trail()),
   error(false)
{}

MazeSolver::~MazeSolver() {
   if (solution != nullptr) {
      delete solution;
      solution = nullptr;
   }
}

void MazeSolver::solve(Maze maze) {

   Breadcrumb* currentPosition = nullptr;

   // Validation will flag errors and skips solving.
   validateStartingPositions(maze);
   outputText("VALIDATING STARTING POS " + std::to_string(error));
   validateCharacters(maze);
   outputText("VALIDATING CHARACTERS " + std::to_string(error));

   if (!error) {
      // Starting values.
      outputText("SETTING STARTING POS");
      setStartingPosition(maze, currentPosition);
      int x = currentPosition->getX();
      int y = currentPosition->getY();
      bool exit = false;
      
      // Directional values.
      int directions = 4;
      int xMove[] = {0, +1, 0, -1};
      int yMove[] = {-1, 0, +1, 0};

      // Complete flag.
      bool endNotReached = maze[y][x] != 'E';

      while (endNotReached || exit) {

         bool canMove = false;

         outputText("ADDING BREADCRUMB");
         addBreadcrumb(x, y, currentPosition);
         
         // Look for the first available stop to move, then move there.
         for (int i = 0; i < directions; ++i) {
            outputText("CHECKING MOVE DIRECTION...");

            int newX = x + xMove[i];
            int newY = y + yMove[i];
            bool moveable = checkNewPosition(newX, newY, maze);
            
            if (moveable) {
               outputText("MOVEABLE DIRECTION FOUND, MOVING..");
               x = newX;
               y = newY;
               canMove = true;
            }
         }

         if (!canMove) {
            outputText("NO MOVEABLE DIRECTION FOUND");
            bool searchingGoodBreadcrum = true;
            currentPosition->setStale(true);
            int lastIndex = solution->size() - 2;

            while (searchingGoodBreadcrum && lastIndex > -1) {
               outputText("MOVING BACK");
               Breadcrumb* lastGoodPosition = solution->getPtr(lastIndex);
               bool isGood = lastGoodPosition->isStale();

               if (isGood) {
                  outputText("GOOD POSITION FOUND");
                  searchingGoodBreadcrum = false;
                  currentPosition = lastGoodPosition;
                  x = currentPosition->getX();
                  y = currentPosition->getY();
               } else {
                  outputText("NO GOOD INDEX FOUND");
                  --lastIndex;
               }
            }

            if (lastIndex == -1) {
               outputText("ERROR, NO INDEXS LEFT TO MOVE BACK TO");
               error = true;
               exit = true;
               Trail* old = solution;
               solution = new Trail();

               delete old;
            }
         }

         endNotReached = maze[y][x] != 'E';
      }
   }
}

void MazeSolver::addBreadcrumb(int x, int y, Breadcrumb* currentPosition) {
   if (!solution->contains(x, y)) {
      currentPosition = new Breadcrumb(x, y, false);
      solution->addCopy(currentPosition);
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

   error = !(startFound && endFound);
}

bool MazeSolver::checkNewPosition(int x, int y, Maze maze) {
   bool xInBounds = 0 < x && x < MAZE_DIM;
   bool yInBounds = 0 < y && y < MAZE_DIM;
   bool validMazeChar = maze[y][x] == OPEN;
   bool empty = solution->contains(x, y);
   bool result = false;
   
   if (xInBounds && yInBounds && validMazeChar && empty) {
      result = true;
   }

   return result;
}

void MazeSolver::validateCharacters(Maze maze) {
   bool invalidCharacterFound = false;
   
   for (int row = 0; row < MAZE_DIM; ++row) {
      for (int col = 0; col < MAZE_DIM; ++col) {
         char point = maze[row][col];
         
         if (point != 'S' && point != 'E' && point != WALL && point != OPEN) {
            invalidCharacterFound = true;
         } 
      }
   }

   error = invalidCharacterFound;
}

void MazeSolver::setStartingPosition(Maze maze, Breadcrumb* position) {
   for (int row = 0; row < MAZE_DIM; ++row) {
      for (int col = 0; col < MAZE_DIM; ++col) {
         char point = maze[row][col];
         
         if (point == 'S') {
            Breadcrumb* b = new Breadcrumb(row, col, false);
            solution->addCopy(b);
            position = b;
         }
      }
   }
}

Trail* MazeSolver::getSolution() {
   Trail* cloneTrail = new Trail();

   int length = solution->size();

   for (int i = 0; i < length; i++) {
      Breadcrumb* b = solution->getPtr(i);
      cloneTrail->addCopy(b);
   }
   
   return cloneTrail;
}

void MazeSolver::outputText(std::string prompt) {
   std::cout << prompt << std::endl;
}