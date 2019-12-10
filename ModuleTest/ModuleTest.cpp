#include "stdafx.h"
#include "CppUnitTest.h"
#include "Module.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ModuleTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(calculateFuel)
		{
			// Big number
			unsigned int mass = 100756;
			int rslt = 33583;

			Module mc1(0);
			Assert::AreEqual(rslt, mc1.calculateFuel(mass));

			// small number
			mass = 12;
			rslt = 2;

			Module mc2(0);
			Assert::AreEqual(rslt, mc2.calculateFuel(mass));

			// odd small number
			mass = 14;
			rslt = 2;

			Module mc3(0);
			Assert::AreEqual(rslt, mc3.calculateFuel(mass));
		}

		TEST_METHOD(calculateTotalFuel)
		{
			// Big number
			unsigned int mass = 100756;
			unsigned int rslt = 50346;

			Module mc1(0);
			Assert::AreEqual(rslt, mc1.calculateTotalFuel(mass));

			// odd small number
			mass = 14;
			rslt = 2;

			Module mc2(0);
			Assert::AreEqual(rslt, mc2.calculateTotalFuel(mass));
		}
	};
}