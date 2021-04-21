// Created By: John Blee 3 April 2018
// CSCI 301, Section 1, Dr. Julstrom, Spring 2018
// Last Modified: 9 April 2018, 11:39
// Project 10: Comparing Three Sorting Algorithms
/* program description */

#include <iostream>
//#include "list.h"
using namespace std;

void printArray(int [], int);
void exchange(int &, int &);
void initialize_Array(int, int, int[]);
int insertion_sort(int [], int, int &);
void new_merge_step(int [], int, int, int, int &);
int new_merge_sort(int [], int, int, int &);
//void merge_step(int [], int, int, int);
//void merge_sort(int [], int, int);
void partition(int [], int, int, int, int &, int &, int &);
int quick_sort(int[], int, int, int &);

int ARRAYMAX = 5000;
int main()
{
	int numOfValues, seedNum, mergeOperations, insertionOperations, quickOperations;
	int mergeArray[ARRAYMAX], quickArray[ARRAYMAX], insertionArray[ARRAYMAX];
	char choice, print;

	do{
		int numOfQuickOperations = 0, numOfInsertionOperations = 0, numOfMergeOperations = 0;
		
		cout << "Enter the number of values to generate and sort, between 1 and 5000: ";
		cin >> numOfValues;
		cout << "Enter an integer seed value: ";
		cin >> seedNum;
		cout << "Print the values? Y or N:\n";
		cin >> print;

		//randTest(array, numOfValues, seedNum);
		// For loop initializes all three arrays;
		initialize_Array(numOfValues, seedNum, mergeArray);
		initialize_Array(numOfValues, seedNum /*+ 1*/, insertionArray);
		initialize_Array(numOfValues, seedNum /*+2*/, quickArray);
		
		// call merge sort
		// call insertion sort
		// call quick sort
		
		if(print == 'Y' || print == 'y')
		{
			cout << "Contents of mergeArray: ";
			printArray(mergeArray, numOfValues);
				
			cout << "\n\nContents of insertionArray: ";
			printArray(insertionArray, numOfValues);
					
			cout << "\n\nContents of quickArray: ";
			printArray(quickArray, numOfValues);
		}
		 
		cout << "\n\nCalling quick_sort\n";
		quickOperations = quick_sort(quickArray, 0, numOfValues - 1, numOfQuickOperations);
		
		if(print == 'Y' || print == 'y')
		{
			cout << "\nContents of quickArray after quick_sort:\n";
			printArray(quickArray, numOfValues);
		}	
		
		cout << "\n\nCalling insertion_sort\n";
		insertionOperations = insertion_sort(insertionArray, numOfValues, numOfInsertionOperations);
		
		if(print == 'Y' || print == 'y')
		{
			cout << "\nContents of insertionArray after insertion_sort:\n";
			printArray(insertionArray, numOfValues);
		}
		
		cout << "\nCalling merge_sort\n";
		mergeOperations = new_merge_sort(mergeArray, 0, numOfValues - 1, numOfMergeOperations);
		
		if(print == 'Y' || print == 'y')
		{
			cout << "\nContents of mergeArray after merge_sort:\n";
			printArray(mergeArray, numOfValues);
		}
		
		cout << "\n\nQuick Sort count = " << quickOperations;
		cout << "\nInsertion Sort Count = " << insertionOperations;
		cout << "\nMerge Sort Count = " << mergeOperations;
		
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
		int n = rand() % 1000; //% 4999 + 1;
		//cout << n << " ";
		array[index] = n;
	}
}

/****************************************************************************************/
int insertion_sort(int a[], int n, int &count)
{
	
	for(int i = 1; i < n; i++)
	{
		int j = i - 1;
		int temp = a[i];

		count++;
		while(j >= 0 && temp < a[j])
		{
			count++;
			a[j + 1] = a[j];
			j--;;
		}

		a[j + 1] = temp;
	}
	return count;
}
/*
****************************************************************************************
void merge_sort(int a[], int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a, low, mid, high);
	}	
}

****************************************************************************************
*/
/****************************************************************************************/
int new_merge_sort(int arr[], int i, int j, int &count)
{
	int mid = 0;

	if(i < j)
	{
		mid = (i + j) / 2;
		new_merge_sort(arr, i, mid, count);
		new_merge_sort(arr, mid + 1, j, count);
		new_merge_step(arr, i, mid, j, count);
	}
	return count;
}
/****************************************************************************************/
void new_merge_step(int arr[], int i, int mid, int j, int &count)
{
	int temp[j];
	int l = i;
	int r = j;
	int m = mid + 1;
	int k = l;

	while(l <= mid && m <= r)
	{
		count++;
		if(arr[l] <= arr[m])
			temp[k++] = arr[l++];
		else
			temp[k++] = arr[m++];
	}
	while(l <= mid)
	{
		count++;
		temp[k++] = arr[l++];
	}
	while(m <= r)
	{
		count++;
		temp[k++] = arr[m++];
	}
	for(int i1 = i; i1 <= j; i1++)
	{
			
		arr[i1] = temp[i1];
	}
}
/****************************************************************************************/
void partition(int a[], int low, int high, int pivot, int &i, int &j, int &count)
{
	int lastS1 = low - 1;
	int firstU = low;
	int firstS3 = high + 1;
	while(firstU < firstS3)
	{
		count++;
		if(a[firstU] < pivot)
		{
			lastS1++;
			exchange(a[firstU], a[lastS1]);
			firstU++;
		}
		else if(a[firstU] == pivot)
			firstU++;
		else
		{
			firstS3--;
			exchange(a[firstU], a[firstS3]);
		}
	}
	i = lastS1;
	j = firstS3;
}
/****************************************************************************************/
int quick_sort(int a[], int low, int high, int &count)
{
	int pivot;
	int lastS1, firstS3;

	if(low < high)
	{
		pivot = a[(low + high) / 2];
		partition(a, low, high, pivot, lastS1, firstS3, count);
		quick_sort(a, low, lastS1, count);
		quick_sort(a, firstS3, high, count);
	}
	return count;	
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
