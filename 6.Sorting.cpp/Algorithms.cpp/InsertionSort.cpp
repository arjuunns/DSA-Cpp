#include <iostream>
#include <vector>
using namespace std; // Stable Sort
// Repeatedly take elements from unsorted subarray and insert in sorted subarray at its correct position
void InsertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i]; 
        int j = i - 1;
        while (j >= 0 and arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}
int main()
{   // Best Case Time Complexity : O(N)
    // Time Complexity : O(N*N) & Space Complexity : O(1)
    int n;
    cout << "Enter thr size of the array :\n";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of the array :";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    InsertionSort(v);
    cout << "Sorted Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}