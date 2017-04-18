/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 01 Pokedex
Date Last Modified: 01/23/2017
------------------------------------------*/

#include "Executive.h"
#include <iostream>

//---------------------------------------------------------------------------
//Checks for valid user input in terminal then runs Executive.h
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
    Executive exec(argv[1]);
    exec.run();
  }
  return(0);
}
