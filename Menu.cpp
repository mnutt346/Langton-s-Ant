/**************************************************************************************
** Program name: Menu.cpp
** Author: Michael Nutt
** Date: 10/03/2019
** Description: Definition of the menu function. The menu function prompts the user to
** select one of two options: 1. Start the program, or 2. Quit the program. It returns
** true if the user chooses to start the program, and returns false otherwise.
**************************************************************************************/

#include "Menu.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


/* Summary: Prompts the user to either start the program or quit
 * Param: string program -> represents the title of the program; used to inform the user
 * as to which program they are starting
 * Return: boolean value representing the user's decision (true = start the program, false = quit)
 */
bool menu(string program)
{
  int selection;

  cout << "Select one of the following options by entering the number representing your selection." << endl;
  cout << "1: Start program: " << program << "." << endl;
  cout << "2: Quit." << endl;

  // Validate input
  selection = convertInputToInt();

  // While the user enter's input other than 1 or 2:
  while (selection != 1 && selection != 2)
  {
    cout << "Invalid input. Please enter either 1 or 2." << endl;
    selection = convertInputToInt();
  }

  if (selection == 1)
  {
    return true;
  }
  else 
  {
    return false;
  }
}   


