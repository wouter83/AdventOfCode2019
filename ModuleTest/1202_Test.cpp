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

		TEST_METHOD(IntcodeDay5_D5_2_1)
		{
			int test1[] = { 3,9,8,9,10,9,4,9,99,-1,8 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			int input = 8;
			std::vector<int> output;
			int ret = Process::process(test1, size, output, input);
			Assert::AreEqual(1, output[output.size() - 1]);

			int test2[] = { 3,9,8,9,10,9,4,9,99,-1,8 };
			output.clear();
			input = 9;
			ret = Process::process(test2, size, output, input);

			Assert::AreEqual(0, output[output.size() - 1]);
		}

		TEST_METHOD(IntcodeDay5_D5_2_2)
		{
			int test1[] = { 3,9,7,9,10,9,4,9,99,-1,8 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			int input = 7;
			std::vector<int> output;
			int ret = Process::process(test1, size, output, input);
			Assert::AreEqual(1, output[output.size() - 1]);

			int test2[] = { 3,9,7,9,10,9,4,9,99,-1,8 };
			output.clear();
			input = 9;
			ret = Process::process(test2, size, output, input);

			Assert::AreEqual(0, output[output.size() - 1]);
		}

		TEST_METHOD(IntcodeDay5_D5_2_3)
		{
			int test1[] = { 3,3,1108,-1,8,3,4,3,99 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			int input = 8;
			std::vector<int> output;
			int ret = Process::process(test1, size, output, input);
			Assert::AreEqual(1, output[output.size() - 1]);

			int test2[] = { 3,3,1108,-1,8,3,4,3,99 };

			output.clear();
			input = 9;
			ret = Process::process(test2, size, output, input);

			Assert::AreEqual(0, output[output.size() - 1]);
		}

		TEST_METHOD(IntcodeDay5_D5_2_4)
		{
			int test1[] = { 3,3,1107,-1,8,3,4,3,99 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			int input = 7;
			std::vector<int> output;
			int ret = Process::process(test1, size, output, input);
			Assert::AreEqual(1, output[output.size() - 1]);

			int test2[] = { 3,3,1107,-1,8,3,4,3,99 };
			output.clear();
			input = 9;
			ret = Process::process(test2, size, output, input);

			Assert::AreEqual(0, output[output.size() - 1]);
		}

		TEST_METHOD(IntcodeDay5_D5_2_5)
		{
			int test1[] = { 3,12,6,12,15,1,13,14,13,4,13,99,-1,0,1,9 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			int input = 0;
			std::vector<int> output;
			int ret = Process::process(test1, size, output, input);
			Assert::AreEqual(0, output[output.size() - 1]);

			int test2[] = { 3,12,6,12,15,1,13,14,13,4,13,99,-1,0,1,9 };
			output.clear();
			input = 9;
			ret = Process::process(test2, size, output, input);

			Assert::AreEqual(1, output[output.size() - 1]);
		}
		TEST_METHOD(IntcodeDay5_D5_2_6)
		{
			int test1[] = { 3,3,1105,-1,9,1101,0,0,12,4,12,99,1 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			int input = 0;
			std::vector<int> output;
			int ret = Process::process(test1, size, output, input);
			Assert::AreEqual(0, output[output.size() - 1]);

			int test2[] = { 3,3,1105,-1,9,1101,0,0,12,4,12,99,1 };
			output.clear();
			input = 9;
			ret = Process::process(test2, size, output, input);

			Assert::AreEqual(1, output[output.size() - 1]);
		}
		TEST_METHOD(IntcodeDay5_D5_2_x)
		{
			int test1[] = { 3,21,1008,21,8,20,1005,20,22,107,8,21,20,1006,20,31,1106,0,36,98,0,0,1002,21,125,20,4,20,1105,1,46,104,999,1105,1,46,1101,1000,1,20,4,20,1105,1,46,98,99 };
			unsigned int size = sizeof(test1) / sizeof(unsigned int);
			
			int input = 5;
			std::vector<int> output;
			int ret = Process::process(test1, size, output, input);
			Assert::AreEqual(999, output[output.size()-1]);

			int test2[] = { 3, 21, 1008, 21, 8, 20, 1005, 20, 22, 107, 8, 21, 20, 1006, 20, 31, 1106, 0, 36, 98, 0, 0, 1002, 21, 125, 20, 4, 20, 1105, 1, 46, 104, 999, 1105, 1, 46, 1101, 1000, 1, 20, 4, 20, 1105, 1, 46, 98, 99 };

			output.clear();
			input = 8;
			ret = Process::process(test2, size, output, input); 
			Assert::AreEqual(1000, output[output.size() - 1]);
			int test3[] = { 3, 21, 1008, 21, 8, 20, 1005, 20, 22, 107, 8, 21, 20, 1006, 20, 31, 1106, 0, 36, 98, 0, 0, 1002, 21, 125, 20, 4, 20, 1105, 1, 46, 104, 999, 1105, 1, 46, 1101, 1000, 1, 20, 4, 20, 1105, 1, 46, 98, 99 };

			output.clear();
			input = 10;
			ret = Process::process(test3, size, output, input);
			Assert::AreEqual(1001, output[output.size() - 1]);

		}
	};
}