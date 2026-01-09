#include <bits/stdc++.h>
using namespace std;
class MyQueue{
    int capacity;
    int front;
    int back;
    int *arr;
    public:
    MyQueue(){
        this->capacity=1000;
        this->front=-1;
        this->back=-1;
        this->arr= new int[this->capacity];
    }
    void enqueue(int val){
        if(isEmpty()){
            back++;
            front++;
            arr[back] =val;
        }
        else if(!isFull()){
            arr[++back] = val;
        }
    }
    void dequeue(){
        if(!isEmpty()){
           front++;
        }
    }
    int sizee(){
        return back-front+1;
    }
    int peek(){
        return arr[front];
    }
    bool isEmpty(){
        if(front==-1 and back==-1) return true;
        else if(front>back) return true;
        return false;
    }
    bool isFull(){
        return front>=capacity-1;
    }
    void display(){
        int temp = front;
        while(temp<= back){
            cout<<arr[temp++]<<" ";
        }
    }
};
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
class MyQueue2{
    node* front;
    node* back;
    int size=0;
    public:
    MyQueue2(){
        this->front = new node(-1);
        this->back = new node(-1);
        size=0;
    }
    void enqueue(int val){

            node* newNode = new node(val);
            back->next=newNode;
            back=newNode;
            size++;
            if(!front->next) front = newNode;
    }
    void dequeue(){
        if(!isEmpty()){
           front=front->next;
           size--;
        }
    }
    int sizee(){
        return size;
    }
    int peek(){
        return front->data;
    }
    bool isEmpty(){
        return size<=0;
    }
    void display(){
        node* temp = front;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main() {
    MyQueue2 q;
    q.enqueue(1);
    q.display();
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.dequeue();
    q.display();
    cout<<endl;
    cout<<q.peek()<<endl;
    cout<<q.sizee()<<endl;

    return 0;
}