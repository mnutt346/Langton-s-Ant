/**************************************************************************************
** Program name: Board.hpp
** Author: Michael Nutt
** Date: 10/03/2019
** Description: Interface for the Board class. The Board class is used to create the 
** board and track the current state of the board (which spaces are black and which
** are white). The Board class is also used to determine if a proposed move of the ant
** will remain in-bounds.
**************************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP


class Board
{
private:
  int rowCount;
  int colCount;
  char **boardTracker;

public:
  Board(int, int, char**);
  int getRowCount();
  int getColCount();
  char getCurrentColor(int, int); 
  void toggleSpace(int, int);
  bool isInBounds(int, int);
};

#endif
