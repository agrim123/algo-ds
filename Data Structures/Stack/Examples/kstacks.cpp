#include <iostream>
#include <climits>

using namespace std;

class kStacks {
    int *arr;
    int *top;
    int *next;
    int n, k;
    int free;

public:
    kStacks(int k, int n);
    bool isFull() { return (free == -1); }
    void push(int item, int stack);
    int pop(int stack);
    bool isEmpty(int stack) { return (top[stack] == -1); }
    void print();
};

kStacks::kStacks(int k1, int n1) {
    k = k1;
    n = n1;
    arr = new int[n];
    top = new int[n];
    next = new int[n];

    for (int i=0;i<k;i++)
        top[i] = -1;

    free = 0;

    for (int i = 0; i < n-1; ++i)
        next[i] = i+1;

    next[n-1] = -1;
}

void kStacks::push(int item, int stack) {
    if (isFull()) {
        cout<<"Stack Overflow"<<endl;
        return;
    }

    int i = free;
    free = next[i];
    next[i] = top[stack];
    top[stack] = i;

    arr[i] = item;
}

int kStacks::pop(int stack) {
    if (isEmpty(stack)) {
        cout<<"Stack Underflow"<<endl;
        return INT_MAX;
    }

    int i = top[stack];
    top[stack] = next[i];
    next[i] = free;
    free = i;
    return arr[i];
}

void kStacks::print() {
    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    kStacks ks(k, n);

    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
    ks.print();

    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
    ks.print();

    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
    ks.print();

    ks.push(98, 1);
    ks.push(99, 2);
    ks.print();

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    ks.print();

    return 0;
}
