/*
    Single Linked List
    - Operations
        - Push at head of list
        - Insert after a node
        - Append node at end
        - Delete node with given key
        - Delete node at given position
        - Length of list
            - Iterative
            - Recursive
        - Search a given element
        - Swap nodes in a linked list without swapping data
        - Delete whole list
        - Reverse the list

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

// Push at head of list
void push(struct Node** head_ref, int x) {
    struct Node* new_node  = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Insert after a node
void insert_after(struct Node* prev_node, int data) {
    if (prev_node == NULL) {
        cout<<"The given previous node cannot be NULL";
        return;
    }
    struct Node* new_node  = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Append node at end
void append(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data  = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
       *head_ref = new_node;
       return;
   }

   struct Node *last = *head_ref;
   while (last->next != NULL)
    last = last->next;

last->next = new_node;
return;
}

// Delete node with given key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    // If head node has the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for key to be deleted
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found in list
    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}

// Delete node at given position
void deleteNodeAtPosition(struct Node **head_ref, int position) {
    // If list is empty
    if (*head_ref == NULL)
      return;

    // Store head node
    struct Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i<position-1; i++)
        temp = temp->next;

    // If position is more than number of ndoes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node *next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next);

    temp->next = next;  // Unlink the deleted node from list
}

// Get length of list using Iterative method
int length_iterative(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Get length of list using Recursive method
int length_recursive(struct Node* head) {
    if (head == NULL)
        return 0;

    return 1 + length_recursive(head->next);
}

// Search element
bool search(struct Node* head, int x) {
    if (head == NULL)
        return false;

    if (head->data == x)
        return true;

    return search(head->next, x);
}

// Swap nodes in a linked list without swapping data
void swapNodes(struct Node **head_ref, int x, int y) {
   if (x == y) return;

   // Search for x (keep track of prevX and CurrX)
   struct Node *prevX = NULL, *currX = *head_ref;
   while (currX && currX->data != x) {
       prevX = currX;
       currX = currX->next;
   }

   // Search for y (keep track of prevY and CurrY)
   struct Node *prevY = NULL, *currY = *head_ref;
   while (currY && currY->data != y) {
       prevY = currY;
       currY = currY->next;
   }

   // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
       return;

   // If x is not head of linked list
   if (prevX != NULL)
       prevX->next = currY;
   else // Else make y as new head
       *head_ref = currY;

   if (prevY != NULL)
       prevY->next = currX;
   else
       *head_ref = currX;

   // Swap next pointers
   struct Node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}

// Delete whole list
void deleteList(struct Node** head_ref) {
    struct Node *curr = *head_ref;
    struct Node *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head_ref = NULL;
}

// Reverse list
void reverseList(struct Node** head_ref) {
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL) {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void display(struct Node *head) {
    cout<<head->data;
    if (head->next == NULL){
        cout<<endl;
        return;
    } else {
        cout<<" => ";
    }
    display(head->next);
}

int main() {
    struct Node* head;
    head = new Node;
    head->data = 1;
    head->next = NULL;

    push(&head,4);
    insert_after(head, 6);
    insert_after(head, 8);
    insert_after(head, 9);
    insert_after(head, 5);
    append(&head,10);
    deleteNode(&head,1);
    deleteNodeAtPosition(&head, 3);
    display(head);
    cout<<"Length : "<<length_iterative(head)<<endl;
    cout<<"Length : "<<length_recursive(head)<<endl;
    cout<<search(head, 8)<<endl;
    swapNodes(&head, 6, 5);
    display(head);
    reverseList(&head);
    display(head);
    deleteList(&head);
    return 0;
}
