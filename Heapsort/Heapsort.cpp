#include<iostream>

using namespace std;


void shiftDown(int numbers[], int root, int bottom);
void heapSort(int numbers[], int ub)
{
	int i, temp;

	for (i = (int)ceil((ub / 2.0)) - 1; i >= 0; i--)
	{
		shiftDown(numbers, i, ub);
	}
	for (i = ub; i >= 1; i--)
	{
		temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		shiftDown(numbers, 0, i - 1);
	}
}

void shiftDown(int numbers[], int root, int bottom)
{
	int done, maxChild, temp;
	done = 0;
	while ((root * 2 + 1 <= bottom) && (!done))
	{
		if (root * 2 + 1 == bottom || numbers[root * 2 + 1] > numbers[root * 2 + 2])
			maxChild = root * 2 + 1;
		else
			maxChild = root * 2 + 2;
		if (numbers[root] < numbers[maxChild])
		{
			temp = numbers[root];
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else
			done = 1;
	}
}

int main()
{
	int numbers[20];
	int i, n;
	cout << "Enter the size of array" << endl;
	cin >> n;
	cout << "Enter the element to sort" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	cout << "After Sorting"<<endl;
	heapSort(numbers, n-1);
	for (i = 0; i < n; i++)
	{
		cout << numbers[i]<<endl;
	}
	return 0;
}