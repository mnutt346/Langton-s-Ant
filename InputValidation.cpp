/**************************************************************************************
** Program name: InputValidation.cpp
** Author: Michael Nutt
** Date: 10/03/2019
** Description: Definitions of the checkIntegerInput and isIntegerInput functions.
** The checkIntegerInput function gets the input from the user and determines wheter
** that input is a positive integer. If not, the function continues to loop until the
** user submits a positive integer.
**************************************************************************************/
#include "InputValidation.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::atoi;
using std::string;


bool isIntegerInput(string input)
{
  for (int i = 0; i < input.size(); i++)
  {
    if (!isdigit(input[i]))
    {
      return false;
    }
  }

  return true;
}


int convertInputToInt()
{
  string input;
  
  int integerInput;  

  do
  {     
    getline(cin, input);
    
    // Iterate through input string and remove whitespace.
    for (int i = 0; i < input.length(); i++)
    {
      if(input[i] == ' ')
      {
        input.erase(i, 1);
      }
    }
    
    if (!isIntegerInput(input))
    {
      cout << "Invalid input. Please enter inputs as positive integers." << endl;
    }
  }
  while (!isIntegerInput(input));

  integerInput = atoi(input.c_str());

  return integerInput;
}



