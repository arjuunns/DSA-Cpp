#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&st,int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int num = st.top();
    st.pop();
    insertAtBottom(st,element);
    st.push(num);
}

void insertAtCorrectPos(stack<int>&st,int element){
    if(st.empty() or st.top()>=element){
        st.push(element);
        return;
    }
    int num = st.top();
    st.pop();
    insertAtCorrectPos(st,element);
    st.push(num);
}

void reverseRecursive(stack<int>&st){
    if(st.size()<=1) return;
    int prev_top = st.top();
    st.pop();
    reverseRecursive(st); // recursively reverses the stack from curr_top till bottom
    insertAtBottom(st,prev_top);
}

void sortStack(stack<int>&st){
    if(st.size()<=1) return;
    int prev_top = st.top();
    st.pop();
    sortStack(st);
    insertAtCorrectPos(st,prev_top);
}
int main() {
    stack<int>st;
    // for(int i = 5;i>0;i--) st.push(i);
    // insertAtBottom(st,6);
    st.push(3);
    st.push(2);
    st.push(5);
    st.push(4);
    st.push(1);
    // reverseRecursive(st);
    sortStack(st);
    while(!st.empty()){
        cout<<" | " << st.top()<< " | "<<endl;
        st.pop();
    }
    return 0;
}