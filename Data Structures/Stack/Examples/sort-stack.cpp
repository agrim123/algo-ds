/*
 * Sort a Stack using recursion
 */

#include <iostream>
#include <cstdlib>

using namespace std;

struct Stack {
    int data;
    struct Stack *next;
};

void init(struct Stack **s) {
    *s = NULL;
}

int isEmpty(struct Stack *s) {
    if (s == NULL)
        return 1;
    return 0;
}

void push(struct Stack **s, int x) {
    struct Stack *p = (struct Stack *)malloc(sizeof(*p));

    if (p == NULL) {
        return;
    }

    p->data = x;
    p->next = *s;
    *s = p;
}

int pop(struct Stack **s) {
    int x;
    struct Stack *temp;

    x = (*s)->data;
    temp = *s;
    (*s) = (*s)->next;
    free(temp);

    return x;
}

int top(struct Stack *s) {
    return (s->data);
}

// Recursive function to insert an item x in sorted way
void sortedInsert(struct Stack **s, int x) {
    // Base case: Either Stack is empty or newly inserted item is greater than top (more than all existing)
    if (isEmpty(*s) || x > top(*s)) {
        push(s, x);
        return;
    }

    // If top is greater, remove the top item and recur
    int temp = pop(s);
    sortedInsert(s, x);

    // Put back the top item removed earlier
    push(s, temp);
}

// Function to sort Stack
void sortStack(struct Stack **s) {
    if (!isEmpty(*s)) {
        // Remove the top item
        int x = pop(s);

        // Sort remaining Stack
        sortStack(s);

        // Push the top item back in sorted Stack
        sortedInsert(s, x);
    }
}

void display(struct Stack *s) {
    while (s) {
        cout<<" "<<s->data;
        s = s->next;
    }
    cout<<endl;
}

int main() {
    struct Stack *top;

    init(&top);
    push(&top, 12);
    push(&top, -7);
    push(&top, 112);
    push(&top, 1412);
    push(&top, -3124);

    cout<<("Stack elements before sorting:\n")<<endl;
    display(top);

    sortStack(&top);
    cout<<endl;

    cout<<("Stack elements after sorting:\n")<<endl;
    display(top);

    return 0;
}
