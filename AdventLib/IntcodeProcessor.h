#pragma once
#include <vector>

class Process
{
public:
	static int process(std::vector<unsigned int>& data);
	static int process(unsigned int* data, unsigned int size);
};

