#include <iostream>
using namespace std;

void insertionSort(int[], int);

const int SIZE = 6;

int main()
{
	int array[SIZE] = {32, 4, 75, 69, 88, 1};
	
	cout << "Initial array: \n";
	for(int i = 0;i < SIZE;i++)
		cout << array[i] << " ";
	cout << "\n";
	
	//call sort
	
	cout << "After sort: \n";
	for(int i = 0;i < SIZE;i++)
		cout << array[i] << " ";
	cout << endl;
	
	return 0;
}
/****************************************************************************************/
void insertionSort(int a[], int n)
{

}
/****************************************************************************************/
