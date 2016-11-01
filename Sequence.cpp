// Sequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
using namespace std;

int checkSequence(int);
bool checkMass(bool*);
void searchNumbers(bool*,int);
int getCountsOfDigits(int);
void test(int);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	test(1);
	test(1692);
	test(0);
	test(156);
	test(5);
	test(1111);
	test(999);
	test(13463);
	test(4887);
	getchar();
	return 0;
}
int checkSequence(int N)
{
	if(N==0)
		return 0;

	bool mass[10] = {0,0,0,0,0,0,0,0,0,0};
	int i = 1;
	for(;!checkMass(mass);i++)
	{
		cout << i <<")   " <<i*N<<endl;
		searchNumbers(mass,i*N);
	}
	return i-1;
}
bool checkMass(bool* mass)
{
	for(int i=0;i<10;i++)
		if(!mass[i])
			return false;
	return true;
}
void searchNumbers(bool* mass,int number)
{
	int length = getCountsOfDigits(number);
	for(int i=0;i<length;i++)
	{
		mass[number%10] = true;
		number = number/10;
	}
}
int getCountsOfDigits(int number)
{
	int count = 0;
	while(number){
		number/=10;
		count++;
	}
	return count;
}
void test(int number)
{
	cout << "N = " << number << endl;
	int _returnCheckSequence = checkSequence(number);
	if(_returnCheckSequence == 0)
		cout << "Fail"<<endl;
	else
		cout << _returnCheckSequence << " - Nomer, nachinaya s kotorogo budet poluchen nabor vsekh tsifr"<<endl;
	cout << endl;
}