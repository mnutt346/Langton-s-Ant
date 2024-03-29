/**************************************************************************************
** Program name: RandomStartGenerator.cpp
** Author: Michael Nutt
** Date: 10/03/2019
** Description: Definitions of the selectRandomStart and generateRandomStart functions.
** The selectRandomStart function returns true if the user chooses to have a random 
** starting point generated, and returns false otherwise. The generatRandomStart
** function returns a randomly-generated integer value used as either the starting
** row or column of the ant.
**************************************************************************************/

#include "RandomStartGenerator.hpp"
#include "InputValidation.hpp"
#include <iostream>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;


/* Summary: Prompts the user to either choose the ant's position themselves or to have
 * the starting point be randomly generated
 * Param: N/A
 * Return: boolean value representing the user's choice
 */
bool selectRandomStart()
{
  int randomStartChoice;

  cout << endl;
  cout << "Would you like to:" << endl;
  cout << "1. Choose the ant's position on the board." << endl;
  cout << "2. Place the ant in a randomly-generated spot." << endl;
  cout << "Please enter 1 or 2." << endl;
  // Validate input
  randomStartChoice = convertInputToInt();
  // While the input is out of range:
  while (randomStartChoice < 1 || randomStartChoice > 2)
  {
    cout << "Invalid input." << endl;
    cout << "Please enter either 1 or 2." << endl;
    // Re-validate input
    randomStartChoice = convertInputToInt();
  }

  if (randomStartChoice == 1)
  {
    return false;
  }
  else
  {
    return true;
  }
}


/* Summary: Generates a random number from 0 to the upper bound (dimension of the board)
 * Param: int upperBound -> represents the edge of the board
 * Return: a randomly-generated integer to be used as either the starting row or column
 */
int generateRandomStart(int upperBound)
{
  int randomStart = rand() % upperBound + 0;

  return randomStart;
}    
