// maxheap utalized for ascending order sorting
#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

void Swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

void InsertMaxHeap (vector<int>& vec, int value) {
    vec.push_back (value);
    int i = vec.size()-1;
    
    while (i>1){
        int parent_index = (int)floor((i-1)/2);
        if(vec[parent_index] < vec[i]) {
            Swap(vec[parent_index], vec[i]);
            i=parent_index;
        }
        else    return ;
    }
}

void InsertMinHeap (vector<int>& vec, int value) {
    vec.push_back (value);
    int i=vec.size()-1;

    while (i>1){
        int parent_index = (int)floor((i-1)/2);
        if(vec[parent_index] > vec[i]) {
            Swap(vec[parent_index], vec[i]);
            i=parent_index;
        }
        else    return ;
    }
}

void Print(vector<int> a) {
    for(int i=0;i<a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int max(vector<int>vec, int a, int b) {
    return (vec[a] > vec[b])? a : b;
}

void deletem(vector<int>& vec, int& num) {
    // first element is replaced by last element

    // cout<<vec.front()<<" ";
    num = vec.front();
    vec.front() = vec[vec.size()-1];
    vec.pop_back();
    // remove the last element from last
    int parent = 0;
    int leftchild=2*parent + 1;
    int rightchild=2*parent + 2;
    int maxi=0;
    //top to bottom
    while (leftchild < vec.size() || rightchild < vec.size()) {

        if(leftchild >= vec.size()) 
            maxi = rightchild;
        else if (rightchild >= vec.size())
            maxi = leftchild;
        else
            maxi = max(vec, leftchild, rightchild);

        if (vec[maxi] > vec[parent]) {
            Swap (vec[maxi], vec[parent]);

            parent = maxi;
            leftchild = 2*parent + 1;
            rightchild = 2*parent + 2;
        }
        else return ;
    }
}
void maxheap() {
    vector<int> arr;
    InsertMaxHeap(arr, 70);
    InsertMaxHeap(arr, 50);
    InsertMaxHeap(arr, 40);
    InsertMaxHeap(arr, 45);
    InsertMaxHeap(arr, 35);
    InsertMaxHeap(arr, 39);
    InsertMaxHeap(arr, 16);
    InsertMaxHeap(arr, 10);
    InsertMaxHeap(arr, 9);
    Print(arr);
    InsertMaxHeap(arr, 60);
    Print(arr);
    cout << "\n-----------------------------\n"
         << "Heap sort\n"
         << "----------------------------" << endl;
    int sorted_arr[arr.size()];
    int N;
    int pos = N = arr.size();
    int num;
    while(!arr.empty()){
        deletem(arr, num);
        sorted_arr[--pos] = num;
    }

    for (int i=0; i<N; i++) cout<<sorted_arr[i]<<" ";
    // ascending sort
    // for descending sorting just store the arr as it is
    // from 0 to size-1
}

void minheap() {
    vector<int> vec;
    InsertMinHeap(vec, 10);
    InsertMinHeap(vec, 15);
    InsertMinHeap(vec, 19);
    InsertMinHeap(vec, 20);
    InsertMinHeap(vec, 30);
    InsertMinHeap(vec, 25);
    InsertMinHeap(vec, 39);
    InsertMinHeap(vec, 23);
    InsertMinHeap(vec, 40);
    InsertMinHeap(vec, 35);
    Print(vec);
}



int main() {
    maxheap();
    cout<<endl;
    // minheap();
    return 0;
}