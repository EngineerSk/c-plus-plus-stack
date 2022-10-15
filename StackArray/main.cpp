#include <iostream>

using namespace std;

struct Stack {
    int size, top, *S;
};

void create(struct Stack *st) {
    printf("Enter size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *) malloc(sizeof(int) * st->size);
}

void display(struct Stack st) {
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}

void push(struct Stack *st, int x) {
    if (st->size - 1 == st->top)
        printf("Stack overflow");
    else
        st->S[++st->top] = x;
}

int pop(struct Stack *st) {
    if (st->top == -1) {
        printf("stack underflow");
        return -1;
    }
    return st->S[st->top--];
}

bool isEmpty(struct Stack st) {
    return st.top == -1;
}

bool isFull(struct Stack st) {
    return st.top == st.size - 1;
}

int peek(struct Stack st, int index) {
    if (st.top - index + 1 < 0)
        return -1;
    return st.S[st.top - index + 1];
}

int stackTop(struct Stack st) {
    if (st.top == -1)
        return -1;
    return st.S[st.top];
}

int main() {
    struct Stack st;
    create(&st);
    return 0;
}
