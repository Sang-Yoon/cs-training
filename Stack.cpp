#include <iostream>

class MyStack
{
private:
    int a[10];
    int index;
public:
    MyStack() {
        std::cout << "Stack Implementation in c++" << std::endl;
        index=-1;
    }
    ~MyStack() {}; // deconstructor

    void push(int val) {
        if(isFull()){std::cout << "Full" << std::endl;}
        else{a[++index] = val;}
    }

    void pop() {
        if (isEmpty()){std::cout << "Empty" << std::endl;}
        else{a[index--] == 0;}
    }

    int top() {
        if (!isEmpty()) {return a[index];}
    }

    bool isEmpty() {return index == -1;}
    bool isFull() {return index == 9;}
    void print() {
        for(int i=0;i<index+1;++i)
            std::cout << a[i] << std::endl;
    }
};

int main() {
    MyStack stack;
    for(int i=10;i>-1;i--)
        stack.push(i);
    stack.print();

    for(int i=0;i<11;i++)
        stack.pop();
    stack.print();
}
