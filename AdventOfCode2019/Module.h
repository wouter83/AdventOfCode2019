#pragma once
class Module
{
public:
	Module(unsigned int mass);
	~Module();
	unsigned int FuelRequired();
	void SetId(unsigned int id) { mId = id; }
	unsigned int GetMass() { return mMass; }

private:
	unsigned int mId;
	unsigned int mMass;
};

