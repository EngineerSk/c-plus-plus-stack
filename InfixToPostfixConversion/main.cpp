#include <iostream>
#include <cstring>

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
    temp->next = nullptr;
    char x = temp->data;
    free(temp);
    return x;
}

char stackTop() {
    return top == nullptr ? '\0' : top->data;
}

void display(char *ptr) {
    int i=0;
    while (ptr[i] != '\0') {
        printf("%c ", ptr[i++]);
    }
    printf("\n");
}

int precedence(char x) {
    if (x == '+' || x == '-')return 1;
    else if (x == '*' || x == '/')return 2;
    return 0;
}

bool isOperand(char x) {
    return precedence(x) == 0;
}

char *infixToPostfix(char *infix) {
    if (infix == nullptr)
        return infix;
    unsigned int len = strlen(infix);
    if (len == 0)
        return infix;
    int i = 0, j = 0;
    char *postfix = (char *) malloc((len + 2) * sizeof(char));
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            if (stackTop() == '\0' || (precedence(infix[i]) > precedence(stackTop())))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while (top != nullptr)postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char *infix = "a+b*c-d/e";
    push('#');
    char *postfix = infixToPostfix(infix);
    display(infix);
    display(postfix);
    return 0;
}
