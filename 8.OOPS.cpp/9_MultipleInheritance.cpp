#include <bits/stdc++.h>
using namespace std;
class mom
{
public:
    int height;
    int weight;
    string colour;
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
    pintu.height = 178;
    pintu.mom::colour = "Black";
    // cout << pintu.weight; // can't tell differnece that which weight is it the dad's or mom's => famously known as diamond problem
    // cout << pintu.mom::weight; // child class inherited mom's weight
    // cout << pintu.dad::weight; // child class inherited dad's weight
    cout << pintu.height << pintu.mom::colour << endl;
    return 0;
}