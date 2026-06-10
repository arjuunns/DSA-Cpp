#include <bits/stdc++.h>
using namespace std;
class Animal
{
    // states/attributes
private:
    int weight;
    char gender;
    string name;
    // Behaviour/Methods

    void sleep()
    {
        cout << "sleeping" << endl;
    }

public:
    int age;
    void eat()
    {
        cout << "eating" << endl;
    }
    int getWeight()
    {
        return weight;
    }
    void setWeight(int w)
    {
        weight = w;
    }
};
int main()
{
    // Animal ramesh;
    // ramesh.name = "lion";
    // cout << ramesh.name << endl;
    // ramesh.setWeight(55);
    // cout << ramesh.getWeight();

    // Using Dynamic memory allocation in heap using pointers
    Animal *suresh = new Animal;
    (*suresh).age = 45;
    suresh->age = 50;
    // cout<<(*suresh).age;
    cout << suresh->age; // to access values stored in pointer use -> arrow operator
    suresh->eat();

    return 0;
}