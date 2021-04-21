// Created By: John Blee 3 April 2018
// CSCI 301, Section 1, Dr. Julstrom, Spring 2018
// Last Modified: 6 April 2018, 16:49
// Project 10: Comparing Three Sorting Algorithms
/* program description */

#include <iostream>
//#include "list.h"
using namespace std;

void exchange(int[], int, int);
void initialize_Array(int, int, int[]);
int insertion_sort(int, int);
int merge_sort(int, int);
void partition(int [], int, int, int, int &, int &);
void quick_sort(int[], int, int);



int ARRAYMAX = 5000;
int main()
{
	int numOfValues, seedNum, mergeOperations, insertionOperations, quickOperations;
	int mergeArray[ARRAYMAX], quickArray[5] = {5, 4, 3, 2, 1}, insertionArray[ARRAYMAX];
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
		initialize_Array(numOfValues, seedNum /*+ 1*/, insertionArray);
		//initialize_Array(numOfValues, seedNum /*+2*/, quickArray);
		
		// call merge sort
		// call insertion sort
		// call quick sort
		
		cout << "\n\nInsertion Sort Count = " << insertionOperations;
		cout << "\nMerge Sort Count = " << mergeOperations;
		cout << "\nQuick Sort count = " << quickOperations << "\n\n";
		
		cout << "Contents of mergeArray: ";
		for(int i = 0; i < numOfValues; i++)
			cout << mergeArray[i] << " ";
		
		cout << "\n\nContents of insertionArray: ";
		for(int i = 0; i < numOfValues; i++)
			cout << insertionArray[i] << " ";
			
		cout << "\n\nContents of quickArray: ";
		for(int i = 0; i < numOfValues; i++)
			cout << quickArray[i] << " ";
		
		cout << "\nCalling quick_sort\n";
		quick_sort(quickArray, 0, 4);
		
		cout << "Contents of quickArray after quick_sort: ";
		for(int i= 0; i< /*numOfValues*/ 5; i++)
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
		int n = rand(); //% 4999 + 1;
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
*/
void partition(int a[], int low, int high, int pivot, int &i, int &j)
{
	int lastS1 = low - 1;
	int firstU = low;
	int firstS3 = high + 1;
	while(firstU < firstS3)
	{
		if(a[firstU] < pivot) // S1
			exchange(a, a[firstU++], a[++lastS1]);
		else if(a[firstU] == pivot) // S2
			firstU++;
		else // S3
			exchange(a, a[firstU], a[--firstS3]);
	}
	i = lastS1;
	j = firstS3;
}
/****************************************************************************************/

void quick_sort(int a[], int low, int high)
{
	cout << "Trace 1";
	int pivot;
	int lastS1, firstS3;
	if(low < high)
	{
		pivot = a[(low + high) / 2];
		partition(a, low, high, pivot, lastS1, firstS3);
		quick_sort(a, low, lastS1);
		quick_sort(a, firstS3, high);
	}
}

/****************************************************************************************/
void exchange(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
/****************************************************************************************/
