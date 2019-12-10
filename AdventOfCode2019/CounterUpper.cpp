#include "stdafx.h"
#include "CounterUpper.h"


CounterUpper::CounterUpper()
{
}

CounterUpper::~CounterUpper()
{
}

void CounterUpper::AddModule(Module& mod)
{
	mod.SetId( mModules.size());
	mModules.push_back(mod);

	mTotalFuel += mod.FuelRequired();
	mTotalMass += mod.GetMass();
}

unsigned int CounterUpper::GetTotalFuel()
{
	return mTotalFuel;
}

unsigned int CounterUpper::GetTotalMass()
{
	return mTotalMass;
}
