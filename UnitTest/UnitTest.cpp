#include "pch.h"
#include "CppUnitTest.h"
#include "Rover.h"
#include "Rover.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMapSize)
		{
			int mapSize = 20;
			Rover rover(mapSize);
			Assert::AreEqual(mapSize, rover.range["x"]);
			Assert::AreEqual(mapSize, rover.range["y"]);
		}
		TEST_METHOD(TestInitialDirection)
		{
			int mapSize = 1;
			Rover rover(mapSize);
			std::string intialDirection = "N";
			Assert::AreEqual(intialDirection, rover.direction);
		}
		TEST_METHOD(TestMoveForwardPositiveY) {
			std::string input = "F";
			int mapSize = 1;
			Rover rover(mapSize);
			int expectedYposition = rover.position["y"] + 1;
			rover.moveForward();
			Assert::AreEqual(expectedYposition, rover.position["y"]);
		}
		TEST_METHOD(TestMoveForwardOutOfRangePositiveY) {
			std::string input = "F";
			int mapSize = 1;
			Rover rover(mapSize);
			int expectedYposition = rover.position["y"]+1;
			rover.moveForward();
			rover.moveForward();
			Assert::AreEqual(expectedYposition, rover.position["y"]);
		}
		TEST_METHOD(TestRotateLeftOneTime) {
			std::string input = "L";
			int mapSize = 1;
			Rover rover(mapSize);
			std::string expectedDirection = "W";
			rover.changeDirection(input);
			Assert::AreEqual(expectedDirection, rover.direction);
		}
		TEST_METHOD(TestRotateRightOneTime) {
			std::string input = "R";
			int mapSize = 1;
			Rover rover(mapSize);
			std::string expectedDirection = "E";
			rover.changeDirection(input);
			Assert::AreEqual(expectedDirection, rover.direction);
		}

		TEST_METHOD(TestFullRotate360Right) {
			std::string input[4] = { "R","R","R","R" };
			int mapSize = 1;
			Rover rover(mapSize);
			std::string expected[4] = { "E","S","W","N" };
			for (int i = 0; i < 4; i++) {
				rover.changeDirection(input[i]);
				Assert::AreEqual(expected[i], rover.direction);
			}
		}
		TEST_METHOD(TestFullRotate360Left) {
			std::string input[4] = { "L","L","L","L" };
			std::string expected[4] = { "W","S","E","N" };
			int mapSize = 1;
			Rover rover(mapSize);
			for (int i = 0; i < 4; i++) {
				rover.changeDirection(input[i]);
				Assert::AreEqual(expected[i], rover.direction);
			}
		}
		TEST_METHOD(TestMoveForwardInAllDirection) {
			// Move in rectangle motion, should be back to the initial position facing north again.
			std::string input[8] = { "F","R","F","R","F","R","F","R"};
			int mapSize = 1;
			Rover rover(mapSize);
			int expectedXPosition = 0;
			int expectedYPosition = 0;
			std::string expectedDirection = "N";
			for (int i = 0; i < 8; i++) {
				if (input[i] == "F") {
					rover.moveForward();
				}
				else {
					rover.changeDirection(input[i]);
				}
			}
			Assert::AreEqual(expectedXPosition, rover.position["x"]);
			Assert::AreEqual(expectedYPosition, rover.position["y"]);
			Assert::AreEqual(expectedDirection, rover.direction);
		}
	};
}
