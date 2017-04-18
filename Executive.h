/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 01 Pokedex
Date Last Modified: 01/23/2017
------------------------------------------*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <fstream>
#include <string>
#include <iostream>
#include "Pokemon.h"
#include <limits>

class Executive
{
  private:
    Pokemon **pklist;
    std::ifstream inFile;
    int count;
    int validInt(int low, int high);
    char validChar();
    void menu();
    void printID();
    void printjName();
    void printRange();
    void printFirst();

  public:
    Executive(std::string fileName);
    ~Executive();
    void run();

};
#endif
