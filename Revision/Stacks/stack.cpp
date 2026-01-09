#include <bits/stdc++.h>
using namespace std;
class MyStack{
    int capacity;
    int size;
    int top;
    int *arr;
    public :
    MyStack(){
        capacity = 100;
        size = 0;
        top = -1;
        arr = new int[capacity];
    }
    void push(int element){
        if(!isFull()) arr[++top] = element;
        size++;
    }
    void pop(){
        if(!isEmpty()) top--;
        size--;
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top>=capacity-1;
    }
    int sizeOfStack(){
        return top+1;
    }
    void display(){
        cout<<"Your Current stack is : ";
        int tempTop = top;
        while(tempTop!=-1) {
            cout<<arr[tempTop]<<" ";
            tempTop--;
        }
        cout<<endl;
    }
    int peek(){
        if(!isEmpty()) return arr[top];
    }

};
int main() {
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.display();
    return 0;
}