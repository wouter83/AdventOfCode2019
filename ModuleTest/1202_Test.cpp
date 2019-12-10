#include "stdafx.h"
#include "CppUnitTest.h"
#include <atlstr.h>

#include "IntcodeProcessor.h"
#include "Generic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_1202
{
	

	TEST_CLASS(Test_1202)
	{
	public:

		void test(unsigned int* expexted, unsigned int* actual, unsigned int size ) 
		{
			for (unsigned int i = 0; i < size; ++i)
			{
				Assert::AreEqual(expexted[i], actual[i]);

			}
		};
		TEST_METHOD(Intcode1)
		{
			unsigned int test1[] =  { 1,0,0,0,99 };
			unsigned int reslt1[] = { 2,0,0,0,99 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			Process::process(test1, size);
			test(reslt1, test1, size);

			CStringW rslt("2,0,0,0,99");
			Assert::AreEqual(rslt.GetString(), Generic::ToCommaSeparated(test1, size).GetString());

		}
		TEST_METHOD(Intcode2)
		{
			unsigned int test1[] = { 2,3,0,3,99 };
			unsigned int reslt1[] = { 2,3,0,6,99 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			Process::process(test1, size);
			test(reslt1, test1, size);
		}

		TEST_METHOD(Intcode3)
		{
			unsigned int test1[] = { 2,4,4,5,99,0 };
			unsigned int reslt1[] = { 2,4,4,5,99,9801 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			Process::process(test1, size);
			test(reslt1, test1, size);
		}
		TEST_METHOD(Intcode4)
		{
			unsigned int test1[] = { 1,1,1,4,99,5,6,0,99 };
			unsigned int reslt1[] = { 30,1,1,4,2,5,6,0,99 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			Process::process(test1, size);
			test(reslt1, test1, size);
		}
	};
}