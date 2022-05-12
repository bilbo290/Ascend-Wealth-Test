#include <iostream>
#include <string>
#include <map>

class Rover
{
public:
  char direction;
  std::map<char, int> position;
  char orientationMap[4] = {'N', 'E', 'S', 'W'};
  Rover(int operatingRange)
  {
    direction = 'N';
    position = {{'x', 0}, {'y', 0}};
  }
  void moveForward()
  {
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
  void checkInRange()
  {
  }
  int findIndex(char arr[], char key)
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
    std::cout << rover.direction << rover.position['x'] << "," << rover.position['y'] << std::endl;
  }

  system("pause"); // <----------------------------------
}