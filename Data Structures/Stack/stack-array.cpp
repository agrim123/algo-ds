/* Stacks
   - Array Implementation
   - LIFO or FILO
   - Three basic operations on Stacks:
        1. Push
        2. Pop
        3. Is Empty
*/

#include <iostream>

using namespace std;

#define MAX 1000

class Stack {
    int top;
public:
    int a[MAX];
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    bool isEmpty();
};

bool Stack::push(int x) {
    if (top >= MAX) {
        cout<<"Stack Overflow!!";
    } else {
        a[++top] = x;
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        cout<<"Stack Underflow!!";
    } else {
        int x = a[top--];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

int main() {
    struct Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << " Popped from stack\n";
    if (s.isEmpty())
        cout<<"Stack is Empty!";
    return 0;
}