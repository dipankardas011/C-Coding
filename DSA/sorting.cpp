#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

void Swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
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
                Swap(arr[j], arr[j + 1]);
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
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
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
            Swap(a[i], a[min]);
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
            Swap(a[left], a[right]);
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
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
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

void sort1(void);
void sort2(void);
void sort3(void);
void sort4(void);
void sort5(void);

int main()
{
    sort1();
    sort2();
    sort3();
    sort4();
    sort5();
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