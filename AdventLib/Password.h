#pragma once
#include <string>
class Password
{
public:
	bool Verify(std::string& str);
private:
	bool boundarycheck(int number);
};

