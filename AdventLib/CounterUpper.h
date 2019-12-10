#pragma once
#include <vector>
#include "Module.h"
class CounterUpper
{
public:
	CounterUpper();
	~CounterUpper();
	void AddModule(Module& mod);
	unsigned int GetTotalFuel();
	unsigned int GetTotalMass();

private:
	unsigned int mTotalMass = 0;
	unsigned int mTotalFuel = 0;
	std::vector<Module> mModules;
};

