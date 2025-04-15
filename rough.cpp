#include <bits/stdc++.h>
using namespace std;

void insertInSortedStack(stack<int>& st, int element); // Function declaration

void sortStack(stack<int>& st, int element) {
    if (!st.empty()) return;
    int top = st.top();
    st.pop();
    sortStack(st, element);
    insertInSortedStack(st, top);
}

void insertInSortedStack(stack<int>& st, int element) {
    if (st.empty() or element > st.top()) {
        st.push(element);
        return;
    }
    int top = st.top();
    st.pop();
    insertInSortedStack(st, element); // Corrected recursive call
    st.push(top);
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(5);
    st.push(2);
    st.push(0);
    sortStack(st, st.top());
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}