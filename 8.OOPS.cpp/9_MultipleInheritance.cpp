#include <bits/stdc++.h>
using namespace std;
class mom
{
public:
    int height;
    int weight;
};
class dad
{
public:
    string colour;
    int weight;
};
class child : public mom, public dad
{
public:
    int intelligence;
};
int main()
{
    child pintu;
    // cout<<pintu.weight; // can't tell differnece that which weight is it the dad's or mom's
    cout << pintu.mom::weight; // child class inherited mom's weight
    cout << pintu.dad::weight; // child class inherited dad's weight
    cout << pintu.intelligence << pintu.height << pintu.colour << endl;
    return 0;
}