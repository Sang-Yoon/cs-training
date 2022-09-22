#include <iostream>

struct Node
{
	int data;
    Node* next;
};

class LinkedListQueue
{
public:
	LinkedListQueue() {
        std::cout << "Linked List Queue implementation in c++" << std::endl;
        front = NULL;
        rear = NULL;
        queue_size = 0;
    }
    ~LinkedListQueue() { /*delete*/ }
    void push(int val) {
        Node* node = new Node();
        node->data = val;
        node->next = rear;
        rear = node;
        queue_size += 1;
    }
    int pop() {
        if(front == NULL){std::cout << "Queue is empty" << std::endl;}
        else{
            front = front->next;
            queue_size -= 1; //반환, 소멸
            }
        return 0;
    }
    int size() {
        std::cout << "queue_size : " << queue_size << std::endl;
        return queue_size;}
private:
	Node* front;
    Node* rear;
    int queue_size;
};

int main() {
    LinkedListQueue queue;
    queue.push(1);
    queue.push(2);
    queue.size();
    queue.pop();
    queue.size();
    return 0;
}
