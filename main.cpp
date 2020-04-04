
#include <iostream>
#include <string>

#include "Types.h"
#include "MazeSolver.h"
#include "Util.h"
#include "Tests.h"

int main(int argc, char** argv) {
    //Tests
    Tests* tests = new Tests();
    tests->runTestSuite();

    // Load Maze from stdin
    Maze maze;
    Util* util = new Util();
    util->readMazeStdin(maze);

    // Solve using MazeSolver
    MazeSolver* solver = new MazeSolver();
    Trail* solution = nullptr;
    solver->solve(maze);
    solution = solver->getSolution();

    // Print Maze to stdout
    util->printMazeStdout(maze, solution);

    delete solver;
    delete util;
    delete tests;

    return EXIT_SUCCESS;
}
