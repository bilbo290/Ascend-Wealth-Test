#include <iostream>
#include <string>
#include <map>

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
    int xyDirection = findIndex(orientationMap, direction);
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
  void changeDirection(char turn)
  {
    int curr = findIndex(orientationMap, direction);
    int turnValue;
    if (turn == 'R')
    {
      turnValue = 1;
    }
    else if (turn == 'L')
    {
      turnValue = -1;
    }
    int newDirectionIndex = (((curr + turnValue) % 4) + 4) % 4;
    direction = orientationMap[newDirectionIndex];
    std::cout << "New direction index :" << ((newDirectionIndex) % 4) << std::endl;
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
  int findIndex(std::string arr[], std::string key)
  {
    int n = 4;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == key)
      {
        return i;
      }
    }
  }
};

int main()
{
  std::cout << "Initiaing Rover...\n";
  std::cout << "Input map size : \n";
  int operatingRange;
  std::cin >> operatingRange;
  Rover rover(operatingRange);
  while (true)
  {

    std::cout << "1. Move forward \n2. Turn\n3. Exit \n";
    char userInput;
    std::cin >> userInput;

    switch (userInput)
    {
    case '1':
      rover.moveForward();
      break;
    case '2':
      char turn;
      std::cout << "Left for left, R for right : \n";
      std::cin >> turn;
      // std::cout << rover.direction << std::endl;
      rover.changeDirection(turn);
      break;
    case '3':
      return 0;
    }
    std::cout << rover.direction << rover.position["x"] << "," << rover.position["y"] << std::endl;
  }

  system("pause"); // <----------------------------------
}