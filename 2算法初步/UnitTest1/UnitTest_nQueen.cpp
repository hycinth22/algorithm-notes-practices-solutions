#include "pch.h"
#include "CppUnitTest.h"
#include "../递归-n皇后问题/递归-n皇后问题.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestNQueen)
	{
	public:
		TEST_METHOD(Queen4)
		{
			cout << "Queen4 Amount:" << f(4);
		}
		TEST_METHOD(Queen6)
		{
			cout << "Queen6 Amount:" << f(6);
		}
		TEST_METHOD(Queen8)
		{
			cout << "Queen8 Amount:" << f(8);
		}
		TEST_METHOD(Queen10)
		{
			cout << "Queen10 Amount:" << f(10);
		}
		TEST_METHOD(Queen12)
		{
			cout << "Queen12 Amount:" << f(12);
		}
	};
}
