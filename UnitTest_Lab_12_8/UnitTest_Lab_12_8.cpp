#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_8/Lab_12_8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab128
{
	TEST_CLASS(UnitTestLab128)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* L = NULL;
			insert(L, 1);
			insert(L, 1);
			insert(L, 1);
			insert(L, 3);
			insert(L, 2);
			delmin(L);
			Assert::AreEqual(L->info, 3);
		}
	};
}
