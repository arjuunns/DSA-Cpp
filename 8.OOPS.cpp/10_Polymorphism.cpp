#include <bits/stdc++.h>
using namespace std;
class Maths  // Compile time polymorphism
{
public:   // function overloading 
    int sum(int a, int b) {
        cout << "I'm in first function : ";
        return a + b;
    }
    int sum(float a, int b) {
        cout << "I'm in second function : ";
        return a + b + 10;
    }
    int sum(int a, int b, int c) {
        cout << "I'm in third function : ";
        return a + b + c;
    }
};
int main()
{
    Maths add;
    cout << add.sum(2, 3) << endl;
    cout << add.sum(4.9f, 3) << endl;
    cout << add.sum(1, 2, 3) << endl;

    return 0;
}