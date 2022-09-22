#include <iostream>

const int queue_size = 4;

class MyQueue
{
private:
    int a[queue_size];
    int idx_front;
    int idx_rear;
public:
    MyQueue() {
        std::cout << "Queue Implementation in c++" << std::endl;
        idx_front=-1;
        idx_rear=-1;
    }
    ~MyQueue() {}; // deconstructor

    void enqueue(int val) {
        if(isFull()){std::cout << "Full" << std::endl;}
        else if(idx_rear == -1)
        {
            a[++idx_rear] = val;
        }
        else
        {
            idx_rear = (idx_rear + 1) % queue_size;
            a[idx_rear] = val;
        }
    }

    void dequeue() {
        if (isEmpty()){std::cout << "Empty" << std::endl;}
        else if(idx_front == -1)
        {
            a[++idx_front] = 0;
        }
        else
        {
            idx_front = (idx_front + 1) % queue_size;
            a[idx_front] = 0;
        }
    }

    int front() {
        if (!isEmpty()) {return a[idx_front];}
    }
    
    int rear() {
        if (!isEmpty()) {return a[idx_rear];}
    }

    bool isEmpty() {return idx_front == idx_rear;}
    bool isFull() {return abs(idx_rear - idx_front) == queue_size - 1;}
    void print() {
        if(isEmpty())
        {
            std::cout << "No Elements" << std::endl;
        }
        else
        {
            while(idx_front != idx_rear)
            {
                std::cout << a[idx_front + 1] << std::endl;
                idx_front = (idx_front + 1) % queue_size;
            }
        }
    }
};

int main() {
    MyQueue queue;
    queue.print();
    queue.enqueue(10);
    queue.enqueue(9);
    // queue.enqueue(8);
    // queue.enqueue(7);
    // queue.enqueue(6);
    queue.print();
    queue.dequeue();
    queue.print();
}
