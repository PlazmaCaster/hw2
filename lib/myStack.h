#ifndef MYSTACK_H
#define MYSTACK_H

#include <exception>

template <class Type>
class myStack {
public:
    myStack();
    myStack(const myStack<Type>& other);
    const myStack<Type>& operator=(const myStack<Type>& rhs);
    ~myStack();
    void push(const Type& value);
    void pop();
    Type top() const;
    bool isEmpty() const;

private:
    struct node {
        Type item;
        node* next;
    };
    node* topOfMyStack;
};

template <class Type>
myStack<Type>::myStack() : topOfMyStack(nullptr) {};

template <class Type>
myStack<Type>::myStack(const myStack<Type>& other) : topOfMyStack(nullptr) {
    myStack<Type> temp;
    for (auto ptr = other.topOfMyStack; ptr != nullptr; ptr = ptr->next) {
        temp.push(ptr->item);
    }

    while (!temp.isEmpty()) {
        push(temp.top());
        temp.pop();
    }
}

template <class Type>
const typename myStack<Type>::myStack&
myStack<Type>::operator=(const myStack<Type>& rhs) {
    if (this != &rhs) {
        while (!isEmpty()) {
            pop();
        }

        myStack<Type> temp;
        for (auto ptr = rhs.topOfMyStack; ptr != nullptr; ptr = ptr->next) {
            temp.push(ptr->item);
        }

        while (!temp.isEmpty()) {
            push(temp.top());
            temp.pop();
        }
    }
    return *this;
}

template <class Type>
myStack<Type>::~myStack() {
    while (!isEmpty()) {
        pop();
    }
}

template <class Type>
void myStack<Type>::push(const Type& value) {
    node* new_node = new node(value, topOfMyStack);

    topOfMyStack = new_node;
}

template <class Type>
void myStack<Type>::pop() {
    if (topOfMyStack != nullptr) {
        node* dead_node = topOfMyStack;
        topOfMyStack = topOfMyStack->next;
        delete dead_node;
    }
}

template <class Type>
Type myStack<Type>::top() const {
    if (topOfMyStack == nullptr) {
        throw std::out_of_range("Stack is Empty");
    }
    return topOfMyStack->item;
}

template <class Type>
bool myStack<Type>::isEmpty() const {
    return topOfMyStack == nullptr;
}

#endif /* MYSTACK_H */