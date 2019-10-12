/**************************************************************************************
** Program name: PrintAnt.cpp
** Author: Michael Nutt
** Date: 10/03/2019
** Description: Definition of the printAnt function. The printAnt function prints the 
** board to the screen with the ant's current position.
**************************************************************************************/

#include <iostream>
#include "PrintAnt.hpp"

using std::cout;
using std::endl;

/* Summary: Prints the board along with the current values of all spaces (' ', '*', or '#')
 * Param: Ant ant -> the ant object, used to track it's location
 * Param: Board *board -> pointer used to track the state of the board
 * Return: N/A
 */
void printAnt(Ant ant, Board *board)
{
  // Get the dimensions of the board
  int boardRows = board->getRowCount();
  int boardCols = board->getColCount();

  // Get the current location of the ant
  int antCurrentRow = ant.getCurrentRow();
  int antCurrentCol = ant.getCurrentCol();

  // For each space on the board:
  // Includes 2 extra iterations in each loop to account for the border
  for (int i = -1; i <= boardRows; i++)
  {
    for (int j = -1; j <= boardCols; j++)
    {
      // Print the upper border
      if (i == -1)
      {
        cout << '-';
      }
      // Print the lower border
      else if (i == boardRows)
      {
        cout << '-';
      }
      // Print the left border
      else if (j == -1)
      {
        cout << '|';
      }
      // Print the right border
      else if (j == boardCols)
      {
        cout << '|';
      }
      // If the current space contains the ant
      else if (i == antCurrentRow && j == antCurrentCol)
      {
        // Print the ant
        cout << '*';
      }
      else
      {
        // Print the color of the current space
        cout << (board->getCurrentColor(i, j));
      }
    }
    // Start new row
    cout << endl;
  }
}

