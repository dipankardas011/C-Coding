#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

void Print(int arr[], int N)
{

	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void BubbleSort(int *arr, int size)
{

	for (int i = 0; i < size; i++)
	{
		int flag = 0;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{ // ascending order
				std::swap(arr[j], arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			return; // already sorted
	}
}

void InsertionSort(int *arr, int size)
{

	for (int i = 1; i < size; i++)
	{
		/*this loop is for the 1...size*/
		int temp = arr[i];// sorting the i in temp
		int j = i - 1;	// the j is running backwards
		while (j >= 0 && arr[j] > temp)	// if the left side ele is > right side
		{
			// then copy the left in the right
			/*
			example: 1 4 3 2
			i = 3
			it is stored in temp "2"

			j = i-1 = 2
			j > "2" then becomes   1 4 '3' 3
			j--

			j = 1
			j > "2" then becomes   1 '4' 4 3
			j--

			j=0
			j< "2" here 1 < "2" so stop
			till here it is 1 4 4 3 as in the last we don't swap
			and so j+1 = 0+1 = 1 is replaced by "2" stored in t
			*/
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void SelectionSort(int *a, int size)
{

	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
			if (a[min] > a[j])
				min = j;

		if (min != i)
			std::swap(a[i], a[min]);
	}
}

int partition(int *a, int left, int right, int pivot)
{

	while (left <= right)
	{
		while (a[left] < pivot)
			left++;

		while (a[right] > pivot)
			right--;

		if (left <= right)
		{
			std::swap(a[left], a[right]);
			left++;
			right--;
		}
	}
	return left;
}

void QuickSort(int *a, int left, int right)
{

	if (left >= right)
		return;

	int pivot = a[(left + right) / 2];
	int index = partition(a, left, right, pivot);
	QuickSort(a, left, index - 1);
	QuickSort(a, index, right);
}

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]

	// Initial index of first subarray
	int i = 0;

	// Initial index of second subarray
	int j = 0;

	// Initial index of merged subarray
	int k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of
	// L[], if there are any
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(int *a, int left, int right)
{

	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

void heapify(int arr[], int i, int size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && arr[largest] < arr[left])
		largest = left;

	if (right < size && arr[largest] < arr[right])
		largest = right;

	if (largest != i)
	{
		std::swap(arr[largest], arr[i]);
		heapify(arr, largest, size);
	}
}

void HeapSort(int arr[], int N)
{
	for (int i = (N - 1) / 2; i >= 0; i--)
		heapify(arr, i, N);

	for (int i = N - 1; i > 0; i--)
	{
		// std::swap element from end and start
		std::swap(arr[0], arr[i]);
		heapify(arr, 0, i);
	}
}

void ShellSort(int a[], int n)
{
	for (int gap = n / 2; gap >= 1; gap /= 2)
	{

		for (int j = gap; j < n; j++)
		{

			for (int i = j - gap; i >= 0; i -= gap)
			{
				if (a[i + gap] > a[i])
					break;
				else
					std::swap(a[i + gap], a[i]);
			}
		}
	}
}

void CountSort(int arr[], int n, int pos)
{
	// here the pos denoted:
	// 1: one's place
	// 10: ten's place
	// 100: hundred's place
	// as number so [0...9]
	int count[10] = {0};

	for (int i = 0; i < n; i++)
	{
		++count[(arr[i] / pos) % 10];
	}

	for (int i = 1; i < 10; i++)
		count[i] = count[i] + count[i - 1];

	int b[n] = {0};
	for (int i = n - 1; i >= 0; i--)
		b[--count[(arr[i] / pos) % 10]] = arr[i];

	for (int i = 0; i < n; i++)
		arr[i] = b[i];

	return;
}

void RadixSort(int a[], int n)
{
	int maxi = a[0];
	for (int i = 1; i < n; i++)
		if (maxi < a[i])
			maxi = a[i];

	for (int pos = 1; maxi / pos > 0; pos *= 10)
		CountSort(a, n, pos);
}

void sort1(void);
void sort2(void);
void sort3(void);
void sort4(void);
void sort5(void);
void sort6(void);
void sort7(void);
void sort8(void);

int main()
{
	sort1();
	sort2();
	sort3();
	sort4();
	sort5();
	sort6();
	sort7();
	sort8();
	cout << "\n\n================================================" << endl;
	return 0;
}

void sort1()
{
	// bubble sort
	cout << "\n-----------------------------\n"
		 << "Bubble sort\n"
		 << "----------------------------" << endl;
	int ar[] = {45, 32, 87, 22, 1, 97, 12, 76, 90};
	int N = sizeof(ar) / sizeof(ar[0]);
	Print(ar, N);
	BubbleSort(ar, N);
	Print(ar, N);
}
void sort2()
{
	//insertion sort
	cout << "\n-----------------------------\n"
		 << "Insertion sort\n"
		 << "----------------------------" << endl;
	int a[] = {34, 564, 568, 2, 5, 98, 34};
	int N = sizeof(a) / sizeof(a[0]);
	Print(a, N);
	InsertionSort(a, N);
	Print(a, N);
}
void sort3()
{
	// seclection sort
	cout << "\n-----------------------------\n"
		 << "Selection sort\n"
		 << "----------------------------" << endl;
	int a[] = {7, 4, 10, 8, 3, 1};
	int N = sizeof(a) / sizeof(a[0]);
	Print(a, N);
	SelectionSort(a, N);
	Print(a, N);
}
void sort4()
{
	// Quick sort
	cout << "\n-----------------------------\n"
		 << "Quick sort\n"
		 << "----------------------------" << endl;
	int a[] = {2, 5, 6, 9, 33, 1, 243, 353};
	int N = sizeof(a) / sizeof(a[0]);
	Print(a, N);
	QuickSort(a, 0, N - 1);
	Print(a, N);
}
void sort5()
{
	// Merge sort
	cout << "\n-----------------------------\n"
		 << "Merge sort\n"
		 << "----------------------------" << endl;
	int a[] = {22323, 15, 126, 9, 213, 1113, 13, 53, 211};
	int N = sizeof(a) / sizeof(a[0]);
	Print(a, N);
	MergeSort(a, 0, N - 1);
	Print(a, N);
}
void sort6()
{
	// max heap to get ascending
	cout << "\n-----------------------------\n"
		 << "Heap sort\n"
		 << "----------------------------" << endl;
	int arr[] = {3, 7, 4, 9, 5, 2, 8};
	int N = sizeof(arr) / sizeof(arr[0]);
	Print(arr, N);
	HeapSort(arr, N);
	Print(arr, N);
}
void sort7()
{
	cout << "\n-----------------------------\n"
		 << "Shell sort\n"
		 << "----------------------------" << endl;
	int arr[] = {4, 143, 645, 132, 12, 5};
	int N = sizeof(arr) / sizeof(arr[0]);
	Print(arr, N);
	HeapSort(arr, N);
	Print(arr, N);
}
void sort8()
{
	cout << "\n-----------------------------\n"
		 << "Radix sort\n"
		 << "----------------------------" << endl;
	int arr[] = {432, 8, 530, 90, 88, 231, 11, 45, 677, 199};
	int N = sizeof(arr) / sizeof(arr[0]);
	Print(arr, N);
	RadixSort(arr, N);
	Print(arr, N);
}