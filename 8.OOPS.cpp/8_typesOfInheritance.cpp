#include <bits/stdc++.h>
using namespace std;
class fruit // Parent
{
public:
    string name;
    int sweetness;
    int cost;
};
class mango : public fruit // Child
{
public:
    string colour;
};
class mango : public fruit // Child
{
public:
    string colour;
};
class alphanso : public mango // Multilevel inheritance => Grand child : fruit => mango => alphonso
{
public:
    int sugarlevel;
};
int main()
{
    alphanso a1;
    cout<<a1.name<<a1.sweetness<<a1.cost<<a1.colour<<a1.sugarlevel;
    return 0;
}