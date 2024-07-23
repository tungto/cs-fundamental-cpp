#include <iostream>
#include <stdio.h>
#include <conid.h>
using namespace std;

struct Student
{
	char fullName[31];
	int math;
	int literature;
	float average;
};

typedef struct Student STUDENT;
void Input(STUDENT &);
void Output(STUDENT &);
void Print(STUDENT &);

int main()
{
	STUDENT student;
	Input(student);
	Print(student);

	return 0;
}