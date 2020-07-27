#include "stdafx.h"
#include "IntcodeProcessor.h"

int Process::process(std::vector<int>& data, std::vector<int>& output, int input)
{
	return process(&data[0], data.size(), output, input);
}

int Process::process( int* data, unsigned int size, std::vector<int>& output, int input)
{
	if (size < 4) return -1;
	unsigned int loc = 0;
	bool error = false;
	unsigned int opcode;

	int modeC, modeB, modeA;
	while (1)
	{
		modeC = modeB = modeA = 0;
		if (loc >= size) break;
		if (error) break;
		
		{
			///opcode etc parser
			int test = data[loc] / 100;
			opcode = data[loc] - (test *100);
			if (test > 0) 
			{
				modeA = test / 100;
				modeB = (test - (modeA * 100)) / 10;
				modeC = (test - ((modeA * 100) + (modeB * 10)));
			}
			loc++;
		}
		
		
		unsigned int pos1, pos2, rslt_loc;

		switch (opcode)
		{
		case 1:
		{
			// adding
			pos1 = data[loc++];
			pos2 = data[loc++];
			rslt_loc = data[loc++];
			if ( (pos1 > size && modeC == 0) || 
				 (pos2 > size && modeB == 0) || 
				  rslt_loc > size ||
				modeA !=0) 
			{ 
				error = true; break; 
			}
			data[rslt_loc] = (modeC == 1 ? pos1 : data[pos1]) + 
							 (modeB == 1 ? pos2 : data[pos2]);
			break;
		}
		case 2:
		{
			// multiply
			pos1 = data[loc++];
			pos2 = data[loc++];
			rslt_loc = data[loc++];
			if ((pos1 > size && modeC == 0) ||
				(pos2 > size && modeB == 0) ||
				rslt_loc > size ||
				modeA != 0)
			{
				error = true; break;
			}
			data[rslt_loc] = (modeC == 1 ? pos1 : data[pos1]) *
							 (modeB == 1 ? pos2 : data[pos2]);
			break;
		}
		case 3:
		{
			rslt_loc = data[loc++];
			data[rslt_loc] = input;
			break;
		}
		case 4:
		{
			rslt_loc = data[loc++];
			output.push_back(data[rslt_loc]);
			break;
		}
		case 99:
			return 0;
			break;
		default:
			break;
		}
	}
	return -2;
}
