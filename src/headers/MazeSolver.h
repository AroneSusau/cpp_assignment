
#ifndef COSC_ASS_ONE_PARTICLE_FILTER
#define COSC_ASS_ONE_PARTICLE_FILTER

#include <string>

#include "Breadcrumb.h"
#include "Trail.h"
#include "Types.h"
#include "milestone4.h"

class MazeSolver {
 public:
  /*                                           */
  /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
  /*                                           */

  // Constructor/Destructor
  MazeSolver();
  ~MazeSolver();

  // Solve the maze
  void solve(Maze maze);

  // Get a DEEP COPY of the solution
  Trail* getSolution();

  /*                                           */
  /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
  /*                                           */

  // Get a DEEP COPY of the solution
  Trail* getSolution(MazeManager* mazeManager);

  // Solve the maze
  void solve(MazeManager* mazeManager);

 private:
  /*                                           */
  /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
  /*                                           */

  // Trail of breadcrumbs from the start to end
  Trail* solution;

  /*                                           */
  /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
  /*                                           */

  // Pointer to the current position in the maze.
  Breadcrumb* position;

  // Current x position.
  int x;

  // Current y position.
  int y;

  // Flag if error discovered in maze.
  bool error;

  // Ensure input maze contains an S and E position.
  void validateStartingPositions(MazeManager* mazeManager);

  // Ensure input maze contains only legal characters.
  void validateCharacters(MazeManager* mazeManager);

  // Checks if a location contains a valid position to move to.
  bool checkNewPosition(int x, int y, MazeManager* mazeManager);

  // Move to new position if an eligable position is found.
  bool mazeMove(MazeManager* mazeManager);

  // Move maze position back to last good position.
  void startBacktracking();

  // If trail has no breadcrumbs for our current location.
  void addBreadcrumb(int x, int y);

  // Resets solution.
  void resetsSolution();

  // Sets first trail breadcrumb to S position.
  void setStartingPosition(MazeManager* mazeManager);
};

#endif  // COSC_ASS_ONE_PARTICLE_FILTER
