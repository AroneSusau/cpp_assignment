
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
   return solution;
}
