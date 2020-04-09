//===================================================
#include <iostream>
#include "MedianStorage.hpp"

//===================================================
template <typename T>
void testFunction(const std::string& aTestName, const MedianStorage<T>& aMedianStorage, T aAwaitedResult)
{
	T medianResult = aMedianStorage.getMedian();
	if (medianResult == aAwaitedResult) 
	{
		std::cout << "TEST " << aTestName.c_str() << " HAS BEEN PASSED, OK" << std::endl;
	}
	else
	{
		std::cout << "TEST " << aTestName.c_str() << " HAS BEEN FAILED!!!" << std::endl;
	}
}

//===================================================
int main()
{
	/// TEST 1
	{
		MedianStorage<double> medianStorage;
		testFunction<double>("TEST_1", medianStorage, 0);
	}
	/// TEST 2
	{
		MedianStorage<double> medianStorage;
		medianStorage.addValue(1);
		testFunction<double>("TEST_2", medianStorage, 1);
	}
	/// TEST 3
	{
		MedianStorage<double> medianStorage;
		medianStorage.addValue(1);
		medianStorage.addValue(2);
		testFunction<double>("TEST_3", medianStorage, 1.5);
	}
	/// TEST 4
	{
		MedianStorage<double> medianStorage;
		medianStorage.addValue(1);
		medianStorage.addValue(2);
		medianStorage.addValue(3);
		testFunction<double>("TEST_4", medianStorage, 2);
	}
	/// TEST 5
	{
		MedianStorage<double> medianStorage;
		medianStorage.addValue(1);
		medianStorage.addValue(2);
		medianStorage.addValue(3);
		medianStorage.addValue(4);
		medianStorage.addValue(5);
		testFunction<double>("TEST_5", medianStorage, 3);
	}
	return 0;
}