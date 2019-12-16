#include "stdafx.h"
#include "CrossedWires.h"

#include<sstream>

CrossedWires::CrossedWires()
{
	std::vector<char> vect;
	vect.resize(1, '0');
	mGrid.push_back(vect);
}

void CrossedWires::AddRow(int count)
{
	//get amount of columns
	size_t columns = mGrid.begin()->size();
	for (int i = 0; i < count; ++i) {
		std::vector<char> vect;
		vect.resize(columns, '0');
		mGrid.push_back(vect);
	}
}

void CrossedWires::AddColumn(int count)
{
	
	for (std::vector< std::vector<char> >::iterator it = mGrid.begin(); it != mGrid.end(); ++it) {
		
		it->resize(it->size() + count,'0');
	}
}
 
 int CrossedWires::LengthClosedCrossed()
{
	//unsigned int size = mGrid[0].size() + mGrid.size();  // lets put the largest number we can get in
	//for (unsigned int i = 0; i < mGrid.size(); ++i)
	//{
	//	for (unsigned int j = 0; j < mGrid[0].size(); ++j)
	//	{
	//		
	//		if (mGrid[i][j] == 'O') continue;
	//		if (mGrid[i][j] == 'X')
	//		{
	//			// found x, now calculate location to our 'O' point
	//			// i = rows
	//			// j = cols

	//			int rowsToNil = abs(static_cast<int>(mNilPointX - i));
	//			int colsToNil = abs(static_cast<int>(mNilPointY - j));

	//			if (size > rowsToNil + colsToNil)
	//				size = rowsToNil + colsToNil;
	//		}
	//	}
	//}

	return mClosedCross;
}

 std::vector<CrossedWires::Command> CrossedWires::parse(std::string& str)
 {
	 std::vector< CrossedWires::Command> commands;
	 std::stringstream ss(str);
	 std::string command;
	 while (std::getline(ss, command, ','))
	 {
		 CrossedWires::Command cmd;
		 cmd.command = command[0];
		 cmd.count = std::stoi(command.substr(1));
		 commands.push_back(cmd);
	 }
	 return commands;
 }

 void CrossedWires::LoadWires(std::string& a, std::string& b)
 {
	 std::vector< CrossedWires::Command> commandsA = parse(a);
	 std::vector< CrossedWires::Command> commandsB = parse(b);

	 // count the size of the grid
	 int sizeColMin = 0, sizeRowMin = 0;
	 int sizeColMax = 0, sizeRowMax = 0;
	 GetMinMax(commandsA, sizeRowMax, sizeRowMin, sizeColMax, sizeColMin);
	 GetMinMax(commandsB, sizeRowMax, sizeRowMin, sizeColMax, sizeColMin);

	 // Create the grid
	 AddRow(sizeRowMax + abs(sizeRowMin) );
	 AddColumn(sizeColMax + abs(sizeColMin) );

	 // where is null?
	 mNilPointX = abs(sizeRowMin);
	 mNilPointY = abs(sizeColMin);
	 mClosedCross = mGrid[0].size() + mGrid.size();

	 mGrid[mNilPointX][mNilPointY] = 'O';

	 AddWire(commandsA, 'a');
	 AddWire(commandsB, 'b');
 }

 void CrossedWires::GetMinMax(std::vector<CrossedWires::Command>& commands,  int& sizeRowMax, int& sizeRowMin, int& sizeColMax, int& sizeColMin)
 {
	 int curCol = 0, curRow = 0;

	 for (std::vector< CrossedWires::Command >::iterator it = commands.begin(); it != commands.end(); ++it)
	 {
		 CrossedWires::Command cmd = (*it);
		 switch (cmd.command)
		 {
		 case 'U':
			 curRow += cmd.count;
			 if (curRow > sizeRowMax)
				 sizeRowMax = curRow;
			 break;
		 case 'D':
			 curRow -= cmd.count;
			 if (curRow < sizeRowMin)
				 sizeRowMin = curRow;
			 break;
		 case 'R':
			 curCol += cmd.count;
			 if (curCol > sizeColMax)
				 sizeColMax = curCol;
			 break;
		 case 'L':
			 curCol -= cmd.count;
			 if (curCol < sizeColMin)
				 sizeColMin = curCol;
			 break;
		 default:
			 break;
		 }
	 }
 }

void CrossedWires::AddChar(unsigned int x, unsigned int y, char c)
{
	if (mGrid[x][y] == '0' || mGrid[x][y] == c)
		mGrid[x][y] = c;
	else
	{
		mGrid[x][y] = 'X';
		unsigned int rowsToNil = abs(static_cast<int>(mNilPointX - x));
		unsigned int colsToNil = abs(static_cast<int>(mNilPointY - y));

		if (mClosedCross > rowsToNil + colsToNil)
			mClosedCross = rowsToNil + colsToNil;
	}

}

bool CrossedWires::AddWire(std::vector< CrossedWires::Command> commands, char c)
{
	unsigned int curRow = mNilPointX, curCol = mNilPointY;
	for (std::vector< CrossedWires::Command >::iterator it = commands.begin(); it != commands.end(); ++it)
	{
		CrossedWires::Command cmd = (*it);
		switch (cmd.command)
		{
		case 'U':
				
			for (unsigned int i = 1; i <= cmd.count; ++i) {
				AddChar(curRow + i, curCol, c);
			}
			curRow += cmd.count;
			break;
		case 'D':
			for (unsigned int i = 1; i <= cmd.count; ++i) {
				AddChar(curRow - i, curCol, c);
			}
			curRow -= cmd.count;
			break; 
		case 'L':
			for (unsigned int i = 1; i <= cmd.count; ++i) {
				AddChar(curRow, curCol -i, c);
			}
			curCol -= cmd.count;
			break;
		case 'R':
			
			for (unsigned int i = 1; i <= cmd.count; ++i) {
				AddChar(curRow, curCol + i, c);
			}
			curCol += cmd.count;
			break;
		default:
			break;
		}
		
	}

	return false;
}

std::vector<std::vector<char>>& CrossedWires::GetGrid()
{
	return mGrid;
}
