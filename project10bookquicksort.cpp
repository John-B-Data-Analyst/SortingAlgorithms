// Created By: John Blee 3 April 2018
// CSCI 301, Section 1, Dr. Julstrom, Spring 2018
// Last Modified: 6 April 2018, 16:49
// Project 10: Comparing Three Sorting Algorithms
/* program description */

#include <iostream>
//#include "list.h"
using namespace std;

void printArray(int [], int);
void exchange(int &, int &);
void initialize_Array(int, int, int[]);
int insertion_sort(int, int);
int merge_sort(int, int);
int partition(int [], int, int);
void quick_sort(int[], int, int);



int ARRAYMAX = 5000;
int main()
{
	int numOfValues, seedNum, mergeOperations, insertionOperations, quickOperations;
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
		initialize_Array(numOfValues, seedNum /*+ 1*/, insertionArray);
		initialize_Array(numOfValues, seedNum /*+2*/, quickArray);
		
		// call merge sort
		// call insertion sort
		// call quick sort
		
		cout << "\n\nInsertion Sort Count = " << insertionOperations;
		cout << "\nMerge Sort Count = " << mergeOperations;
		cout << "\nQuick Sort count = " << quickOperations << "\n\n";
		
		cout << "Contents of mergeArray: ";
		printArray(mergeArray, numOfValues);
				
		cout << "\n\nContents of insertionArray: ";
		printArray(insertionArray, numOfValues);
					
		cout << "\n\nContents of quickArray: ";
		printArray(quickArray, numOfValues);
				
		cout << "\nCalling quick_sort\n";
		quick_sort(quickArray, 0, numOfValues - 1);
		
		cout << "\nContents of quickArray after quick_sort: ";
		printArray(quickArray, numOfValues);
		
		cout << "\nInsertion Sort count = " << "\n";
		cout << "Merge Sort count = " << "\n";
		cout << "Quick Sort count = " << "\n";
			
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
		int n = rand() % 10; //% 4999 + 1;
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
int partition(int a[], int low, int high)
{
	int pivotValue, pivotIndex, mid;
	mid = (low + high) / 2;
	exchange(a[low], a[mid]);
	pivotIndex = low;
	pivotValue = a[low];
	for(int scan = low + 1; scan <= high; scan++)
	{
		if(a[scan] < pivotValue)
		{
			pivotIndex++;
				exchange(a[pivotIndex], a[scan]);
		}
	}
	exchange(a[low], a[pivotIndex]);
	return pivotIndex;
}
/****************************************************************************************/
void quick_sort(int a[], int low, int high)
{
	cout << "\nbeginning of quick sort function:\n";
	printArray(a, high);
	int pivotPoint;
	if(low < high)
	{
		pivotPoint = partition(a, low, high);
		quick_sort(a, low, pivotPoint - 1);
		quick_sort(a, pivotPoint + 1, high);
	}
}

/****************************************************************************************/
void exchange(int &i, int &j)
{
	int temp = i;
	i = j;
	j = temp;
}
/****************************************************************************************/
void printArray(int a[], int n)
{
	for(int i = 0;i < n;i++)
		cout << a[i] << " ";
}
/****************************************************************************************/
