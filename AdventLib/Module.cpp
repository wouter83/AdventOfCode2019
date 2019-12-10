#include "stdafx.h"
#include "Module.h"


Module::Module(unsigned int mass)
	: mMass(mass)
{
}

Module::~Module()
{
}

int Module::calculateFuel(unsigned int mass)
{
	 return (mass / 3) - 2;
}

unsigned int Module::calculateTotalFuel(unsigned int mass)
{
	int fuel = calculateFuel(mass);
	if (fuel > 0) {
		return fuel + calculateTotalFuel(fuel);
	} else {
		return 0;
	}
}
unsigned int Module::FuelRequired()
{
	return calculateTotalFuel(mMass);
	
}
