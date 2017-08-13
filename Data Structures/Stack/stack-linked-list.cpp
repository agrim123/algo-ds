/*
    Stacks
        - Linked Lists Implementation
        - LIFO or FILO
        - Four basic operations on Stacks:
               1. Push
               2. Pop
               3. Is Empty
               4. Peek
*/

#include <iostream>
#include <cstdlib>

using namespace std;

#define INT_MIN 0

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data) {
    struct StackNode* s = (struct StackNode*) malloc(sizeof(struct StackNode));
    s->data = data;
    s->next = NULL;
    return s;
}

int isEmpty(struct StackNode *root) {
    return !root;
}

void push(struct StackNode** root, int data) {
    struct StackNode* s = newNode(data);
    s->next = *root;
    *root = s;
    cout<<data<<" pushed to stack"<<endl;
}

int pop(struct StackNode** root) {
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(struct StackNode* root) {
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main() {
    struct StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    cout<<pop(&root)<<" popped from stack"<<endl;

    cout<<"Top element is "<<peek(root)<<endl;

    return 0;
}
