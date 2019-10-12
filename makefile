###
### @file - project1_makefile
### @author - Michael Nutt <nuttm@oregonstate.edu>
### @description - makefile for Project 1 - Langton's Ant

#
# LangtonAnt
#

CXX = g++

CFLAGS = -std=c++11

.PHONY: clean

LangtonAnt: LangtonAnt.o Ant.o Board.o Menu.o InputValidation.o PrintAnt.o RandomStartGenerator.o
	$(CXX) $(CFLAGS) -g LangtonAnt.o Ant.o Board.o Menu.o InputValidation.o PrintAnt.o RandomStartGenerator.o -o LangtonAnt

LangtonAnt.o: LangtonAnt.cpp
	$(CXX) $(CFLAGS) -c LangtonAnt.cpp

Ant.o: Ant.cpp Ant.hpp
	$(CXX) $(CFLAGS) -c Ant.cpp

Board.o: Board.cpp Board.hpp
	$(CXX) $(CFLAGS) -c Board.cpp

Menu.o: Menu.cpp Menu.hpp
	$(CXX) $(CFLAGS) -c Menu.cpp

InputValidation.o: InputValidation.cpp InputValidation.hpp
	$(CXX) $(CFLAGS) -c InputValidation.cpp

PrintAnt.o: PrintAnt.cpp PrintAnt.hpp
	$(CXX) $(CFLAGS) -c PrintAnt.cpp

RandomStartGenerator: RandomStartGenerator.cpp RandomStartGenerator.hpp
	$(CXX) $(CFLAGS) -c RandomStartGenerator.cpp
	
clean:
	rm *.o LangtonAnt

