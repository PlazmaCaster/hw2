#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdexcept>

/// @brief Linked list implementation of a stack
/// @tparam Type 
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

/// @brief Default Constructor
/// @tparam Type 
template <class Type>
myStack<Type>::myStack() : topOfMyStack(nullptr) {};

/// @brief Copy Constructor
/// @tparam Type 
/// @param other The other stack to be cloned
template <class Type>
myStack<Type>::myStack(const myStack<Type>& other) : topOfMyStack(nullptr) {
    myStack<Type> temp; // Temporary stack

    // Copies each element in reverse order
    for (auto ptr = other.topOfMyStack; ptr != nullptr; ptr = ptr->next) {
        temp.push(ptr->item);
    }

    // Pushes it back into *this stack in correct order
    while (!temp.isEmpty()) {
        push(temp.top());
        temp.pop();
    }
}

/// @brief Copy Assignment Operator
/// @tparam Type 
/// @param rhs Right hand side stack to be copied
/// @return The newly created copy of rhs stack
template <class Type>
const typename myStack<Type>::myStack&
myStack<Type>::operator=(const myStack<Type>& rhs) {
    if (this != &rhs) {         // Self-assignment guard
        // Destroy original contents
        while (!isEmpty()) {
            pop();
        }

        // Same logic as the copy constructor from here on out
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

/// @brief myStack destructor
/// @tparam Type 
template <class Type>
myStack<Type>::~myStack() {
    while (!isEmpty()) {
        pop();      // POP ALL BALOONS
    }
}

/// @brief Push new element onto stack
/// @tparam Type 
/// @param value The value to be pushed
template <class Type>
void myStack<Type>::push(const Type& value) {
    // Create new node and add it to linked list
    node* new_node = new node(value, topOfMyStack);

    topOfMyStack = new_node;
}

/// @brief Pop top element of stack
/// @note Does nothing if stack is empty
/// @tparam Type 
template <class Type>
void myStack<Type>::pop() {
    if (topOfMyStack != nullptr) {
        node* dead_node = topOfMyStack;
        topOfMyStack = topOfMyStack->next; // reassign topOfMyStack to next node
        delete dead_node;
    }
}

/// @brief Reveals what the current top of stack is
/// @tparam Type 
/// @throws std::out_of_range() Seeing top of empty stack is not allowed
/// @return The top element of stack
template <class Type>
Type myStack<Type>::top() const {
    if (topOfMyStack == nullptr) {
        throw std::out_of_range("Stack is Empty");
    }
    return topOfMyStack->item;
}

/// @brief Checks if the stack is empty or not
/// @tparam Type 
/// @return Boolean: True if the stack is empty, false otherwise
template <class Type>
bool myStack<Type>::isEmpty() const {
    return topOfMyStack == nullptr;
}

#endif /* MYSTACK_H */