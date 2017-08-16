/*
 * Reverse a string using stack
 *
 * Time Complexity: O(n) where n is number of characters in stack.
 * Auxiliary Space: O(n) for stack.
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>

using namespace std;

struct Stack {
    int top;
    unsigned size;
    char* arr;
};

struct Stack* createStack(unsigned size) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (char*) malloc(stack->size * sizeof(char));

    return stack;
}

int isFull(struct Stack* stack) {
   return stack->top == stack->size - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack) {
   return stack->top == -1;
}

// Function to add an item to stack
void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;

    stack->arr[++stack->top] = item;
}

// Function to remove an item from stack
char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;

    return stack->arr[stack->top--];
}

// A stack based function to reverse a string
void reverse(char str[]) {
    int n = strlen(str);

    // Create a stack of size equal to length of string
    struct Stack* stack = createStack(n);

    // Push all characters of string to stack
    for (int i = 0; i < n; i++)
        push(stack, str[i]);

    // Pop all characters of string and put them back to str
    for (int i = 0; i < n; i++)
        str[i] = pop(stack);
}

int main() {
    char str[] = "SOME RANDOM STRING";

    reverse(str);
    cout<<"Reversed string is "<<str<<endl;

    return 0;
}
