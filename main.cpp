#include <iostream>
#include <string>
#include <map>
#include <fstream>

class Rover
{
public:
  std::string direction;
  std::map<std::string, int> position;
  std::string orientationMap[4] = {"N", "E", "S", "W"};
  std::map<std::string, int> range;
  Rover(int operatingRange)
  {
    direction = 'N';
    position = {{"x", 0}, {"y", 0}};
    range = {{"x", operatingRange}, {"y", operatingRange}};
  }
  void moveForward()
  {
    int xyDirection = findDirectionIndex(orientationMap, direction);
    std::string toMove;
    int toMoveSign;
    if (xyDirection % 2)
    {
      toMove = "x";
      if (xyDirection == 1)
      {
        toMoveSign = 1;
      }
      else
      {
        toMoveSign = -1;
      }
    }
    else
    {
      toMove = "y";
      if (xyDirection == 0)
      {
        toMoveSign = 1;
      }
      else
      {
        toMoveSign = -1;
      }
    }
    if (checkInRange(toMove, toMoveSign))
    {
      position[toMove] = position[toMove] + toMoveSign;
    }
  }
  void changeDirection(std::string turn)
  {
    int curr = findDirectionIndex(orientationMap, direction);
    int turnValue;
    if (turn == "R")
    {
      turnValue = 1;
    }
    else if (turn == "L")
    {
      turnValue = -1;
    }
    int newDirectionIndex = (((curr + turnValue) % 4) + 4) % 4;
    direction = orientationMap[newDirectionIndex];
    // std::cout << "New direction index :" << ((newDirectionIndex) % 4) << std::endl;
  }
  bool checkInRange(std::string toMove, int toMoveSign)
  {
    if (toMoveSign == 1)
    {
      if (position[toMove] + toMoveSign > range[toMove])
      {
        return false;
      }
    }
    else
    {
      if (position[toMove] + toMoveSign < 0)
      {
        return false;
      }
    }
    return true;
  }
  int findDirectionIndex(std::string arr[], std::string key)
  {
    int n = 4;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == key)
      {
        return i;
      }
    }
    return -1;
  }
};

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

        if (userInput == "F")
        {
          rover.moveForward();
        }
        else if (userInput == "L" || userInput == "R")
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
