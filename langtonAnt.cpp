/**************************************************************************************
** Program name: determinant.hpp
** Author: Michael Nutt
** Date: 10/03/2019
** Description: Implemetation of the main() function for the Langton's Ant program.
**************************************************************************************/
#include <iostream>
#include "Menu.hpp"
#include "RandomStartGenerator.hpp"
#include "Ant.hpp"
#include "Board.hpp"
#include "PrintAnt.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{
  const string TITLE = "Langton's Ant";

  int programSelection = menu(TITLE);
  
  // While the user chooses to enter the simulation:
  while (programSelection)
  {
    
    int rowCount; //user-determined number of rows on the board
    int colCount; //user-determined number of columns on the board
    int totalSteps; //user-determined number of steps the ant will take
    int currentRow; //tracks the current row of the ant
    int currentCol; //tracks the current column of the ant
    int currentStep = 0; //tracks the ants total steps taken

    // Prompt user to select number of rows
    cout << endl;
    cout << "Please enter a positive integer between 2 and 100, inclusive." << endl;
    cout << "This number will represent the number of rows on the board." << endl;
    
    // Validate input for rows
    rowCount = convertInputToInt();
    
    // While the input is out of range:
    while(rowCount < 2 || rowCount > 100)
    {
      cout << "Invalid input." << endl;
      cout << "Please enter a positive integer between 2 and 100, inclusive." << endl;
      // Re-validate new input
      rowCount = convertInputToInt();
    }
    
    // Prompt user to select number of columns
    cout << endl;
    cout << "Now, please enter a positive integer between 2 and 100, inclusive." << endl;
    cout << "This number will represent the number of columns on the board." << endl;
    
    // Validate input for columns
    colCount = convertInputToInt();

    // While input is out of range:
    while(colCount < 2 || colCount > 100)
    {
      cout << "Invalid input." << endl;
      cout << "Please enter a positive integer between 2 and 100, inclusive." << endl;
      // Re-validate new input
      colCount = convertInputToInt();
    }

    // If the user wants to use a random starting point:
    if (selectRandomStart())
    {
      // Generate a random starting column     
      currentRow = generateRandomStart((rowCount - 1));
      // Generate a random starting row
      currentCol = generateRandomStart((colCount - 1));
    }
    // Otherwise, prompt the user to select a sarting point
    else
    {
      // Select the starting row
      cout << endl;
      cout << "Please select the starting row of the ant by entering an integer between 0 and " << colCount - 1 << "." << endl;
      // Validate input
      currentRow = convertInputToInt();
      // While the input is out of range:
      while (currentRow < 0 || currentRow >= rowCount)
      {
        cout << "Invalid input." << endl;
        cout << "Please enter an integer between 0 and " << rowCount - 1 << "." << endl; 
        // Re-validate input
        currentRow = convertInputToInt();
      }
      
      // Select the starting column
      cout << endl;
      cout <<  "Please select the starting column of the ant by entering an integer between 0 and " << rowCount - 1 << "." << endl;
      // Validate input
      currentCol = convertInputToInt();
      // While the input is out of range:
      while (currentCol < 0 || currentCol >= colCount)
      {
        cout << "Invalid input." << endl;
        cout << "Please enter an integer between 0 and " << colCount - 1 << "." << endl; 
        // Re-validate input
        currentCol = convertInputToInt();
      }
    }

    
    // Prompt the user to select the total number of steps in the simulation
    cout << endl;
    cout << "Please enter and integer between 1 and 200, inclusive" << endl;
    cout << "This will determine the number of steps the simulation will take." << endl;
    // Validate input
    totalSteps = convertInputToInt();
    // While the input is out of range:
    while (totalSteps < 1 || totalSteps > 200)
    {
      cout << "Invalid input." << endl;
      cout << "Please enter an integer between 1 and 200." << endl;
      // Re-validate input
      totalSteps = convertInputToInt();
    }


    // Generate a 2D array to track the state of the board
    char **tracker = new char *[rowCount];
    for (int i = 0; i < rowCount; i++)
    {
      tracker[i] = new char [colCount];
    }

    // Generate Board object using rowCount, colCount, and the 2D array
    Board *board = new Board(rowCount, colCount, tracker);

    // Generate Ant object using currentRow and currentCol as its starting point, and the board object
    // to allow the ant to track its state
    Ant ant(currentRow, currentCol, board);    
 
    // While the ant has not completed the simulation
    while (currentStep < totalSteps)
    {
      // Increment currentStep
      currentStep++;
        
      //Store the ant's current location to use as reference after it moves
      int prevRow = ant.getCurrentRow();
      int prevCol = ant.getCurrentCol();
     
      printAnt(ant, board);

      ant.moveAnt(prevRow, prevCol); 

      int nextRow = ant.getCurrentRow();
      int nextCol = ant.getCurrentCol();
      
      cout << "Please press enter to continue." << endl;
      cin.get(); 
    } 

    // Deallocate memory used by the 2D array
    for (int i = 0; i < rowCount; i++)
    {
      delete[] tracker[i];
    }
    delete[] tracker;

    // Provide the user with the option to run the simulation again, or quit
    programSelection = menu(TITLE);
  }


  if (!programSelection)
  {
    return 0;
  }
}
  

