/**************************************************************************************
** Program name: Ant.cpp
** Author: Michael Nutt
** Date: 10/03/2019
** Description: Implementation of the Ant class interface.  
**************************************************************************************/
#include <string>
#include "Ant.hpp"


/*
 * Summary: Ant constructor initializes the Ant's starting position, provides a reference to
 * the board object, and sets the initial direction to east.
 * Param: int row -> defines the current row on which the ant currently sits
 * Param: int col -> defines the current column on which the ant currently sits
 * Returns: N/A   
 */
Ant::Ant(int row, int col, Board *brd)
{
  currentRow = row;
  currentCol = col;
  direction = 'E';
  board = brd;
}


/*
 * Summary: The getCurrentRow method returns the row on which the ant currently sits. To be
 * used when checking if a proposed move is valid.
 * Param: N/A
 * Returns: int representing the row on which the ant currently sits
 */
int Ant::getCurrentRow()
{
  return currentRow;
}


/*
 * Summary: The getCurrentCol method returns the column on which the ant currently sits. To be
 * used when checking if a proposed move is valid.
 * Param: N/A
 * Returns: int representing the column on which the ant currently sits
 */
int Ant::getCurrentCol()
{
  return currentCol;
}


/*
 * Summary: The turnOnBlack method turns the ant 90 degrees to the left when the ant is on a
 * black square.
 * Param: N/A
 * Returns: N/A
 */
void Ant::turnOnBlack()
{
  switch (direction)
  {
  case 'N':
    direction = 'W';
    break;
  case 'E':
    direction = 'N';
    break;
  case 'S':
    direction = 'E';
    break;
  case 'W':
    direction = 'S';
    break;
  }
}


/*
 * Summary: The turnOnWhite method turns the and 90 degrees to the right when the and is on a
 * white square.
 * Param: N/A
 * Returns: N/A
 */
void Ant::turnOnWhite()
{
  switch (direction)
  {
  case 'N':
    direction = 'E';
    break;
  case 'E':
    direction = 'S';
    break;
  case 'S':
    direction = 'W';
    break;
  case 'W':
    direction = 'N';
    break;
  }
}


/*
 * Summary: The moveAnt method moves the ant one space after changing direction based on the
 * color of the square in which it currently sits. 
 * Param: int row -> passes the row on which the ant currently sits
 * Param: int col -> passes the column on which the ant currently sits
 * Return: N/A
 */
void Ant::moveAnt(int row, int col)
{
  // If the ant is on a white space:
  if (board->getCurrentColor(row, col) == ' ')
  {
    turnOnWhite();
  }
  // If the ant is on a black space:
  else 
  {
    turnOnBlack();
  }
  
  // Change the color of the curret space before moving.
  board->toggleSpace(row, col);  

  switch (direction)
  {
  // Facing north, move one row up
  case 'N':
    currentRow--;
    break;
  // Facing east, move one column right
  case 'E':
    currentCol++;
    break;
  // Facing south, move one row down
  case 'S':
    currentRow++;
    break;
  // Facing west, move one row left
  case 'W':
    currentCol--;
    break;
  }

  
  // Check if the ant is moving out of bounds
  if (!board->isInBounds(currentRow, currentCol))
  {
    // Reset the ant to its previous position
    currentRow = row;
    currentCol = col;
    // Reverse the ant's direction
    reverseDirection();
  }
}


/*
 * Summary: The reverseDirection method rotates the ant 180 degrees and moves the ant 
 * one space in the new direction. To be used if the ant's next move will be invalid.
 * Param: N/A
 * Return: N/A
 */
void Ant::reverseDirection()
{
  switch (direction)
  {
  case 'N':
    direction = 'S';
    currentRow++;
    break;
  case 'E':
    direction = 'W';
    currentCol--;
    break;
  case 'S':
    direction = 'N';
    currentRow--;
    break;
  case 'W':
    direction = 'E';
    currentCol++;
    break;
  }
}
