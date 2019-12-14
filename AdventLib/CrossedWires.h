#pragma once
#include <string>
#include <vector>


class CrossedWires
{
public:
	CrossedWires();
	void AddRow(int count);
	void AddColumn(int count);
	bool AddWire(std::string& str, char c);
	std::vector<std::vector<char>>& GetGrid() { return mGrid; };

	 int LengthClosedCrossed();
private:
	void AddChar(int x, int y, char c);

	std::vector<std::vector<char>> mGrid;
	unsigned int mColSize = 0;
	unsigned int mRowSize = 0;

};

