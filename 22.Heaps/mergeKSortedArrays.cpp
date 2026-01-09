#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    int row;
    int col;
    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare // custom comparator to use in min_heap
{ 
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKArr(vector<vector<int>> arr, int K)
{
    priority_queue<node *, vector<node *>, compare> minheap;
    // step1  : saare arrays k first elements insert kr do

    for (int i = 0; i < K; i++)
    {
        node *temp = new node(arr[i][0], i, 0);
        minheap.push(temp);
    }
    vector<int> ans;
    while (!minheap.empty())
    {
        node *temp = minheap.top();
        minheap.pop();
        ans.push_back(temp->data);
        int i = temp->row;
        int j = temp->col;
        if (j + 1 < arr[i].size())
        {
            node *next = new node(arr[i][j + 1], i, j + 1);
            minheap.push(next);
        }
    }
    return ans;
}

int main()
{
    vector<int> v1{1, 2, 3, 4};
    vector<int> v2{1, 5, 8, 9, 10, 12};
    vector<int> v3{1, 6};
    vector<vector<int>> arr;
    arr.push_back(v1);
    arr.push_back(v2);
    arr.push_back(v3);
    vector<int> ans = mergeKArr(arr, 3);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}