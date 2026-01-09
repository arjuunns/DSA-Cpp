#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(){
        data=-1;
        next=nullptr;
    }
    node(int d){
        data=d;
        next=nullptr;
    }
    node(int d,node* next){
        data= d;
        this->next = next;
    }
};
class MyStack{
    int capacity;
    int size;
    node *top;
    public :
    MyStack(){
        capacity = 100;
        size = 0;
        top = nullptr;
    }
    void push(int element){
        if(size<capacity){
            node * newNode = new node(element);
            newNode->next = top;
            top=newNode;
            size++;
        }
    }
    void pop(){
        if(!top) cout<<"Stack is empty!!"<<endl;
        node * temp = top;
        top=top->next;
        delete temp;
        size--;
    }
    bool isEmpty(){
        return !top;
    }
    bool isFull(){
        return (size>capacity);
    }
    int sizeOfStack(){
        return size;
    }
    void display(){
        cout<<"Your Current stack is : ";
        node * temp = top;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        
    }
    int peek(){
      if(!isEmpty()) return top->data;
      return -1;
    }

};
int main() {
    MyStack st;
    cout<<st.isEmpty()<<endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    cout<<st.isFull()<<" "<<st.isEmpty()<<endl;
    cout<<st.peek()<<endl;
    cout<<st.sizeOfStack()<<endl;
    st.push(5);
    st.display();
    return 0;
}