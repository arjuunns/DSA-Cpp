#include <bits/stdc++.h>
#include <queue>
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

void heapify(int arr[], int n, int i) // Works in O(n) average time complexity || assume that this function adjusts arr[i] to its correct position among ith to nth elements
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n and arr[largest] < arr[left])
        largest = left;

    if (right <= n and arr[largest] < arr[right]) // why can't we use else if
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
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
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.remove();
    h.remove();
    // h.print();
    cout << endl;
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--) // ignoring the leaf nodes
    {
        heapify(arr, n, i); // n times O(logn)
    }

    heapSort(arr, n); // O(nlogn)

    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";

    priority_queue<int> maxHeap;
    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(3);
    maxHeap.pop();
    cout << maxHeap.top();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // declare Minheap => priority_queue<data_type,vector<data_type>,greater<data_type>>min_heap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);
    cout << endl;
    cout << minHeap.top();
    return 0;
}