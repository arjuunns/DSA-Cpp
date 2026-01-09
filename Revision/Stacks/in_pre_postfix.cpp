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
string infix_to_postfix(string s){
    int n = s.size();
    stack<string>val;
    stack<char>op;
    for(int i=0;i<n;i++){
        char ch = s[i];
        if(isalnum(ch)) {
            string temp = "";
            temp+=s[i];
            val.push(temp);
        }
        else if(ch=='(') {
            op.push(ch);
        }
        else if((op.empty() and isOperator(ch)) or (!op.empty() and isOperator(ch) and priority(ch)>priority(op.top()))){
            op.push(ch);
        }
        else if(ch==')'){
            while(!op.empty() and !val.empty() and op.top()!='('){
                string v2 = val.top();val.pop();
                string v1 = val.top();val.pop();
                string temp = "";
                char opr = op.top();op.pop();
                temp = v1+v2+opr;
                val.push(temp);
            }
            op.pop();
        }
        else {
            while(!op.empty() and !val.empty() and priority(ch)<=priority(op.top())){
                string v2 = val.top();val.pop();
                string v1 = val.top();val.pop();
                string temp = "";
                char opr = op.top();op.pop();
                temp = v1+v2+opr;
                val.push(temp);
            }
        }
    }
     while(!op.empty()){
        string v2 = val.top(); val.pop();
        string v1 = val.top(); val.pop();
        char opr = op.top(); op.pop();
        string temp = v1 + v2 + opr;
        val.push(temp);
    }
    
    return val.top();
}

string infix_to_prefix(string infix){
    reverse(infix.begin(),infix.end());
    for(auto &ch : infix){
        if(ch=='(') ch=')';
        else if(ch==')') ch='(';
    }
    string prefix = infix_to_postfix(infix);
    reverse(prefix.begin(),prefix.end());
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
    cout<<infix_to_postfix(infix)<<endl;
    return 0;
}