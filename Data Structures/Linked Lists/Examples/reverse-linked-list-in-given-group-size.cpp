/*
 *  Reverse a Linked List in groups of given size
 */

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int key;
    struct Node* next;
};

/* Reverses the linked list in groups of size s and returns the
   pointer to the new head node. */
struct Node *reverseList (struct Node *head, int s) {
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    int count = 0;

    // reverseList first s nodes of the linked list
    while (current != NULL && count < s) {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    /* next is now a pointer to (s+1)th node
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    if (next !=  NULL)
       head->next = reverseList(next, s);

    return prev;
}

// Push at head of list
void push(struct Node** head_ref, int x) {
    struct Node* new_node  = (struct Node*)malloc(sizeof(struct Node));
    new_node->key = x;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void display(struct Node *head) {
    cout<<head->key;

    if (head->next == NULL) {
        cout<<" => null"<<endl;
        return;
    } else
        cout<<" => ";

    display(head->next);
}

int main() {
    struct Node* head = NULL;

     push(&head, 9);
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);

     cout<<"Given linked list "<<endl;
     display(head);
     head = reverseList(head, 3);

     cout<<"Reversed Linked list "<<endl;
     display(head);

     return(0);
}
