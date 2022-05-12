#include <iostream>
#include <string>
#include <map>
#include <cstdio>

class Rover
{
public:
  std::string direction;
  std::map<std::string, int> position;
  Rover(int operatingRange)
  {
    direction = "N";
    position = {{"x", 0}, {"y", 0}};
  }
  void moveForward()
  {
  }
  void changeDirection()
  {
  }
  void checkInRange()
  {
  }
};

int main()
{
  std::cout << "Initiaing Rover...\n";
  std::cout << "Input map size : \n";
  int operatingRange;
  std::cin >> operatingRange;
  Rover rover(operatingRange);
  std::cout << rover.direction << rover.position["x"] << "," << rover.position["y"] << std::endl;
  system("pause"); // <----------------------------------
}