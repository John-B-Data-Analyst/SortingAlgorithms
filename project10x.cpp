// Created By: John Blee 3 April 2018
// CSCI 301, Section 1, Dr. Julstrom, Spring 2018
// Last Modified: 5 April 2018, 12:22
// Project 10: Comparing Three Sorting Algorithms
/* program description */

#include <iostream>
//#include "list.h"
using namespace std;

void initialize_Array(int, int, int[]);
int insertion_sort(int, int);
int merge_sort(int, int);
int quick_sort(int, int);

int ARRAYMAX = 5000;
int main()
{
	int numOfValues, seedNum;
	int mergeArray[ARRAYMAX], quickArray[ARRAYMAX], insertionArray[ARRAYMAX];
	char choice, print;

	do{
		cout << "Enter the number of values to generate and sort, between 1 and 5000: ";
		cin >> numOfValues;
		cout << "Enter an integer seed value: ";
		cin >> seedNum;
		//cout << "Print the values? ";
		//cin >> print;

		//randTest(array, numOfValues, seedNum);
		// For loop initializes all three arrays;
		initialize_Array(numOfValues, seedNum, mergeArray);
		initialize_Array(numOfValues, seedNum + 1, insertionArray);
		initialize_Array(numOfValues, seedNum +2, quickArray);
		
		cout << "\n\nInsertion Sort Count = ";
		cout << "\nMerge Sort Count = ";
		cout << "\nQuick Sort count = \n\n";
		
		cout << "Contents of mergeArray: ";
		for(int i = 0; i < numOfValues; i++)
			cout << mergeArray[i] << " ";
		
		cout << "\n\nContents of insertionArray: ";
		for(int i = 0; i < numOfValues; i++)
			cout << insertionArray[i] << " ";
			
		cout << "\n\nContents of quickArray: ";
		for(int i = 0; i < numOfValues; i++)
			cout << quickArray[i] << " ";
		
		cout << "\n\nEnter E to exit or any other key to run again: ";
		cin >> choice;
	} while (choice != 69 && choice != 101);

	cout << "END\n";

	return 0;
}
/********************************************************************************************/
void initialize_Array(int size, int seed, int array[])
{
	srand(seed);
	for (int index = 0; index < size; index++)
	{
		int n = rand() % 4999 + 1;
		//cout << n << " ";
		array[index] = n;
	}
}
/*
****************************************************************************************
int insertion_sort(int size, int seed)
{
	int a[size];
	for(int index = 0; index < size; index++)
	{
		int n = rand() % 4999 + 1;
		a[index] = n;
	}
}
****************************************************************************************
int merge_sort()
{

}
****************************************************************************************
int quick_sort()
{

}
****************************************************************************************

*/
