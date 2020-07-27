#include "stdafx.h"
#include "Password.h"

bool Password::boundarycheck(int number)
{
	return number > 1 && number % 2 == 0 && number / 2 == 1;
}

bool Password::Verify(std::string& str)
{
	if (str.length() > 6) return false;
	int prev = -1;
	bool retSameAsPrevious = false;
	bool retSameOrHigher = true;
	bool retCountSame = false;
	int countSame = 1;

	for (char& c : str) 
	{
		int val = (int)c - 48;
		if (prev != -1)
		{
			if (prev == val)
			{
				retSameAsPrevious = true;
				++countSame;
			}
			else 
			{
				if (boundarycheck(countSame))
					retCountSame = true;
				countSame = 1;
			}
			retSameOrHigher &= (prev <= val);
		}
		prev = val;
	}
	if (boundarycheck(countSame))
		retCountSame = true;

	return retSameAsPrevious & retSameOrHigher & retCountSame;
}
