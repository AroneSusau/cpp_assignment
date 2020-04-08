#ifndef MAZEMANAGER_H
#define MAZEMANAGER_H

/*
 * These are some sample functions to help you dynamically allocate
 *  memory for a generic 2D Maze.
 */

#include "Types.h"

class MazeManager {

  public: 

    // Constructor / Deconstructor
    MazeManager();
    MazeManager(int rows, int columns);    
    ~MazeManager();

    // Makes a new maze by rows / cols
    void makeMaze(const int rows, const int cols);
    
    // Deletes the existing maze
    void deleteMaze();

    // Updates maze with provided maze.
    void updateMaze(std::string tmp, int row, int col);

    // Updates a character in the maze at point row by col.
    void updateCharacter(int row, int col, char character);

    // Gets the value at the specified position in the maze.
    char getValue(int row, int col);

    // Gets number of rows.
    int getRows();

    // Gets number of columns.
    int getColumns();

  private: 

    // All characters in the maze.
    Maze maze;

    // Number of rows in the maze.
    int rows;

    // Number of columns in the maze
    int columns;

};

#endif