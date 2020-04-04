
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
   Breadcrumb* currentPosition;
   validateStartingPositions(maze);
   validateCharacters(maze);

   if (!error) {
      setStartingPosition(maze, currentPosition);
      int x = currentPosition->getX();
      int y = currentPosition->getY();

      while (maze[y][x] != 'B') {

      }
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

void MazeSolver::validateCharacters(Maze maze) {
   bool invalidCharacterFound = false;
   
   for (int row = 0; row < MAZE_DIM; ++row) {
      for (int col = 0; col < MAZE_DIM; ++col) {
         char point = maze[row][col];
         
         if (point != 'S' || point == 'E' || point == WALL || point == OPEN) {
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
