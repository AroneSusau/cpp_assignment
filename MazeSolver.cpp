
#include "MazeSolver.h"
#include "Trail.h"
#include "Types.h"

MazeSolver::MazeSolver() {}

MazeSolver::~MazeSolver() {
   if (solution != nullptr) {
      delete solution;
      solution = nullptr;
   }
}

void MazeSolver::solve(Maze maze) {
   // TODO
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
