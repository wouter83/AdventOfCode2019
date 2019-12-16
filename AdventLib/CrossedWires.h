#pragma once
#include <string>
#include <vector>
#include <map>


class CrossedWires
{
public:
	struct Command {
		char command;
		unsigned int count;
	}; 
	
	CrossedWires();
	void AddRow(int count);
	void AddColumn(int count);
	bool AddWire(std::vector< CrossedWires::Command> cmd, char c);
	std::vector<std::vector<char>>& GetGrid();

	int LengthClosedCrossed();
	void LoadWires(std::string& a, std::string& b);

	void GetMinMax(std::vector<CrossedWires::Command>& commandsA, int& sizeRowMax, int& sizeRowMin, int& sizeColMax, int& sizeColMin);

private:
	void AddChar(unsigned int x, unsigned int y, char c);
	std::vector<Command> parse(std::string& str);

	std::vector<std::vector<char>> mGrid;
	unsigned int mColSize = 0;
	unsigned int mRowSize = 0;

	unsigned int mNilPointX, mNilPointY = 0;
	std::map<int, int> mCross;
	unsigned int mClosedCross;
};

