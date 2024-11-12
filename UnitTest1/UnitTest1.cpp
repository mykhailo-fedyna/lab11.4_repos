#include "pch.h"
#include "CppUnitTest.h"
#include "../lab11.4.cpp"  // Підключення основного файлу з кодом

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestAreParallel)
		{
			// Тест перевірки паралельності
			Line line1 = { 1, 2, -3 };
			Line line2 = { 2, 4, -6 };  // Паралельна пряма
			Line line3 = { 3, 1, 0 };   // Непаралельна пряма

			Assert::IsTrue(areParallel(line1, line2), L"Прямі мають бути паралельними");
			Assert::IsFalse(areParallel(line1, line3), L"Прямі не повинні бути паралельними");
		}

		TEST_METHOD(TestArePerpendicular)
		{
			// Тест перевірки перпендикулярності
			Line line1 = { 1, 2, -3 };
			Line line2 = { -2, 1, 4 };   // Перпендикулярна пряма
			Line line3 = { 3, 1, 0 };    // Неперпендикулярна пряма

			Assert::IsTrue(arePerpendicular(line1, line2), L"Прямі мають бути перпендикулярними");
			Assert::IsFalse(arePerpendicular(line1, line3), L"Прямі не повинні бути перпендикулярними");
		}
	};
}
