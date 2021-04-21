// Created By: John Blee 3 April 2018
// CSCI 301, Section 1, Dr. Julstrom, Spring 2018
// Last Modified: 10 April 2018, 08:31
// Due April 10 2018
// Project 10: Comparing Three Sorting Algorithms
/* This program sorts three identical arrays that are the size of the users choosing and
are filled with a pseudo random number generator. The three arrays are sorted using insertion sort,
quick sort, and merge sort. The number of characteristic equations is counted during the sorting,
and the functions display the number of characteristic equations for each sort method at the end. */

#include <iostream>
using namespace std;

// function prototypes
void printArray(int [], int);
void exchange(int &, int &);
void initialize_Array(int, int, int[]);
int insertion_sort(int [], int, int &);
void new_merge_step(int [], int, int, int, int &);
int new_merge_sort(int [], int, int, int &);
void partition(int [], int, int, int, int &, int &, int &);
int quick_sort(int[], int, int, int &);

// global constant that represent the maximum size an array can be
const int ARRAYMAX = 5000;
int main()
{
	// variable declarations
	int numOfValues, seedNum, mergeOperations, insertionOperations, quickOperations;
	int mergeArray[ARRAYMAX], quickArray[ARRAYMAX], insertionArray[ARRAYMAX];
	char exitChoice, print;
	
	do{
		int numOfQuickOperations = 0, numOfInsertionOperations = 0, numOfMergeOperations = 0;
		
		cout << "Enter the number of values to generate and sort, between 1 and 5000: ";
		cin >> numOfValues;
		cout << "Enter an integer seed value: ";
		cin >> seedNum;
		cout << "Print the values? Y or N:\n";
		cin >> print;

		// fill each array with the entered parameters
		initialize_Array(numOfValues, seedNum, mergeArray);
		initialize_Array(numOfValues, seedNum, insertionArray);
		initialize_Array(numOfValues, seedNum, quickArray);
		
		// display the unsorted contents of the array if the user chose Y or y
		if(print == 'Y' || print == 'y')
		{
			cout << "Contents of mergeArray: ";
			printArray(mergeArray, numOfValues);
				
			cout << "\n\nContents of insertionArray: ";
			printArray(insertionArray, numOfValues);
					
			cout << "\n\nContents of quickArray: ";
			printArray(quickArray, numOfValues);
		}
		 
		// call quick sort
		quickOperations = quick_sort(quickArray, 0, numOfValues - 1, numOfQuickOperations);
		
		// show contents of of the sorted quickArray
		if(print == 'Y' || print == 'y')
		{
			cout << "\nContents of quickArray after quick_sort:\n";
			printArray(quickArray, numOfValues);
		}	
		
		// call insertion sort
		insertionOperations = insertion_sort(insertionArray, numOfValues, numOfInsertionOperations);
		
		// show contents of the sorted insertionArray
		if(print == 'Y' || print == 'y')
		{
			cout << "\nContents of insertionArray after insertion_sort:\n";
			printArray(insertionArray, numOfValues);
		}
		
		// call merge sort
		cout << "\nCalling merge_sort\n";
		mergeOperations = new_merge_sort(mergeArray, 0, numOfValues - 1, numOfMergeOperations);
		
		// show contents of sorted mergeArray
		if(print == 'Y' || print == 'y')
		{
			cout << "\nContents of mergeArray after merge_sort:\n";
			printArray(mergeArray, numOfValues);
		}
		
		// display characteristic operation results
		cout << "\n\nQuick Sort count = " << quickOperations;
		cout << "\nInsertion Sort Count = " << insertionOperations;
		cout << "\nMerge Sort Count = " << mergeOperations;
		
		// user enters choice to continue or exit
		cout << "\n\nEnter E to exit or any other key to run again: ";
		cin >> exitChoice;
	
	// repeat menu unless E or e is entered	
	} while (exitChoice != 69 && exitChoice != 101);

	cout << "END\n";

	return 0;
}
/********************************************************************************************/
// pre-condition: function is passed a non negative integer that represents the size of the array being passed, a 
// non negative integer that represents the seed value for the random number generator, and an array
// post-condition: The function fills the given array with random numbers. It returns no value.
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
// pre-condition: The function is passed an array, a non negative integer that is the size of the array, and
// an integer 'count' which is currently at zero. This counts the number of characteristic operations
// post-condition: The function sorts the given array, counts the number of characteristic operations that occur, and 
// returns the number of characteristic operations 
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
/****************************************************************************************/
// pre-condition: The function is passed an array, an integer that represents the lowest index of the array, an 
// integer that represents the largest index of the array, and an integer currently set to 0 that
// counts the number of characteristic operations
// post-condition: The function returns the number of characteristic operations that were performed 
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
// pre-condition: This is the merge step of merge sort. The function is passed an array, three integers that 
// represent low, mid and high of the array, and a counter
// post-condition: The function sorts the passed array and counts all of the characteristic operations
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
// pre-condition: The function is passed an array, integers that represent the low and high indices of the array,
// a integer that is the chosen pivot point for the partition step, and a counter that counts the
// number of characteristic operations
// post-condition: The function performs the partition step of quick sort. It moves all values less than 'pivot'
// to the left of pivot and all values greater than 'pivot' to the right of pivot. It returns nothing.
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
// pre-condition: The function is passed an array, the low and high indices of the array, and a counter
// post-condition: The function sorts the given array using the quick sort method, counts the number of characteristic
// equations, and returns that number as an integer
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
// pre-condition: The function is passed two values by reference. They are integers.
// post-condition: The function swaps the two values and returns nothing.
void exchange(int &i, int &j)
{
	int temp = i;
	i = j;
	j = temp;
}
/****************************************************************************************/
// pre-condition: The function is passed an array, and the size of the array.
// post-condition: The function prints the array to the screen, and returns no value.
void printArray(int a[], int n)
{
	for(int i = 0;i < n;i++)
		cout << a[i] << " ";
}
/****************************************************************************************/
