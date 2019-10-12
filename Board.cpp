/**************************************************************************************
** Program name: Board.cpp
** Author: Michael Nutt
** Date: 10/03/2019
** Description: Implementation of the Board class interface.
**************************************************************************************/

#include "Board.hpp"

/*
 * Summary: Board default constructor initializes the dimensions of the board to those
 * specified by the user, and initializes a pointer to the 2D array which tracks the
 * state of the board.
 * Param: int rows -> defines the number of rows on the board
 * Param: int cols -> defines the number of columns on the board
 * Param: char **brdTracker -> pointer to the 2D array that stores the state of the board
 * Return: N/A
 */
Board::Board(int rows, int cols, char **brdTracker)
{
  rowCount = rows;
  colCount = cols;
  boardTracker = brdTracker;
}


/*
 * Summary: Returns the number of rows on the board.
 * Param: N/A
 * Return: The number of rows on the board as an int.
 */
int Board::getRowCount()
{
  return rowCount;
}


/*
 * Summary: Returns the number of columns on the board.
 * Param: N/A
 * Return: The number of columns on the board as an int.
 */
int Board::getColCount()
{
  return colCount;
}


/*
 * Summary: Returns the color of the given square.
 * Param: int row -> represents the row of the space being checked
 * Param: int col -> represents the column of the space being checked
 * Return: The color of the space being checked as a char.
 */
char Board::getCurrentColor(int row, int col)
{
  char color = boardTracker[row][col];
  
  // Default to whitespace if no color is present. Used when initializing the empty board.
  if (color != '#' && color != ' ')
  {
    color = ' ';
  }
   
  return color;
}


/*
 * Summary: Switches the color of the given square from black to white or white to black.
 * Param: int row -> represents the row of the space being toggled
 * Param: int col -> represents the column of the space being toggled
 * Return: N/A
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


/* Summary: Determines whether a proposed move is within the bounds of the board.
 * Returns false if the move is outside the board, and returns true otherwise.
 * Param: int row -> represents the row of the space the ant is moving to
 * Param: int col -> represents the column of the space the ant is moving to
 * Return: A boolean value determining wheter the move is valid
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
