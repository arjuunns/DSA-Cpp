#include <bits/stdc++.h>
using namespace std;
class animal
{
public:
    virtual void speak() // if i mark parent func virtual then the func in child class will be called
    {
        cout << "speaking" << endl;
    }
};
class dog : public animal
{
public:
    void speak() // function over-riding
    {
        cout << "barking" << endl;
    }
};
int main() // note : whether you are upcasting or downcasting, the method of that class will be called to which the pointer belongs
{
    // animal a1;
    // dog d1;
    // a1.speak();
    // d1.speak();

    // UPCASTING
    animal *x = new dog(); // in this case ptr is of parent class and objet is of dog type therefore func of parent class will be called.
    x->speak();            // speaking will be the output
                           // if i mark parent func virtual then the func in child class will be called

    // DOWNCASTING 
    dog *b=(dog*)new animal();
    b->speak();
    // outputs gets reversed if you use virtual keyword in the parent method
    return 0;
}