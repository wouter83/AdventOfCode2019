#pragma once
#include <vector>

class Process
{
public:
	static int process(std::vector<int>& data, std::vector<int>& output, int input = 0);
	static int process(int* data, unsigned int size, std::vector<int>& output, int input = 0);
};

