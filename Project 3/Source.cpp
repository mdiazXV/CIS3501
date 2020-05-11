//Mariah Diaz
//CIS 3501
//Fall 2019
//Prof. John P. Baugh
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

//Declarations of arrays and array sizes
const int arraySize1 = 250;
const int arraySize2 = 500;
const int arraySize3 = 750;
const int arraySize4 = 1000;
const int arraySize5 = 2500;
int firstArray[arraySize1], secondArray[arraySize2], thirdArray[arraySize3], fourthArray[arraySize4], fifthArray[arraySize5];

//The following function is to find the partition for the Quicksort
//The input is the array and two integers. The function then goes through
//the array and finds the pivot best suited for the sort
int Partition(int numbers[], int i, int k)
{
	int l;
	int h;
	int midpoint;
	int pivot;
	int temp;
	bool done;

	//Pick middle element as pivot
	midpoint = i + (k - i) / 2;
	pivot = numbers[midpoint];

	done = false;
	l = i;
	h = k;

	while (!done)
	{
		while (numbers[l] < pivot)
		{
			++l;
		}

		while (pivot < numbers[h])
		{
			--h;
		}
		if (l >= h)
		{
			done = true;
		}
		else
		{
			temp = numbers[l];
			numbers[l] = numbers[h];
			numbers[h] = temp;
			++l;
			--h;
		}
	}

	return h;
}

//The function is recursive, calling the partition function
//The output of the partition, which is the pivot, is then set to
//a local variable and used in the recursive calls
//The function does not have an output, but it does take an array as input
//and sorts the array, utilizing the pivot in its recursion
void Quicksort(int numbers[], int i, int k)
{
	int j;

	if (i >= k)
	{
		return;
	}

	j = Partition(numbers, i, k);
	Quicksort(numbers, i, j);
	Quicksort(numbers, j + 1, k);
}

//The following function is for insertion sort implementation
//The input for this function is an array and its size
//The function has no output, but it does sort an array using
//the insertion sort algorithm
void Insertion(int numbers[], int numberSize)
{
	int i;
	int j;
	int temp;
	for (i = 1; i < numberSize; ++i)
	{
		j = i;
		while (j > 0 && numbers[j] < numbers[j - 1])
		{
			temp = numbers[j];
			numbers[j] = numbers[j - 1];
			numbers[j - 1] = temp;
			--j;
		}
	}
}

int main()
{
	//load the first array and sort
	for (int i = 0; i < arraySize1; i++)
	{
		firstArray[i] = rand() % 300 + 1;
	}

	auto start = std::chrono::high_resolution_clock::now();
	Quicksort(firstArray, 0, arraySize1 - 1);
	auto finish = std::chrono::high_resolution_clock::now();
	cout << "The time it took to Quicksort the array of size 250: " << 
		std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ns/n" << endl;

	auto start2 = std::chrono::high_resolution_clock::now();
	Insertion(firstArray, arraySize1);
	auto finish2 = std::chrono::high_resolution_clock::now();
	cout << "The time it took to Insertion Sort the array of size 250: " <<
		std::chrono::duration_cast<std::chrono::nanoseconds>(finish2 - start2).count() << " ns/n" << endl;

	//load the second array and sort
	for (int i = 0; i < arraySize2; i++)
	{
		secondArray[i] = rand() % 300 + 1;
	}

	auto start3 = std::chrono::high_resolution_clock::now();
	Quicksort(secondArray, 0, arraySize2 - 1);
	auto finish3 = std::chrono::high_resolution_clock::now();
	cout << "The time it took to Quicksort the array of size 500: " <<
		std::chrono::duration_cast<std::chrono::nanoseconds>(finish3 - start3).count() << " ns/n" << endl;

	auto start4 = std::chrono::high_resolution_clock::now();
	Insertion(secondArray, arraySize2);
	auto finish4 = std::chrono::high_resolution_clock::now();
	cout << "The time it took to Insertion Sort the array of size 500: " <<
		std::chrono::duration_cast<std::chrono::nanoseconds>(finish4 - start4).count() << " ns/n" << endl;

	//load the third array and sort
	for (int i = 0; i < arraySize3; i++)
	{
		thirdArray[i] = rand() % 300 + 1;
	}

	auto start5 = std::chrono::high_resolution_clock::now();
	Quicksort(thirdArray, 0, arraySize3 - 1);
	auto finish5 = std::chrono::high_resolution_clock::now();
	cout << "The time it took to Quicksort the array of size 750: " <<
		std::chrono::duration_cast<std::chrono::nanoseconds>(finish5 - start5).count() << " ns/n" << endl;

	auto start6 = std::chrono::high_resolution_clock::now();
	Insertion(thirdArray, arraySize3);
	auto finish6 = std::chrono::high_resolution_clock::now();
	cout << "The time it took to Insertion Sort the array of size 750: " <<
		std::chrono::duration_cast<std::chrono::nanoseconds>(finish6 - start6).count() << " ns/n" << endl;

	//load the fourth array and sort
	for (int i = 0; i < arraySize4; i++)
	{
		fourthArray[i] = rand() % 300 + 1;
	}

	auto start7 = std::chrono::high_resolution_clock::now();
	Quicksort(fourthArray, 0, arraySize4 - 1);
	auto finish7 = std::chrono::high_resolution_clock::now();
	cout << "The time it took to Quicksort the array of size 1000: " <<
		std::chrono::duration_cast<std::chrono::nanoseconds>(finish7 - start7).count() << " ns/n" << endl;

	auto start8 = std::chrono::high_resolution_clock::now();
	Insertion(fourthArray, arraySize4);
	auto finish8 = std::chrono::high_resolution_clock::now();
	cout << "The time it took to Insertion Sort the array of size 1000: " <<
		std::chrono::duration_cast<std::chrono::nanoseconds>(finish8 - start8).count() << " ns/n" << endl;

	//load fifth array and sort
	for (int i = 0; i < arraySize5; i++)
	{
		fifthArray[i] = rand() % 300 + 1;
	}

	auto start9 = std::chrono::high_resolution_clock::now();
	Quicksort(fifthArray, 0, arraySize5 - 1);
	auto finish9 = std::chrono::high_resolution_clock::now();
	cout << "The time it took to Quicksort the array of size 2500: " <<
		std::chrono::duration_cast<std::chrono::nanoseconds>(finish9 - start9).count() << " ns/n" << endl;

	auto start10 = std::chrono::high_resolution_clock::now();
	Insertion(fifthArray, arraySize5);
	auto finish10 = std::chrono::high_resolution_clock::now();
	cout << "The time it took to Insertion Sort the array of size 2500: " <<
		std::chrono::duration_cast<std::chrono::nanoseconds>(finish10 - start10).count() << " ns/n" << endl;

	system("pause");
}