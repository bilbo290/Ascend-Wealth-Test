#include "Rover.h"

Rover::Rover(int operatingRange)
{
    direction = 'N';
    position = { {"x", 0}, {"y", 0} };
    range = { {"x", operatingRange}, {"y", operatingRange} };
}
void Rover::moveForward()
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
void Rover::changeDirection(std::string turn)
{
    int curr = findDirectionIndex(orientationMap, direction);
    int turnValue = 0;
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
bool Rover::checkInRange(std::string toMove, int toMoveSign)
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
int Rover::findDirectionIndex(std::string arr[], std::string key)
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
