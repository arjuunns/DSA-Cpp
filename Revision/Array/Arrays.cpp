#include <bits/stdc++.h>
using namespace std;
// const int size = 1e2;
class MyArray{
    int size;
    int capacity;
    int *arr;
    public:
    MyArray(){}
    MyArray(int capacity){
        this->capacity = capacity;  
        this->size = 0;    
        arr = new int[capacity]; 
    }
    void Display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void Insert(int val,int pos){
        for(int i=size;i!=pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos]=val;
        size++;
    }
    void Delete(int pos){
        for(int i = pos;i<size;i++){
            arr[i] = arr[i+1];
        }
        size--;
    }
    void LinearSearch(int target){
        bool flag = false;
        for(int i=0;i<size;i++){
            if(arr[i]==target) {
                flag = true;
                cout<<"The element "<<target<<" is present at index "<<i<<endl;
            }
        }
        if(!flag) cout<<"Element not found!!"<<endl;
    }
    ~MyArray(){
        delete []arr;
        cout<<"Array deleted"<<endl;
    } 
};
int main() {
    MyArray arr(100);
    arr.Insert(0,0);
    arr.Insert(1,1);
    arr.Insert(2,2);
    arr.Insert(3,3);
    arr.Insert(4,4);
    arr.Insert(5,5);
    arr.Delete(2);
    arr.Delete(0);
    arr.Display();
    return 0;
}