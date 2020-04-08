
#include <string>
#include <iostream>

#include "../headers/milestone4.h"

MazeManager::MazeManager():
  maze(nullptr),
  rows(0),
  columns(0)
{}  

MazeManager::MazeManager(int rows, int columns):
  maze(nullptr),
  rows(rows),
  columns(columns)
{}    

MazeManager::~MazeManager() {
  deleteMaze();
}

void MazeManager::makeMaze(int rows, int cols) {
  deleteMaze();
  this->rows = rows;
  this->columns = cols;

  if (rows >= 0 && cols >= 0) {
    maze = new char*[rows];
    for (int i = 0; i != rows; ++i) {
      maze[i] = new char[cols];
    }
  }

}

void MazeManager::deleteMaze() {
  if (rows >= 0 && columns >= 0) {
    for (int i = 0; i != rows; ++i) {
      delete maze[i];
    }
    delete maze;
    maze = nullptr;
  }
}

void MazeManager::updateMaze(std::string tmp, int row, int col) {
  deleteMaze();
  makeMaze(row, col);
  
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      this->maze[i][j] = tmp[i * col + j];
    }
  }
}

void MazeManager::updateCharacter(int row, int col, char character) {
  bool validRow = row <= rows && row >= 0;
  bool validCol = col <= columns && col >= 0;
  
  if (validRow && validCol) {
    maze[row][col] = character;
  }
}

char MazeManager::getValue(int row, int col) {
  char character = ' ';
  
  bool validRow = row <= rows && row >= 0;
  bool validCol = col <= columns && col >= 0;
  
  if (validRow && validCol) {
    character = maze[row][col];
  }

  return character;
}

int MazeManager::getRows() {
  return rows;
}

int MazeManager::getColumns() {
  return columns;
}
