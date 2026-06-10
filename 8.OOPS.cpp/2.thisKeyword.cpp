#include <bits/stdc++.h>
using namespace std;
class Animal
{ // IMP: this-> is a pointer to current object
public:
    int weight;
    void setWeight(int weight)
    {
        this->weight = weight; // this->weight means weight which is a member of class or humne class ke kisi object dog me paramter vala weight ki value store kar di
    }
    int GetWeight()
    {
        return weight;
    }

} dog;
int main()
{
    dog.setWeight(55);
    cout << dog.GetWeight();
    return 0;
}