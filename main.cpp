#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "Rover.h"
int main()
{
  while (true)
  {

    std::cout << "Input file [i], enter CLI mode [c], or exit [e]" << std::endl;
    std::string inputType;
    std::cin >> inputType;
    if (inputType == "i" || inputType == "I")
    {
      std::string line;
      std::string fileName;
      std::cout << "Input file name with extension \n";
      std::cin >> fileName;
      std::ifstream myfile(fileName);
      if (myfile.is_open())
      {
        std::getline(myfile, line);
        int operatingRange = stoi(line);
        Rover rover(operatingRange);
        while (std::getline(myfile, line))
        {
          if (line == "F")
          {
            rover.moveForward();
          }
          else if (line == "L" || "R")
          {
            rover.changeDirection(line);
          }
          else
          {
            std::cout << "Invalid input, skip to next line \n";
            continue;
          }
          std::cout << "Input : " << line << " -> " << rover.direction << rover.position["x"] << "," << rover.position["y"] << std::endl;
        }
        myfile.close();
      }

      else
      {
        std::cout << "Unable to open file";
        system("pause");
        return 0;
      }
    }
    else if (inputType == "c" || inputType == "C")

    {
      std::cout << "Initiaing Rover...\n";
      std::cout << "Input map size : \n";
      int operatingRange;
      std::cin >> operatingRange;
      Rover rover(operatingRange);
      while (true)
      {
        std::cout << "Move forward [F], Turn [L,R], Exit [e] \n";
        std::string userInput;
        std::cin >> userInput;

        if (userInput == "F" || userInput == "f")
        {
          rover.moveForward();
        }
        else if (userInput == "L" || userInput == "R" || userInput == "l" || userInput == "r")
        {
          rover.changeDirection(userInput);
        }
        else if (userInput == "e" || "E")
        {
          return 0;
        }
        else
        {
          std::cout << "Wrong input \n";
          continue;
        }
        std::cout << rover.direction << rover.position["x"] << "," << rover.position["y"] << std::endl;
      }
    }
    else if (inputType == "e" || inputType == "E")
    {
      return 0;
    }
    else
    {
      std::cout << "Invalid input \n";
      continue;
    }
  }
}
