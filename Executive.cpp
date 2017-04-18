/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 01 Pokedex
Date Last Modified: 01/23/2017
------------------------------------------*/
#include "Executive.h"
//---------------------------------------------------------------------------
//Constructor
//---------------------------------------------------------------------------
Executive::Executive(std::string fileName)
{
  inFile.open(fileName);
  inFile >> count;
  inFile.ignore();
  pklist = new Pokemon*[count];


  for(int i = 0; i < count; i++)
  {
    std::string aName = "";
    std::string jName = "";
    std::string id = "";

    std::getline(inFile, aName, ',');
    std::getline(inFile, id, ',');
    std::getline(inFile, jName);

    //Creates new objects that populate the array
    pklist[i] = new Pokemon(aName, jName, std::stoi(id));
    //std::cout << "ADDED POKEMON: " << aName << '\n'; debug
  }
}
//---------------------------------------------------------------------------
//Deconstructor
//---------------------------------------------------------------------------
Executive::~Executive()
{
  for(int i = 0; i < count; i++)
  {
    delete pklist[i];
  }
  delete[] pklist;
}

//---------------------------------------------------------------------------
//Prints the menu
//---------------------------------------------------------------------------
void Executive::menu()
{

  std::cout << "\nWelcome to the Pokedex!\n";
  std::cout << "1) Print specific Pokemon data\n";
  std::cout << "2) Print range of Pokemon based on ID\n";
  std::cout << "3) Print Japanese names to file\n";
  std::cout << "4) Print Pokemon whose name(s) begin with...\n";
  std::cout << "5) Exit\n";
  std::cout << "Enter your choice: ";
}
//---------------------------------------------------------------------------
//Prints specific Pokemon with ID from user input
//---------------------------------------------------------------------------
void Executive::printID()
{
  int id2 = 0;
  std::cout << "Enter Pokemon ID (1-151): ";
  id2 = validInt(1, 151);
  for(int i = 0; i < count; i++)
  {
    //std::cout << i << '\n'; debug
    if(id2 == pklist[i]->getID())
    {
      //std::cout << "found\n"; debug
      std::cout << "Pokemon #" << pklist[i]->getID() << ": " << pklist[i]->getaName() << " (USA), " << pklist[i]->getjName() << " (JPN)\n";
      break;
    }
  }
}
//---------------------------------------------------------------------------
//Prints Japanese names to file
//---------------------------------------------------------------------------
void Executive::printjName()
{
  std::ofstream outfile;
  std::cout << "Enter file name: ";
  std::string fileName;
  std::cin >> fileName;
  outfile.open(fileName);
  //Checks for filename, if file doesn't open it loops
  while(!outfile.is_open())
  {
    std::cout << "Enter a valid file name: ";
    std::cin.clear();
    std::cin.ignore();
    std::cin >> fileName;
    outfile.open(fileName);
  }

  for(int i = 0; i < count; i++)
  {
      outfile << pklist[i]->getjName() << "\n";
  }
  outfile.close();
}
//---------------------------------------------------------------------------
//Prints Range of Pokemon based on ID
//---------------------------------------------------------------------------
void Executive::printRange()
{
  int r1 = 0;
  int r2 = 0;
  do
  {
  std::cout << "Enter valid first value: ";
  r1 = validInt(151, 1);
}while(r1 > 151 || r1 < 1);

  do
  {
  std::cout << "Enter valid second value: ";
  r2 = validInt(1, 151);
  }while(r2 < 1 || r2 > 151);


  //Keeps input valid
  if(r2 < r1)
  {
    int temp = r1;
    r1 = r2;
    r2 = temp;
    std::cout<<std::endl;
  }
  //-----------------

  for(int i = 0; i < count; i++)
  {
    if(pklist[i]->getID() >= r1 && pklist[i]->getID() <= r2)
    {
      std::cout << "Pokemon #" << pklist[i]->getID() << ": " << pklist[i]->getaName() << " (USA), " << pklist[i]->getjName() << " (JPN)\n";
    }
  }
}
//---------------------------------------------------------------------------
//Prints all Pokemon starting with letter gathered by User
//---------------------------------------------------------------------------
void Executive::printFirst()
{
  char first = '\0';
  std::cout << "Enter the first letter of the Pokemon: ";
  first = validChar();
  for(int i = 0; i < count; i++)
  {
    if(tolower(first) == tolower(pklist[i]->getaName()[0]))
    {
      std::cout << "Pokemon #" << pklist[i]->getID() << ": " << pklist[i]->getaName() << " (USA), " << pklist[i]->getjName() << " (JPN)\n";
    }
  }
}
//---------------------------------------------------------------------------
//Checks for valid int
//---------------------------------------------------------------------------
int Executive::validInt(int low, int upper)
{
  int input = 0;
  std::cin >> input;
  while(std::cin.fail() || input < low || input > upper)
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter a valid number: ";
    std::cin >> input;
  }
  return(input);
}
//---------------------------------------------------------------------------
//Checks for valid char
//---------------------------------------------------------------------------
char Executive::validChar()
{
  char charput = 0;
  std::cin >> charput;
  std::cin.ignore(1000, '\n');
  while(std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Enter a letter: ";
    std::cin >> charput;
  }
  return(charput);
}
//---------------------------------------------------------------------------
//Runs the program
//---------------------------------------------------------------------------
void Executive::run()
{
  bool quit = false;
  int choice = 0;
  do
  {
    menu();
    choice = validInt(1, 5);
    //Choice 1 -------------------------------------------------------
    if(choice == 1)
    {
      printID();
    }
    //Choice 2 -------------------------------------------------------
    else if(choice == 2)
    {
      printRange();
    }
    //Choice 3 -------------------------------------------------------
    else if(choice == 3)
    {
      printjName();
    }
    //Choice 4 -------------------------------------------------------
    else if(choice == 4)
    {
      printFirst();
    }
    //Choice 5 -------------------------------------------------------
    else if (choice == 5)
    {
      quit = true;
    }
    //---------------------------------------------------------------
    choice = 0;
  }while(!quit);

  std::cout << "Goodbye!\n";
}
