#include "stdafx.h"
#include "IntcodeProcessor.h"

int Process::process(std::vector<unsigned int>& data)
{
	return process(&data[0], data.size());
}

int Process::process(unsigned int* data, unsigned int size)
{
	if (size < 4) return -1;
	unsigned int loc = 0;
	bool error = false;
	while (1)
	{
		if (loc >= size) break;
		if (error) break;
		unsigned int opcode = data[loc++];
		unsigned int pos1, pos2, rslt_loc;

		switch (opcode)
		{
		case 1:
		{
			// adding
			pos1 = data[loc++];
			pos2 = data[loc++];
			rslt_loc = data[loc++];
			if (pos1 > size || pos2 > size || rslt_loc > size) { error = true; break; }
			data[rslt_loc] = data[pos1] + data[pos2];
			break;
		}
		case 2:
			// multiply
			pos1 = data[loc++];
			pos2 = data[loc++];
			rslt_loc = data[loc++];
			if (pos1 > size || pos2 > size || rslt_loc > size) { error = true; break; }
			data[rslt_loc] = data[pos1] * data[pos2];
			break;
		case 99:
			return 0;
			break;
		default:
			break;
		}
	}
	return -2;
}
