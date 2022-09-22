#include <iostream>

class MyQueue
{
private:
    int a[10];
    int index_front;
    int index_rear;
public:
    MyQueue() {
        std::cout << "Queue Implementation in c++" << std::endl;
        index_front=-1;
        index_rear=-1;
    }
    ~MyQueue() {}; // deconstructor

    void push(int val) {
        if(isFull()){std::cout << "Full" << std::endl;}
        else{a[++index_rear] = val;}
    }

    void pop() {
        if (isEmpty()){std::cout << "Empty" << std::endl;}
        else{a[++index_front] = 0;}
    }

    int front() {
        if (!isEmpty()) {return a[index_front];}
    }
    
    int rear() {
        if (!isEmpty()) {return a[index_rear];}
    }

    bool isEmpty() {return index_front == index_rear;}
    bool isFull() {return index_rear - index_front == 10;}
    void print() {
        for(int i=0;i<index_rear+1;++i)
            std::cout << a[i] << std::endl;
    }
};

int main() {
    MyQueue queue;
    queue.print();
    queue.push(10);
    queue.push(9);
    queue.push(8);
    queue.print();
    queue.pop();
    queue.print();
}
