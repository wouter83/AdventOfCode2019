#include "pch.h"
#include "Generic.h"

CStringW Generic::ToCommaSeparated(unsigned int* data, unsigned int size)
{
	CStringW t;
	for (unsigned int i = 0; i < size; ++i)
	{
		CStringW tmp;
		CStringW comma(",");

		tmp.Format(L"%d", data[i]);
		t.Append(tmp);
		if (i + 1 != size) {
			t.Append(comma);
		}
	}
	return t;
}
