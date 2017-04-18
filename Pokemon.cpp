/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 01 Pokedex
Date Last Modified: 01/23/2017
------------------------------------------*/
#include "Pokemon.h"
//---------------------------------------------------------------------------
//Stores private variables for Executive.cpp
//---------------------------------------------------------------------------
Pokemon::Pokemon(std::string aName, std::string jName, int id)
{
    m_aName = aName;
    m_jName = jName;
    m_id = id;
}

std::string Pokemon::getaName() const
{
 return(m_aName);
}

std::string Pokemon::getjName() const
{
  return(m_jName);
}

int Pokemon::getID() const
{
  return(m_id);
}

void Pokemon::setaName(std::string aName)
{
  m_aName = aName;
}

void Pokemon::setjName(std::string jName)
{
  m_jName = jName;
}

void Pokemon::setID(int id)
{
  m_id = id;
}
