#include "stdafx.h"
#include "CrossedWires.h"

#include<sstream>

CrossedWires::CrossedWires()
{
	std::vector<char> vect;
	vect.resize(1, 'O');
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
	mRowSize += count;
}

void CrossedWires::AddColumn(int count)
{
	
	for (std::vector< std::vector<char> >::iterator it = mGrid.begin(); it != mGrid.end(); ++it) {
		
		it->resize(it->size() + count,'0');
	}
	mColSize += count;

}
 
 int CrossedWires::LengthClosedCrossed()
{
	unsigned int size = mColSize + mRowSize;
	for (unsigned int i = 0; i < mColSize; ++i)
	{
		for (unsigned int j = 0; j < mRowSize; ++j)
		{
			if (mGrid[i][j] == 'X')
			{
				if (size > i + j)
					size = i + j;
			}
		}
	}

	return size;
}

void CrossedWires::AddChar(int x, int y, char c)
{
	if (mGrid[x][y] == '0')
		mGrid[x][y] = c;
	else
		mGrid[x][y] = 'X';
}

bool CrossedWires::AddWire(std::string& str, char c)
{
	std::stringstream ss(str);
	std::string command;

	unsigned int curCol = 0, curRow = 0;
	

	while (std::getline(ss, command, ','))
	{
		int size = command.size();
		if (size != std::string::npos)
		{
			std::string direction = command.substr(0, 1);
			unsigned int value = std::stoi(command.substr(1));
			switch (direction[0])
			{
			case 'U':
				// create more rows?
				if ((curRow + value) > mRowSize) {
					AddRow((curRow + value) - mRowSize);
				}
				for (unsigned int i = 1; i <= value; ++i) {
					AddChar(curRow + i, curCol, c);
				}
				curRow += value;
				break;
			case 'D':
				// can not go under zero rows
				for (unsigned int i = 1; i <= value; ++i) {
					AddChar(curRow - i, curCol, c);
				}
				curRow -= value;
				break; 
			case 'L':
				// can not go under zero columns
				for (unsigned int i = 1; i <= value; ++i) {
					AddChar(curRow, curCol -i, c);
				}
				curCol -= value;
				break;
			case 'R':
				// create more columns?
				if ((curCol + value) > mColSize) {
					AddColumn((curCol + value) - mColSize);
				}
				for (unsigned int i = 1; i <= value; ++i) {
					AddChar(curRow, curCol + i, c);
				}
				curCol += value;
				break;
			default:
				break;
			}
		}
	}

	return false;
}
