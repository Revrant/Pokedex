/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 01 Pokedex
Date Last Modified: 01/23/2017
------------------------------------------*/
#ifndef POKEMON_H
#define POKEMON_H
#include <string>

class Pokemon
{
  private:
    std::string m_aName;
    std::string m_jName;
    int m_id;
  public:
    Pokemon(std::string aName, std::string jName, int id);
    std::string getaName() const;
    std::string getjName() const;
    int getID() const;
    void setjName(std::string jName);
    void setaName(std::string aName);
    void setID(int id);
};
#endif
