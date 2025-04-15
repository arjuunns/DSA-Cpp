#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int>apples{1,3,5,2,3};  
    vector<int>capacity{10,3,3,2,1};
    sort(capacity.begin(),capacity.end());  
    reverse(capacity.begin(),capacity.end());
    int sum=0;
    int boxes=1;
    int j=0;
    for(int i=0;i<apples.size();i++){
        sum+=apples[i]; 
        while(sum>capacity[j]){ 
            boxes++; 
            sum=sum-capacity[j]; 
            j++; 
        }
    }
    cout<<boxes;
    return 0;
}