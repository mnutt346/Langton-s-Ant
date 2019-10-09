/**************************************************************************************
** Program name: Menu.cpp
** Author: Michael Nutt
** Date: 10/03/2019
** Description: Definition of the menu function.
**************************************************************************************/

#include "Menu.hpp"
#include <iostream>


using std::cin;
using std::cout;
using std::endl;
using std::string;


bool menu(string program)
{
  int selection;

  cout << "Select one of the following options by entering the number representing your selection." << endl;
  cout << "1: Start program: " << program << "." << endl;
  cout << "2: Quit." << endl;

  selection = convertInputToInt();

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


