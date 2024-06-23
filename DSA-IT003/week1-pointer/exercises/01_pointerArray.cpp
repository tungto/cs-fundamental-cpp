#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// gen random int number
int genRandomNumber(int min, int max)
{

	// x % y = [0, y - 1]
	int result = rand() % (max - min) + min + 1;

	// printf("test random: %d\n", result);

	return result;
}

// gen random float number
float genRandomNumber(float min, float max)
{

	float random = (float)rand() / RAND_MAX;

	float result = random * max + min + 1;

	float nearest = roundf((result * 100) / 100);

	printf("test nearest: %.2f\n", nearest);

	return nearest;
}

float genRandomFloatNumber(float *a, int &n)
{
	float min = 268;
	float max = 339;
	// int amount = genRandomNumber(10, 20);

	for (int i = 0; i < n; i++)
	{
		*(a + i) = genRandomNumber((float)-268, (float)339);
	}
}

void printArray(float *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "item at " << i << " is :" << *(a + i) << endl;
	}
}

int main()
{
	srand(time(NULL));

	int amount = genRandomNumber(10, 20);
	float *a = new float[amount];

	genRandomFloatNumber(a, amount);

	printArray(a, amount);

	return 0;
}