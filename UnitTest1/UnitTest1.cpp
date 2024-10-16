#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7_1_rek/lab_7_1_rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCreate)
        {
            const int rowCount = 3;
            const int colCount = 3;
            const int Low = 1;
            const int High = 10;
            int** R = new int* [rowCount];

            for (int i = 0; i < rowCount; i++)
                R[i] = new int[colCount];

            Create(R, rowCount, colCount, Low, High);

            // Перевірка значень в матриці
            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    Assert::IsTrue(R[i][j] >= Low && R[i][j] <= High);
                }
            }

            for (int i = 0; i < rowCount; i++)
                delete[] R[i];
            delete[] R;
        }

        TEST_METHOD(TestCalc)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** R = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                R[i] = new int[colCount];

            // Встановимо значення матриці
            R[0][0] = 2; R[0][1] = 4; R[0][2] = 6;
            R[1][0] = 1; R[1][1] = 5; R[1][2] = 3;
            R[2][0] = 8; R[2][1] = 10; R[2][2] = 12;

            // Сортуємо масив перед підрахунком
            Sort(R, rowCount, colCount);

            int S = 0, k = 0;
            Calc(R, rowCount, colCount, S, k);

            // сума парних чисел: 2 + 4 + 6 + 8 + 10 + 12 = 42
            Assert::AreEqual(42, S);
            // Кількість парних чисел = 6
            Assert::AreEqual(6, k);

            for (int i = 0; i < rowCount; i++)
                delete[] R[i];
            delete[] R;
        }

	};
}
