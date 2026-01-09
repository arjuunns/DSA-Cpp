#include <bits/stdc++.h>
using namespace std;
bool isOperator(char ch){
    if((ch>='a' and ch<='z') or (ch>='A' and ch<='Z') or (ch >= '0' && ch <= '9')) return false;
    return true;
}
int priority(char ch){
    if(ch=='^') return 4;
    else if(ch=='/' or ch=='*') return 3;
    else if(ch=='+' or ch=='-') return 2;
    else return -1;
}
string infix_to_postfix(string infix){
    string postfix = "";
    int n = infix.size();
    stack<char>st;
    for(int i=0;i<n;i++){
        if(infix[i]=='(' or (st.empty() and isOperator(infix[i]))) st.push(infix[i]);
        else if(infix[i]==')'){
            while(st.top()!='('){
                postfix+=st.top();
                st.pop();
            }
            st.pop(); // removing opening bracket
        }
        else if(!st.empty() and isOperator(infix[i]) and (priority(infix[i])>priority(st.top()))) st.push(infix[i]);
        else if(isOperator(infix[i]) and (priority(infix[i])<priority(st.top()))){
            while(isOperator(infix[i]) and (priority(infix[i])<=priority(st.top()))){
            postfix+=st.top();
            st.pop();
        }
            st.push(infix[i]);
        }
        else postfix+=infix[i];

    }
    while(!st.empty()){
        postfix+=st.top();
        st.pop();
    }
    return postfix;
}
string infix_to_prefix(string infix){
    string prefix = "";





    return prefix;
}
string prefix_to_postfix(string prefix){
    string postfix = "";





    return postfix;
}
string prefix_to_infix(string prefix){
    string infix = "";





    return infix;
}
string postfix_to_infix(string postfix){
    string infix = "";





    return infix;
}
string postfix_to_prefix(string postfix){
    string prefix = "";





    return prefix;
}
int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout<<infix_to_postfix(infix);
    return 0;
}