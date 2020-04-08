
#ifndef COSC_ASS_ONE_PARTICLE_FILTER
#define COSC_ASS_ONE_PARTICLE_FILTER

#include <string>

#include "Breadcrumb.h"
#include "Trail.h"
#include "Types.h"

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
   void validateStartingPositions(Maze maze);

   // Ensure input maze contains only legal characters.
   void validateCharacters(Maze maze);

   // Checks if a location contains a valid position to move to.
   bool checkNewPosition(int x, int y, Maze maze);

   // Move to new position if an eligable position is found.
   bool mazeMove(Maze maze);

   // Move maze position back to last good position.
   void startBacktracking(Maze maze);

   // If trail has no breadcrumbs for our current location.
   void addBreadcrumb(int x, int y); 

   // Resets solution.
   void resetsSolution();

   // Sets first trail breadcrumb to S position.
   void setStartingPosition(Maze maze);

};

#endif // COSC_ASS_ONE_PARTICLE_FILTER
