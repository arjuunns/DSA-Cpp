#include <bits/stdc++.h>
using namespace std;
class car{
    public:
    int engine;
    int seats;
    string name;
    car(){
        cout<<"default constructor called"<<endl;
    }
    car(int engine,int seats,string name){
        this->engine=engine;
        this->seats=seats;
        this->name=name;
    }
    ~car(){
        cout<<"car destructor"<<endl;
    }
};
class car1 : public car{
    public:
    int alloySize;
    car1(){
        cout<<"car1 constructor"<<endl;
    }

    car1(int alloySize){
        this->alloySize=alloySize;
        cout<<"car1 constructor"<<endl;
    }
    ~car1(){
        cout<<"car1 destructor"<<endl;
    }

};
int main() {
    car1 c(5);
    return 0;
}