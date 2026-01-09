#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val) // T.C = O(logn) -> comparisons with i/2
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return; // we found the correct position of new element
        }
    }
    void remove() // deletes the root node => Time Complexity -> O(logn)
    {
        if (!size)
        {
            cout << "Nothing to remove" << endl;
            return;
        }
        arr[1] = arr[size];
        size--; // last element automatically deleted
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else // we found the correct position
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
    }
};
void heapify(int arr[], int n, int i) // Works in O(n) average time complexity || assume that this function adjusts arr[i] to its correct position
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n and arr[largest] < arr[left])
    {
        swap(arr[i], arr[largest]);
        largest = left;
        heapify(arr, n, largest); // adjusts the newly adjusted element further down the heap
    }

    else if (right <= n and arr[largest] < arr[right])
    {
        swap(arr[i], arr[largest]);
        largest = right;
        heapify(arr, n, largest); // adjusts the newly adjusted element further down the heap
    }
}
void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]); // step1 : swap
        size--;
        heapify(arr, size, 1); // correct position pe phochao
    }
}
int main()
{
    heap h;
    for(int i=1;i<=11;i++){
       h.insert(i);
    }
    // for(int i=12;i<=111;i++){}
    h.print();
    // cout << endl;
    // int arr[6] = {-1, 54, 53, 55, 52, 50};
    // int n = 5;
    // for (int i = n / 2; i > 0; i--) // ignoring the leaf nodes
    // {
    //     heapify(arr, n, i); // n times O(logn)
    // }

    // heapSort(arr, n);

    // for (int i = 1; i <= n; i++)
    //     cout << arr[i] << " ";

    return 0;
}