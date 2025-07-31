#include <bits/stdc++.h>
using namespace std;
void sortStack(int element,stack<int>&st){
    if(st.size()==1 or element>st.top()){
        st.push(element);
        return;
    } 
}
int main() {
    stack<int> st1;
    st1.push(3);
    st1.push(1);
    st1.push(5);
    st1.push(2);
    st1.push(0);
    sortStack(st1.top(),st1); // at top => max , bottom => min
    stack<int>st2;
    st2.push(st1.top());
    st1.pop();
    while(!st1.empty()){
        int curr = st1.top();
        st1.pop();
        while(st2.top()>curr){
            st1.push(st2.top());
            st2.pop();
        }
        st2.push(curr);
    }
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    return 0;
}