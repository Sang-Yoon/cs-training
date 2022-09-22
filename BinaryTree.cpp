#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define MAX_TREE_SIZE 16
#define NONE -1

// BinaryTree implemented as an array
class BinaryTree
{
public:
    BinaryTree() {
        std::cout << "Binary Tree Implementation in c++" << std::endl;
    }

    // Insert an element into the empty space with the smallest index.
    // Return `false` if the insertion fails because the tree is full.
    bool insert(int val) {
        if(isFull()){
            std::cout << "Tree is full" << std::endl;
            return false;
        }
        else{
            _size += 1;
            if(_size == 1){
                _tree[_size] = val;
                std::cout << "Root node : " << _tree[_size] << std::endl;
            }
            else{
                _tree[_size] = val;
                std::cout << "Value of node No." << _size << " : "<< _tree[_size] << std::endl;
            }
            return true;
        }
    }

    // Return the value of parent.
    // Return `-1` if the given index is the root.
    int get_parent(size_t index) {
        if(index == 0){
            std::cout << "Root doesn't have a parent" << std::endl;
            return -1;
        }
        else{
            if(index % 2 == 0){
                parent = _tree[index / 2];
                std::cout << "parent : " << parent << std::endl;
            }
            else{
                parent = _tree[int(floor(index / 2))];
                std::cout << "parent : " << parent << std::endl;
            }
            return parent;
        }
    }

    // Return the value of left child.
    // Return `-1` if the given index is a leaf.
    int get_left_child(size_t index) {
        if(index * 2 < _size){
            left_child = _tree[index * 2];
            std::cout << "left child : " << left_child << std::endl;
        }
        else{
            return -1;
        }
        return 0;
    }

    // Return the value of right child.
    // Return `-1` if the given index is a leaf.
    int get_right_child(size_t index) {
        if(index * 2 <= _size){
            right_child = _tree[index * 2 + 1];
            std::cout << "right child : " << right_child << std::endl;
        }
        else{
            return -1;
        }
        return 0;
    }

    // Hint: 
    //   {line# of tree} = {line# of left subtree} + {line# of right subtree}
    //
    // Example:
    // (right)
    //             ┌(null)
    //          ┌3─┤
    //          │  └(null)
    // (root) 1─┤
    //          │     ┌(null)
    //          │  ┌5─┤
    //          │  │  └(null)
    //          └2─┤
    //             │  ┌(null)
    //             └4─┤
    //                └(null)
    // (left)
    void print_tree() {
        // (Reverse) Inorder Traversal
        printf("(right)\n");
        vector<string> v = reverse_inorder_str(1, true);
        for (auto line: v)
            cout << line << endl;
        printf("(left)\n");
    }

    bool isEmpty() {
        return _size == 0;
    }

    bool isFull() {
        return _size == _max_size - 1;
    }

    // Return container size.
    size_t size() {
        return _size;
    }

    // Return maximum size.
    size_t max_size() {
        return _max_size;
    }

private:
    size_t _size = 0; // private 변수는 앞에 _(underbar)
    size_t _max_size = MAX_TREE_SIZE;
	int _tree[MAX_TREE_SIZE + 1] = {0};
    int parent;
    int left_child;
    int right_child;

    vector<string> reverse_inorder_str(size_t index, bool is_right) {
        // Index: begin.right -> end.left
        vector<string> v;
        string prefix = string(is_right ? "┌" : "└");
        
        if ((index > _max_size) || (_tree[index] == 0)) {
            // Current is a (null).
            v.push_back(prefix + string("(null)"));
            cout << "2" << endl;
        } else {
            cout << "3" << endl;
            // Current is a node.
            bool is_root = index == 1;
            string data = to_string(_tree[index]);
            string space(data.length() + 1, ' ');
            string s = (is_root ? "(root) " : prefix) + data + string("─┤");
            v.push_back(s);
            // Right
            vector<string> right = reverse_inorder_str(index * 2 + 1, true);
            spacing(right, (is_root ? "       " : (is_right ? " " : "│")) + space);
            // Left
            vector<string> left  = reverse_inorder_str(index * 2, false);
            spacing(left, (is_root ? "       " : (is_right ? "│" : " ")) + space);
            // Concatenate
            v.insert(v.begin(), right.begin(), right.end());
            v.insert(v.end(), left.begin(), left.end());
        }

        for (auto line: v)
            cout << " | " << line << endl;

        // vector<string> v
        for (int i=0; i<sizeof(v); i++)
            cout << " | " << v[i] << endl;

        for (string line: v)
        

        return v;
    }

    void spacing(vector<string>& v, const string& space) {
        for (auto& line: v)
            line.insert(0, space);
    }
};

int main() {
    BinaryTree tree;
    for(int i=1;i<=15;i++){
        tree.insert(i);
    }

    tree.print_tree();
    return 0;
}
