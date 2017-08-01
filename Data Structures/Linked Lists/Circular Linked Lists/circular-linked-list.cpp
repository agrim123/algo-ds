/*
    Circular linked List
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head_ref;
    ptr->data = data;
    ptr->next = *head_ref;

    // If linked list is not NULL then set the next of last node
    if (*head_ref != NULL) {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr;
    }
    else
        ptr->next = ptr;

    *head_ref = ptr;
}

void displayList(struct Node *head) {
    struct Node *temp = head;
    if (head != NULL) {
        do {
            cout<<" "<<temp->data;
            temp = temp->next;
        } while (temp != head); // It is a circular list !!
    }
}

int main() {
    struct Node *head = NULL;

    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    displayList(head);

    return 0;
}
