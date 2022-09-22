#include <iostream>

struct Node
{
	int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList
{
public:
	DoublyLinkedList() {
        std::cout << "Doubly Linked List implementation in c++" << std::endl;
        head = NULL;
        list_size = 0;
        
    }
    ~DoublyLinkedList() { /*delete*/ }
    void push_head(int val) {
        Node* node = new Node();
        node->data = val;
        node->next = head;
        head = node;
        list_size += 1;
    }
    int pop_head() {
        int value = 0;
        if(head == NULL){std::cout << "List is empty" << std::endl;}
        else{
            Node* kill = head;
            head = head->next;
            value = kill->data;
            delete kill;
            list_size -= 1;
            }
        std::cout << "Data : " << value << std::endl;
        return value;
    }
    void push_middle(int index, int val) {
        Node* node = new Node();
        Node* cur = head;
        for(int i=0; i<index-1; i++)
        {
            cur = cur->next; 
        }
        node->next = cur->next;
        node->prev = cur;
        node->data = val;
        cur->next = node;
        node->next->prev = node;
        list_size += 1;
    }
    int pop_middle(int index) {
        int value = 0;
        Node* cur = head;
        for(int i=0; i<index-1; i++)
        {
            cur = cur->next;
        }
        Node* kill = cur->next;
        cur->next = kill->next;
        kill->next->prev = cur;
        value = kill->data;
        delete kill;
        list_size -= 1;
        std::cout << "Data : " << value << std::endl;
        return value;
    }
    int size() {
        std::cout << "list_size : " << list_size << std::endl;
        return list_size;}
private:
	Node* head;
    Node* garb_head;
    int list_size;
};

int main() {
    DoublyLinkedList list;
    list.push_head(1);
    list.push_head(2);
    list.push_head(3);
    list.push_middle(1, 10);
    list.size();
    list.pop_middle(1);
    list.size();
    return 0;
}
