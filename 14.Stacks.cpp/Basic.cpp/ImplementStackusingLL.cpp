#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node()
    {
        this->data = -1;
        this->next = nullptr;
    }
    node(int data, node *next)
    {
        this->data = data;
        this->next = next;
    }
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class stacks
{
    node *head;
    int capacity;
    int currSize;

public:
    stacks(int capacity)
    {
        this->capacity = capacity;
        this->currSize = 0;
        this->head = nullptr;
    }
    bool isEmpty()
    {
        return this->head == nullptr;
    }
    bool isFull()
    {
        return this->currSize == this->capacity;
    }
    void push(int data) // insert at head
    {
        if (isFull())
            cout << "Stack is full !" << endl;
        node *newnode = new node(data, this->head);
        this->head = newnode;
        this->currSize++;
    }
    void pop() // delete head // 1 ->  2 ->  -> null
    {                         //                Head
                              //           temp
        if (isEmpty())
            cout << "Stack is empty !" << endl;
        node *temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->currSize--;
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Empty stack!" << endl;
        }
        return this->head->data;
    }
};
int main()
{
    stacks st(1);
    st.push(1);
    st.pop();
    st.pop();
    // st.push(2);
    // st.push(3);
    // cout << st.top() << endl;
    // st.pop();
    // cout << st.top() << endl;
    // st.push(4);
    // st.push(5);
    // st.push(6);
    // st.push(7);
    return 0;
}