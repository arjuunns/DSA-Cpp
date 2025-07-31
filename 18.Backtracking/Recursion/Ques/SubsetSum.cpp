#include <bits/stdc++.h>
using namespace std;
void SubsetSum(vector<int> &arr, multiset<int> &ans, int i, int sum)
{
    if (i == arr.size()) { // T.C -> O(2^n * logn) and Space : O(n) recursive stack space + O(2^n) for set
        ans.insert(sum);
        return;
    }
    sum += arr[i];
    SubsetSum(arr, ans, i + 1, sum); // pick  //                                                     SubsetSum(arr,ans,i+1,sum+arr[i]); // other syntax
    sum -= arr[i];                   // remove the last included sum while backtracking
    SubsetSum(arr, ans, i + 1, sum); // not pick //                                                  SubsetSum(arr,ans,i+1,sum);
}
int main()
{
    vector<int> arr{2, 3, 4};
    multiset<int> ans;
    SubsetSum(arr, ans, 0, 0);
    for (auto x : ans) 
        cout << x << " ";
    return 0;
}