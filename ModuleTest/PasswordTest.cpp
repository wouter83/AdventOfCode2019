#include "stdafx.h"
#include "CppUnitTest.h"
#include <afx.h>
#include <vector>

#include "Password.h"
#include "Generic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PasswordTest
{
	TEST_CLASS(PasswordTest)
	{
	public:
		TEST_METHOD(verify)
		{
			Password p;
			std::string input = "122345";
			Assert::IsTrue( p.Verify(input));

			input = "111123";
			Assert::IsFalse(p.Verify(input));

			input = "135679";
			Assert::IsFalse(p.Verify(input));

			input = "111111";
			Assert::IsFalse(p.Verify(input));

			input = "223450";
			Assert::IsFalse(p.Verify(input));

			input = "123789";
			Assert::IsFalse(p.Verify(input));

			input = "112233";
			Assert::IsTrue(p.Verify(input));

			input = "123444";
			Assert::IsFalse(p.Verify(input));

			input = "111122";
			Assert::IsTrue(p.Verify(input));


			input = "122333";
			Assert::IsTrue(p.Verify(input));
		}
	};
}