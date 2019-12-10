#pragma once
class Module
{
public:
	Module(unsigned int mass);
	~Module();
	unsigned int FuelRequired();
	void SetId(unsigned int id) { mId = id; }
	unsigned int GetMass() { return mMass; }
	int calculateFuel(unsigned int mass);
	unsigned int calculateTotalFuel(unsigned int mass);

private:
	unsigned int mId;
	unsigned int mMass;
};

