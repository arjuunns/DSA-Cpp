#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int front;
    int back;
    vector<int> v;
    int currSize;
    int totalSize;

public:
    Queue(int n)
    {
        this->v.resize(n);
        this->front = -1;
        this->back = -1;
        this->currSize = 0;
        this->totalSize = n;
    }
    void enqueue(int data)
    {
        if (isFull())
            return;
        this->back = (this->back + 1) % this->totalSize;
        this->v[this->back] = data;
        this->currSize++;
    }
    void dequeue()
    {
        if (isEmpty())
            return;
        this->front = (this->front + 1) % this->totalSize;
        this->currSize--;
    }
    int getfront()
    {
        if (this->front == -1)
            return -1;
        return this->v[this->front];
    }
    bool isEmpty()
    {
        return this->currSize == 0;
    }
    bool isFull()
    {
        return this->currSize == this->totalSize;
    }
};
int main()
{
    Queue qu(3);
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    while (!qu.isEmpty()) {
        cout << qu.getfront() << " ";
        qu.dequeue();
    }
    return 0;
}