#ifndef UTIL_H
#define UTIL_H

#include "Trail.h"
#include "Types.h"

class Util {
 public:
  Util();
  ~Util();

  // Read in a maze from standard input.
  void readMazeStdin(Maze maze);

  // Print the maze to standard output.
  void printMazeStdout(Maze maze, Trail* solution);

  // Print out the movement directions to standard output.
  void printMovementDirections(Trail* solution);
};

#endif
