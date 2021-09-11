#include <iostream>
#include <cmath>
#include <algorithm>

// must be sorted
bool BinarySearch(int arr[], int size, int key) {

    int left = 0;
    int right = size-1;
    int mid = 0;

    while (left <= right) {
        mid = (left + right)/2;
        if (key < arr[mid])
            right = mid-1;
        else if (key > arr[mid])
            left = mid+1;
        else
            return true;
    }
    return false;
}

bool compare(int i, int j ) {
    return (i<j);
}

int main() {
    int arr[] = {12, 45, 1, 46, 6, 88, 44};
    int N = sizeof(arr)/sizeof(arr[0]);
    std::sort(arr, arr+N, compare);
    std::cout<<"enter the element to be searched..  ";
    int key;
    std::cin>>key;
    (BinarySearch(arr,N,key))? std::cout<<"found!"<<std::endl :
                            std::cout<<"not found!"<<std::endl;
    return 0;
}