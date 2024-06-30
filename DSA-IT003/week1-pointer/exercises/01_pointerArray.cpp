#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cmath>

using namespace std;

// gen random int number
int genRandomNumber(int min, int max)
{

	// x % y = [0, y - 1]
	int result = rand() % (max - min) + min + 1;

	// printf("test random: %d\n", result);

	return result;
}

// gen random double number
double genRandomNumber(double min, double max)
{
	double random = static_cast<double>(rand()) / RAND_MAX;

	double result = random * (max - min) + min;

	double roundedResult = round((result * 100) / 100); // round to 2 decimal places

	return roundedResult;
}

double *createRandomArray(int &size)
{
	double min = -268.0;
	double max = 339.0;
	size = genRandomNumber(10, 20);
	double *arr = new double[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = genRandomNumber(min, max);
	}

	return arr;
}

void printArray(double *arr, int size)
{
	cout << "Generated array:" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "item at " << i << " is : " << arr[i] << endl;
	}
}

double getSum(double *arr, int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum;
}

// Function to calculate the sum and product of elements in the array
void calculateSumAndProduct(double *arr, int size, double &sum, double &product)
{
	sum = 0.0;
	product = 1.0;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
		product *= arr[i];
	}
}

// Function to count occurrences of a specific value in the array
int countOccurrences(double *arr, int size, double value)
{
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == value)
		{
			count++;
		}
	}
	return count;
}

/**
 * resize the array
 */
double *resizeArray(double *arr, int size)
{
	double *newArr = new double[size];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;

	return newArr;
}

// tra ve con tro tro toi mang even numbers
double *getEvenItems(double *arr, int size)
{
	int evenCount = 0;
	double *evenNums = new double[size];
	for (int i = 0; i < size; ++i)
	{
		double number = arr[i];
		double intNum;
		double fracPart = modf(number, &intNum);

		if ((int)(intNum) % 2 == 0)
		{
			cout << arr[i] << " ";
			evenNums[evenCount++] = arr[i];
		}
	}

	double *resizedEventNums = resizeArray(evenNums, evenCount);

	return resizedEventNums;
}

int findTheMinIndex(double *arr, int size)
{
	int index = 0;
	double temp = arr[0];

	for (int i = 0; i < size; i++)
	{
		if (temp >= arr[i])
		{
			index = i;
			temp = arr[i];
		}
	}
	return index;
}
/**
 * reverse the array
 */
double *reverseArr(double *arr, int size)
{
	double *reversedArr = new double[size];
	for (int i = 0; i < size; i++)
	{
		reversedArr[i] = arr[size - i - 1];
	}

	return reversedArr;
}

double *getNegativeNumber(double *arr, int size)
{
	double *negativeArr = new double[size];
	int negativeCount = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			negativeArr[negativeCount++] = arr[i];
		}
	}

	printf("%d count", negativeCount);

	double *resizedNegativeArr = resizeArray(negativeArr, negativeCount);

	return resizedNegativeArr;
}

struct ItemInRange
{
	int count;
	double *arrItemInRange;
};

ItemInRange countItemsInRange(double min, double max, double *arr, int size)
{
	int count = 0;

	double *arrItemInRange = new double[size];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= min && arr[i] <= max)
		{
			arrItemInRange[count++] = arr[i];
		}
	}

	return {count, arrItemInRange};
}

int main()
{
	srand(static_cast<unsigned int>(time(NULL))); // seed for random number generator

	int size;
	double *arr = createRandomArray(size);

	// 2. print arr
	printArray(arr, size);

	// 3. sum
	double sum = getSum(arr, size);
	cout << "Sum of all elements in the array: " << sum << endl;

	// 4. Calculate the sum and product of array elements
	double product;
	calculateSumAndProduct(arr, size, sum, product);
	cout << "Sum of array elements: " << sum << endl;
	cout << "Product of array elements: " << product << endl;

	// 5. Count occurrences of a specific value (e.g., first element of the array)
	double valueToFind = arr[0];
	int count = countOccurrences(arr, size, valueToFind);
	cout << "Number of occurrences of " << valueToFind << ": " << count << endl;

	// 6. return arr of even number
	double *evenNums = getEvenItems(arr, size);

	// 7 find the index of minimum value
	int minIndex = findTheMinIndex(arr, size);
	cout << "Index of minimum value: " << minIndex << endl;

	// 8. create reverse array
	double *reversedArr = reverseArr(arr, size);
	printArray(reversedArr, size);

	// 9. get negative array
	double *negativeArr = getNegativeNumber(arr, size);
	cout << "Negative numbers in the array: " << endl;
	// printArray(negativeArr);

	// 10. count item in range
	ItemInRange result = countItemsInRange(0, 100, arr, size);
	cout << "items in range: " << result.count << endl;

	// free dynamically allocated memory
	delete[] evenNums;
	delete[] reversedArr;
	delete[] arr; // free dynamically allocated memory

	return 0;
}