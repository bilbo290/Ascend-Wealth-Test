#pragma once
#include<iostream>
#include<string>
#include<map>
class Rover
{
public:
    std::string direction;
    std::map<std::string, int> position;
    std::string orientationMap[4] = {"N","E","S","W"};
    std::map<std::string, int> range;
    Rover(int);
    void moveForward();
    void changeDirection(std::string );
    bool checkInRange(std::string, int);
    int findDirectionIndex(std::string arr[], std::string key);
};


