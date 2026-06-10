#include <bits/stdc++.h>
using namespace std;
class animal{
    public:
    int age;
    int weight;
    void eat(){
        cout<<"Eating"<<endl;
    }
};

//Inheritance :
class dog:public animal{
};

int main() {
    dog pillu; 
    pillu.eat();   
    return 0;
}