#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *top = nullptr;

void push(int x) {
    auto *t = (struct Node *) malloc(sizeof(struct Node));
    if (t == nullptr) {
        printf("Stack is full\n");
        return;
    }
    t->data = x;
    t->next = top;
    top = t;
}

int pop() {
    if (top == nullptr) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node *t = top;
    top = t->next;
    int x = t->data;
    t->next = nullptr;
    free(t);
    return x;
}

int stackTop() {
    if (top == nullptr) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int peek(int index) {
    struct Node *p = top;
    int x = -1;
    if (index >= 1) {
        for (int i = 0; i < index - 1 && p != nullptr; ++i)
            p = p->next;
    }
    if (p != nullptr)
        x = p->data;
    else
        printf("Invalid position");
    p = nullptr;
    free(p);
    return x;
}

void display() {
    struct Node *p = top;
    while (p != nullptr) {
        printf("%d", p->data);
        p = p->next;
    }
    free(p);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
