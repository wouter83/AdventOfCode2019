#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrossedWires.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CrossedWireTest
{
	TEST_CLASS(CrossedWireTest)
	{
	public:
		TEST_METHOD(Init)
		{
			CrossedWires wire;
			std::vector<std::vector<char>> grid = wire.GetGrid();
			Assert::AreEqual(static_cast<size_t>(1), grid.size()); // 1 row
			Assert::AreEqual(static_cast<size_t>(1), grid[0].size()); // 1 column
			Assert::AreEqual('0', grid[0][0]); // 1 column
		}
		TEST_METHOD(addColumns)
		{
			CrossedWires wire;
			wire.AddColumn(3);
			std::vector<std::vector<char>> grid = wire.GetGrid();
			Assert::AreEqual(static_cast<size_t>(1), grid.size()); // 1 row
			Assert::AreEqual(static_cast<size_t>(4), grid[0].size()); // 1 + 3 columns


			for (std::vector< std::vector<char> >::iterator it = grid.begin(); it != grid.end(); ++it) {
				for (std::vector<char>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
					Assert::AreEqual('0', (*it2));
				}
			}
		}
		TEST_METHOD(addRows)
		{
			CrossedWires wire;
			wire.AddColumn(3);
			wire.AddRow(4);

			std::vector<std::vector<char>> grid = wire.GetGrid();
			Assert::AreEqual(static_cast<size_t>(5), grid.size()); // 1 + 4 row
			Assert::AreEqual(static_cast<size_t>(4), grid[0].size()); // 1 + 3 columns


			for (std::vector< std::vector<char> >::iterator it = grid.begin(); it != grid.end(); ++it) {
				for (std::vector<char>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
					Assert::AreEqual('0', (*it2));
				}
			}
		}
		TEST_METHOD(addWire)
		{
			std::string wire1 = "R8,U5,L5,D3";
			std::string wire2 = "U7,R6,D4,L4";
			CrossedWires wire;
			wire.AddWire(wire1, 'a');
			wire.AddWire(wire2, 'b');

			std::vector<std::vector<char>> grid = wire.GetGrid();
			Assert::AreEqual('O', grid[0][0]); // 0,0 = '0'
			Assert::AreEqual('a', grid[0][1]);
			Assert::AreEqual('a', grid[0][2]);
			Assert::AreEqual('a', grid[0][3]);
			Assert::AreEqual('a', grid[0][4]);
			Assert::AreEqual('a', grid[0][5]);
			Assert::AreEqual('a', grid[0][6]);
			Assert::AreEqual('a', grid[0][7]);
			Assert::AreEqual('a', grid[0][8]);
			Assert::AreEqual('a', grid[1][8]);
			Assert::AreEqual('a', grid[2][8]);
			Assert::AreEqual('a', grid[3][8]);
			Assert::AreEqual('a', grid[4][8]);
			Assert::AreEqual('a', grid[5][8]);
			Assert::AreEqual('a', grid[5][7]);
			Assert::AreEqual('X', grid[5][6]);
			Assert::AreEqual('a', grid[5][5]);
			Assert::AreEqual('a', grid[5][4]);
			Assert::AreEqual('a', grid[5][3]);
			Assert::AreEqual('a', grid[4][3]);
			Assert::AreEqual('X', grid[3][3]);
			Assert::AreEqual('a', grid[2][3]);
			
			//std::string wire2 = "U7,R6,D4,L4";
			//
			Assert::AreEqual('b', grid[1][0]); // 0,0 = '0'
			Assert::AreEqual('b', grid[2][0]); // 0,0 = '0'
			Assert::AreEqual('b', grid[3][0]); // 0,0 = '0'
			Assert::AreEqual('b', grid[4][0]); // 0,0 = '0'
			Assert::AreEqual('b', grid[5][0]); // 0,0 = '0'
			Assert::AreEqual('b', grid[6][0]); // 0,0 = '0'
			Assert::AreEqual('b', grid[7][0]); // 0,0 = '0'
			Assert::AreEqual('b', grid[7][1]); // 0,0 = '0'
			Assert::AreEqual('b', grid[7][2]); // 0,0 = '0'
			Assert::AreEqual('b', grid[7][3]); // 0,0 = '0'
			Assert::AreEqual('b', grid[7][4]); // 0,0 = '0'
			Assert::AreEqual('b', grid[7][5]); // 0,0 = '0'
			Assert::AreEqual('b', grid[7][6]); // 0,0 = '0'
			Assert::AreEqual('b', grid[6][6]); // 0,0 = '0'
			Assert::AreEqual('X', grid[5][6]); // 0,0 = '0'
			Assert::AreEqual('b', grid[4][6]); // 0,0 = '0'
			Assert::AreEqual('b', grid[3][6]); // 0,0 = '0'
			Assert::AreEqual('b', grid[3][5]); // 0,0 = '0'
			Assert::AreEqual('b', grid[3][4]); // 0,0 = '0'
			Assert::AreEqual('X', grid[3][3]); // 0,0 = '0'
			Assert::AreEqual('b', grid[3][2]); // 0,0 = '0'

			Assert::AreEqual(6, wire.LengthClosedCrossed());
		}
		
		TEST_METHOD(addWire2)
		{
			std::string wire1 = "R75,D30,R83,U83,L12,D49,R71,U7,L72";
			std::string wire2 = "U62,R66,U55,R34,D71,R55,D58,R83";
			CrossedWires wire;
			wire.AddWire(wire1, 'a');
			wire.AddWire(wire2, 'b');

			Assert::AreEqual(159, wire.LengthClosedCrossed());
		}
		TEST_METHOD(addWire3)
		{
			std::string wire1 = "R98,U47,R26,D63,R33,U87,L62,D20,R33,U53,R51";
			std::string wire2 = "98,R91,D20,R16,D67,R40,U7,R15,U6,R7";
			CrossedWires wire;
			wire.AddWire(wire1, 'a');
			wire.AddWire(wire2, 'b');

			Assert::AreEqual(135, wire.LengthClosedCrossed());
		}
	};
}