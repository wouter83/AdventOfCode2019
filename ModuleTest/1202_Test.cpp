#include "stdafx.h"
#include "CppUnitTest.h"
#include <afx.h>
#include <vector>

#include "IntcodeProcessor.h"
#include "Generic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_1202
{
	

	TEST_CLASS(Test_1202)
	{
	public:

		void test(int* expexted, int* actual, unsigned int size ) 
		{
			for (unsigned int i = 0; i < size; ++i)
			{
				Assert::AreEqual(expexted[i], actual[i]);

			}
		};
		TEST_METHOD(Intcode1)
		{
			int test1[] =  { 1,0,0,0,99 };
			int reslt1[] = { 2,0,0,0,99 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			std::vector<int> output;

			Process::process(test1, size, output);
			test(reslt1, test1, size);

			

		}
		TEST_METHOD(Intcode2)
		{
			int test1[] = { 2,3,0,3,99 };
			int reslt1[] = { 2,3,0,6,99 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			std::vector<int> output;

			Process::process(test1, size,output);
			test(reslt1, test1, size);
		}

		TEST_METHOD(Intcode3)
		{
			int test1[] = { 2,4,4,5,99,0 };
			int reslt1[] = { 2,4,4,5,99,9801 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			std::vector<int> output;

			std::vector<int> tmp;
			for (unsigned int k = 0; k < size; ++k)
				tmp.push_back(test1[k]);

			Process::process(tmp,output);
			test(reslt1, &tmp[0], size);
		}
		TEST_METHOD(Intcode4)
		{
			int test1[] = { 1,1,1,4,99,5,6,0,99 };
			int reslt1[] = { 30,1,1,4,2,5,6,0,99 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			std::vector<int> output;

			Process::process(test1, size,output);
			test(reslt1, test1, size);
		}
		
		TEST_METHOD(Intcode5)
		{
			int test1[] = { 1,11,1,4,99,5,6,0,99 };
			int size = sizeof(test1) / sizeof(unsigned int);
			std::vector<int> output;

			int ret = Process::process(test1, size,output);

			Assert::AreEqual(-2, ret);
		}

		TEST_METHOD(Intcode6)
		{
			int test1[] = { 1,1,10,4,99,5,6,0,99 };
			int size = sizeof(test1) / sizeof(unsigned int);
			std::vector<int> output;

			int ret = Process::process(test1, size,output);

			Assert::AreEqual(-2, ret);
		}
		
		TEST_METHOD(Intcode7)
		{
			int test1[] = { 1,1,1,10,99,5,6,0,99 };
			int size = sizeof(test1) / sizeof(unsigned int);
			std::vector<int> output;

			int ret = Process::process(test1, size,output);

			Assert::AreEqual(-2, ret);
		}

		TEST_METHOD(IntcodeDay5_newParam)
		{
			int test1[] = { 3,0,4,0,99 };
			int size = sizeof(test1) / sizeof(unsigned int);
			std::vector<int> output;
			int ret = Process::process(test1, size,output);

			Assert::AreEqual(0, ret);
			Assert::AreEqual(0, output[0]);
		}

		TEST_METHOD(IntcodeDay5_ParamMode)
		{
			int test1[] = { 1002,4,3,4,33 };
			int reslt1[] = { 1002,4,3,4,99 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			std::vector<int> output;
			int ret = Process::process(test1, size, output);

			test(reslt1, test1, size);
		}

		TEST_METHOD(IntcodeDay5_ParamModeNegative)
		{
			int test1[] = { 1101,100,-1,4,0 };
			int reslt1[] = { 1101,100,-1,4,99 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			std::vector<int> output;
			int ret = Process::process(test1, size, output);

			test(reslt1, test1, size);
		}
	};
}