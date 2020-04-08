/* * * * * * * * * * * * * *
Assignment 1 COSC1070

Author: Arone Susau
Student#: S3728977
Year: 2020

Program description can be found in README.md
* * * * * * * * * * * * * */

#include <iostream>
#include <string>

#include "../headers/MazeSolver.h"
#include "../headers/Tests.h"
#include "../headers/Types.h"
#include "../headers/Util.h"
#include "../headers/milestone4.h"

int main(int argc, char** argv) {
  // Tests - If commenting out, dont forget the 'delete tests' at the bottom too. 
  // Tests* tests = new Tests(); tests->runTestSuite();

  // Load Maze from stdin
  MazeManager* mazeManager = new MazeManager();
  Util* util = new Util();
  util->readMazeStdin(mazeManager);

  // Solve using MazeSolver
  MazeSolver* solver = new MazeSolver();
  Trail* solution = nullptr;
  solver->solve(mazeManager);
  solution = solver->getSolution(mazeManager);

  // Print Maze to stdout
  util->printMazeStdout(mazeManager, solution);
  util->printMovementDirections(solution);

  delete solver;
  delete util;
  // delete tests;

  return EXIT_SUCCESS;
}
