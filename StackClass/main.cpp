#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node *next = nullptr;
};

template<class T>
class Stack {
private:
    Node<T> *first;
public:
    Stack();

    ~Stack();

    void push(T x);

    T pop();

    T peek(int index);

    T stackTop();

    void display();
};

template<class T>
Stack<T>::Stack() {
    first = nullptr;
}

template<class T>
Stack<T>::~Stack() {
    while (first != nullptr) {
        Node<T> *p = first;
        p->next = nullptr;
        first = first->next;
        delete p;
    }
    delete first;
}

template<class T>
void Stack<T>::push(T x) {
    auto *temp = new Node<T>;
    if (temp == nullptr) {
        cout << "Stack is full" << endl;
        delete temp;
        return;
    }
    temp->data = x;
    temp->next = first;
    first = temp;
    temp = nullptr;
    delete temp;
}

template<class T>
T Stack<T>::pop() {
    if (first == nullptr) {
        cout << "Stack is empty" << endl;
        return nullptr;
    }
    T x = first->data;
    Node<T> *temp = first;
    first = first->next;
    temp->next = nullptr;
    delete temp;
    return x;
}

template<class T>
T Stack<T>::peek(int index) {
    if (first == nullptr) {
        cout << "Stack is empty" << endl;
        return "";
    }
    Node<T> *temp = nullptr;
    T x;
    if (index >= 1) {
        temp = first;
        for (int i = 0; i < index - 1 && temp != nullptr; ++i)
            temp = temp->next;
    }
    if (temp != nullptr)
        x = temp->data;
    else
        cout << "Invalid position" << endl;
    temp = nullptr;
    delete temp;
    return x;
}

template<class T>
T Stack<T>::stackTop() {
    if (first == nullptr) {
        cout << "Stack is empty" << endl;
        return "";
    }
    return first->data;
}

template<class T>
void Stack<T>::display() {
    Node<T> *temp = first;
    if (first == nullptr)
        return;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    delete temp;
}

int main() {
    Stack<string> stack = Stack<string>();
    stack.push("5");
    stack.push("15");
    stack.push("23");
    stack.push("25");
    stack.display();
    cout << stack.pop() << " Popped out!" << endl;
    stack.display();
    cout << stack.peek(5) << endl;
    cout << stack.stackTop() << " at the stack top!" << endl;
    return 0;
}
