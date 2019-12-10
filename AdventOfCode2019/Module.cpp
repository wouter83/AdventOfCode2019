#include "stdafx.h"
#include "Module.h"


Module::Module(unsigned int mass)
	: mMass(mass)
{
}

Module::~Module()
{
}

unsigned int Module::FuelRequired()
{
	return (mMass / 3) - 2;
}
