#include <bits/stdc++.h>
using namespace std;
class Animal
{ // IMP: this-> is a pointer to current object
    // int weight;
    // void setWeight(int weight)
    // {
    //     this->weight = weight; // this->weight means weight which is a member of class or humne class ke kisi object dog me paramter vala weight ki value store kar di
    // }
    // int GetWeight()
    // {
    //     return weight;
    // }
    //   Animal(){
    //     cout<<"this is a private constructor"<<endl;
    // }
   
    // void fun1(){
    // }
    // public:
    // void fun(){

    //     cout<<"HAVING FUN!!"<<endl;
    // }

} dog;
int main()
{
    int a = 10;
    int &ref = a;  // ref is a reference to variable a
    ref = 20;      // Changes the value of 'a' to 20
    cout << a;     // Outputs 20

}