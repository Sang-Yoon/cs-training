#include <iostream>

struct Node
{
	int data;
    Node* next;
};

class LinkedListStack
{
public:
	LinkedListStack() {
        std::cout << "Linked List Stack implementation in c++" << std::endl;
        head = NULL;
        stack_size = 0;
    }
    ~LinkedListStack() { /*delete*/ }
    void push(int val) {
        Node* node = new Node();
        node->data = val;
        node->next = head;
        head = node;
        stack_size += 1;
    }
    int pop() {
        if(head == NULL){std::cout << "Stack is empty" << std::endl;}
        else{
            Node* kill = head;
            head = head->next;
            int value = kill->data;
            delete kill;
            stack_size -= 1;
            return value; //반환, 소멸
            }
    }
    int size() {
        std::cout << "stack_size : " << stack_size << std::endl;
        return stack_size;}
private:
	Node* head;
    int stack_size;
};

int main() {
    LinkedListStack stack;
    stack.push(1);
    stack.push(2);
    stack.size();
    stack.pop();
    stack.size();
    return 0;
}
