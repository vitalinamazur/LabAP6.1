#include "pch.h"
#include "CppUnitTest.h"
#include "../LabAP6.1/LabAP6.1.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForArrayProcessing
{
    TEST_CLASS(UnitTestForArrayProcessing)
    {
    public:

        TEST_METHOD(TestCreateArray)
        {
            const int n = 5;
            int r[n];
            int Low = 10, High = 90;

            Create(r, n, Low, High);

            for (int i = 0; i < n; i++) {
                Assert::IsTrue(r[i] >= Low && r[i] <= High);
            }
        }

        TEST_METHOD(TestProcessArray)
        {
            const int n = 5;
            int r[n] = { 15, 21, 27, 45, 75 };
            int count = 0, sum = 0;

            ProcessArray(r, n, count, sum);

            Assert::AreEqual(5, count);     
            Assert::AreEqual(183, sum);    
            int expectedArray[n] = { 15, 21, 27, 45, 75 };

            for (int i = 0; i < n; i++) {
                Assert::AreEqual(expectedArray[i], r[i]);
            }
        }
    };
}
