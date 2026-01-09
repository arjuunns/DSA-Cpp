#include <bits/stdc++.h> // postfix : v1_v2_op
using namespace std;
int priority(char op)
{
    if (op == '*' or op == '/')
        return 2;
    return 1;
}
int main()
{
    string postfix = "9-(5+3)*4/6"; // 953+4*6/-
    stack<string> val;
    stack<char> op;
    for (int i = 0; i < postfix.size(); i++)
    {
        char ch = postfix[i];
        if (ch >= 48 and ch <= 57)
        {
            string s = "";
            s += ch;
            val.push(s);
        }
        else if (op.empty() or ch == '(' or op.top() == '(')
            op.push(ch);
        else if (ch == ')')
        {
            while (op.top() != '(')
            {
                string v2 = val.top();
                val.pop();
                string v1 = val.top();
                val.pop();
                char o = op.top();
                string res = "";
                res += v1;
                res += v2;
                res += o; // order changed
                op.pop();
                val.push(res);
            }
            op.pop(); // '(' removed
        }
        else
        {
            while (priority(op.top()) >= priority(ch))
            {
                string v2 = val.top();
                val.pop();
                string v1 = val.top();
                val.pop();
                char o = op.top();
                string res = "";
                res += v1;
                res += v2;
                res += o;
                op.pop();
                val.push(res);
            }
            op.push(ch);
        }
    }
    while (val.size() > 1)
    {
        string v2 = val.top();
        val.pop();
        string v1 = val.top();
        val.pop();
        char o = op.top();
        string res = "";
        res += v1;
        res += v2;
        res += o;
        op.pop();
        val.push(res);
    }
    cout << val.top();
    return 0;
}