#ifndef UTIL_H
#define UTIL_H

#include "Trail.h"
#include "Types.h"
#include "../headers/milestone4.h"

class Util {
 public:
  Util();
  ~Util();

  // Read in a maze from standard input.
  void readMazeStdin(MazeManager* mazeManager);

  // Print the maze to standard output.
  void printMazeStdout(MazeManager* mazeManager, Trail* solution);

  // Print out the movement directions to standard output.
  void printMovementDirections(Trail* solution);
};

#endif
