#include <iostream>

using namespace std;

struct Node {
    char data;
    struct Node *next;
} *top = nullptr;

void push(char x) {
    auto *temp = (struct Node *) malloc(sizeof(struct Node));
    if (temp == nullptr) {
        printf("Stack is full\n");
        return;
    }
    temp->data = x;
    temp->next = top;
    top = temp;
}

char pop() {
    if (top == nullptr) {
        printf("Stack is empty\n");
        return '\0';
    }
    struct Node *temp = top;
    top = top->next;
    char x = temp->data;
    temp->next = nullptr;
    free(temp);
    return x;
}

void display() {
    struct Node *p = top;
    if (p == nullptr)
        return;
    while (p != nullptr) {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
    free(p);
}

bool isParenthesisBalanced(string exp) {
    // To enhance the function for matching (), [] and {}
    // hash map can be defined using distinct opening brackets as keys and respective distinct closing brackets as value
    // if any opening bracket is in the string, it should be pushed to stack
    // if the first next closing bracket matches the opening bracket in stack using stack top as hash map key then pop the stack
    // else if the first next character of the string is any closing bracket and stack is empty return false
    // else return false
    for (int i = 0; exp[i] != '\0'; ++i) {
        push(exp[i]);
        display();
        pop();
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (top == nullptr)
                return false;
            pop();
        }
    }
    return top == nullptr && !exp.empty();
}

int main() {
    isParenthesisBalanced("((a+b)*(c-d)))") ? printf("true") : printf("false");
    return 0;
}
