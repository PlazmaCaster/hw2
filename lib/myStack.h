template <class Type>
class myStack {
public:
    myStack();
    myStack(const myStack <Type>&);
    const myStack <Type>& operator =(const myStack <Type>&);
    ~myStack();
    void push(const Type&);
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