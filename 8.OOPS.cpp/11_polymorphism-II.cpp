#include <bits/stdc++.h>
using namespace std;
// Operator overloading -> plus(+) sign se subtraction kr denge
class param
{
public:
    int val;
    void operator+(param &obj2)
    {
        int value1 = this->val;
        int value2 = obj2.val;
        cout << (value1 - value2) << endl;
    }
};
int main() {
    param obj1, obj2;
    obj1.val = 7;
    obj2.val = 2;
    obj1 + obj2;

    return 0;
}