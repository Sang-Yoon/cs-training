#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char element){
    switch(element){
        case '+':
        case '-':
        case '/':
        case '*':
        return true;
    }
    return false;
}

void print_infix_form(char* prefix, size_t size) {
    // printf로 구현
    stack<string> exp;
    for (int i=size-1; i>=0; i--){
        if(isOperator(prefix[i])){
            string op1 = exp.top();
            exp.pop();
            string op2 = exp.top();
            exp.pop();
            string tmp = "(" + op1 + prefix[i] + op2 + ")";
            exp.push(tmp);
        }
        else{
            exp.push(string(1,prefix[i]));
        }
    }
    string infix = exp.top();
    printf("infix : %s\n", infix.c_str());
}

void print_postfix_form(char* prefix, size_t size) {
    // printf로 구현
    stack<string> exp;
    for (int i=size-1; i>=0; i--){
        if(isOperator(prefix[i])){
            string op1 = exp.top();
            exp.pop();
            string op2 = exp.top();
            exp.pop();
            string tmp = op1 + op2 + prefix[i];
            exp.push(tmp);
        }
        else{
            exp.push(string(1,prefix[i]));
        }
    }
    string postfix = exp.top();
    printf("postfix : %s\n", postfix.c_str());
}

int main() {
    // prefix_input
    char prefix_input[11] = {'/','*','+','a', 'b', '-', 'c', 'd', '+', 'e', 'f'};
    size_t size = 12;

    print_infix_form(prefix_input, size);
    print_postfix_form(prefix_input, size);
    return 0;
}