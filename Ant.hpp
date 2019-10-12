/**************************************************************************************
** Program name: Ant.hpp
** Author: Michael Nutt
** Date: 10/03/2019
** Description: Interface for the Ant class. The Ant class is used to track the ant's 
** position and direction on the board, and to move/rotate the ant.
**************************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "Board.hpp"

class Ant
{
private:
  int currentRow;
  int currentCol;
  char direction;
  Board *board;

public: 
  Ant(int, int, Board*);
  int getCurrentRow();
  int getCurrentCol();
  void turnOnWhite();
  void turnOnBlack();
  void moveAnt(int, int);
  void reverseDirection();
};

#endif
