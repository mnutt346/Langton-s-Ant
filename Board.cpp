/**************************************************************************************
** Program name: Board.cpp
** Author: Michael Nutt
** Date: 10/03/2019
** Description: Implementation of the Board class interface.
**************************************************************************************/

#include "Board.hpp"

/*
 * Board default constructor initializes the board's dimensions to 4x4, creates an Ant
 * using the Ant default constructor, sets sets randomStart to "true", and stepsAllowed
 * to 10.
 */
Board::Board(int rows, int cols, char **brdTracker)
{
  rowCount = rows;
  colCount = cols;
  boardTracker = brdTracker;
}


/*
 * Returns the number of rows on the board.
 */
int Board::getRowCount()
{
  return rowCount;
}


/*
 * Returns the number of columns on the board.
 */
int Board::getColCount()
{
  return colCount;
}


/*
 * Returns the color of the given square.
 */
char Board::getCurrentColor(int row, int col)
{
  char color = boardTracker[row][col];
  
  // Default to whitespace
  if (color != '#' && color != ' ')
  {
    color = ' ';
  }
   
  return color;
}


/*
 * Switches the color of the given square from black to white or white to black.
 */
void Board::toggleSpace(int row, int col)
{
  char currentColor = getCurrentColor(row, col);

  if (currentColor == ' ')
  {
    boardTracker[row][col] = '#';
  }
  else
  {
    boardTracker[row][col] = ' ';
  }
}


/* Determines whether a proposed move is within the bounds of the board.
 * Returns false if the move is outside the board, and returns true otherwise.
 */
bool Board::isInBounds(int row, int col)
{
  //If the row is negative (too far north)
  if (row < 0)
  {
    return false;
  }
  //If the row is greater than the bounds of the board (too far south)
  else if (row >= rowCount)
  {
    return false;
  }
  //If the column is negative (too far west)
  else if (col < 0)
  {
    return false;
  }
  //If the column is greater than the bounds of the board (too far east)
  else if (col >= colCount)
  {
    return false;
  }
  else
  {
    return true;
  }
}
