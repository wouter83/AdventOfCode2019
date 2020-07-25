#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrossedWires.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CrossedWireTest
{
	TEST_CLASS(CrossedWireTest)
	{
	public:

		TEST_METHOD(loadWire)
		{
			std::string wire1 = "R8,U5,L5,D3";
			std::string wire2 = "U7,R6,D4,L4";
			CrossedWires wire;
			wire.LoadWires(wire1, wire2);
		}

		TEST_METHOD(addWire)
		{
			std::string wire1 = "R8,U5,L5,D3";
			std::string wire2 = "U7,R6,D4,L4";
			CrossedWires wire;
			wire.LoadWires(wire1, wire2);
			
			int closedCross = 0;
			int shortestCross = 0;
			wire.RunWires(closedCross, shortestCross);
			Assert::AreEqual(6, closedCross);
			Assert::AreEqual(30, shortestCross);

		}
		
		TEST_METHOD(addWire2)
		{
			std::string wire1 = "R3,D2,L5";
			std::string wire2 = "U1,L1,D4";

			CrossedWires wire;

			wire.LoadWires(wire1, wire2);

			int closedCross = 0;
			int shortestCross = 0;
			wire.RunWires(closedCross, shortestCross);

			Assert::AreEqual(3, closedCross);

		}

		TEST_METHOD(addWire2a)
		{
			std::string wire1 = "R2,D2,L4,U4"; 
			std::string wire2 = "U3,L3,D1,R1";

			CrossedWires wire;

			wire.LoadWires(wire1, wire2);

			int closedCross = 0;
			int shortestCross = 0;
			wire.RunWires(closedCross, shortestCross);
			Assert::AreEqual(4, closedCross);

		}
		TEST_METHOD(addWire3)
		{
			std::string wire1 = "R75,D30,R83,U83,L12,D49,R71,U7,L72"; // col = 134, row = 
			std::string wire2 = "U62,R66,U55,R34,D71,R55,D58,R83";
			CrossedWires wire;

			wire.LoadWires(wire1, wire2);

			int closedCross = 0;
			int shortestCross = 0;
			wire.RunWires(closedCross, shortestCross);
			Assert::AreEqual(159, closedCross);
			Assert::AreEqual(610, shortestCross);
		}
		TEST_METHOD(addWire4)
		{
			std::string wire1 = "R98,U47,R26,D63,R33,U87,L62,D20,R33,U53,R51";
			std::string wire2 = "U98,R91,D20,R16,D67,R40,U7,R15,U6,R7";
			CrossedWires wire;
			wire.LoadWires(wire1, wire2);

			int closedCross = 0;
			int shortestCross = 0;
			wire.RunWires(closedCross, shortestCross);
			Assert::AreEqual(135, closedCross);
			Assert::AreEqual(410, shortestCross);
		}
	};
}