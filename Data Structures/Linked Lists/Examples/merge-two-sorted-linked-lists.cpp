/*
 *  Merge Two Sorted Linked Lists
 */

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

struct Node {
    int key;
    struct Node* next;
};

void moveNode(struct Node** source, struct Node** dest);

/*
    Takes two lists, each of which is sorted in increasing order, and merges the two together into one list which is in increasing order.
*/
struct Node* mergeSorted(struct Node* a, struct Node* b) {
    /*
        We can avoid making a new node and use something like

        struct Node* result = NULL;
        struct Node** lastPtrRef = &result;

    */
    struct Node temp;
    struct Node* tail = &temp;

    temp.next = NULL;

    while(true) {
        if (a == NULL) {
            tail->next = b;
            break;
        } else if (b == NULL) {
            tail->next = a;
            break;
        }
        if (a->key <= b->key)
            moveNode(&a, &(tail->next));
        else
            moveNode(&b, &(tail->next));
        tail = tail->next;
    }
    return temp.next;
}

// Push at head of list
void push(struct Node** head_ref, int x) {
    struct Node* new_node  = (struct Node*)malloc(sizeof(struct Node));
    new_node->key = x;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/*
    moveNode() function takes the node from the front of the
   source, and move it to the front of the dest.
   It is an error to call this with the source list empty.

   Before calling moveNode():
   source == {1, 2, 3}
   dest == {1, 2, 3}

   Affter calling moveNode():
   source == {2, 3}
   dest == {1, 1, 2, 3}
*/
void moveNode(struct Node** source, struct Node** dest) {
    struct Node* new_node = *source;
    assert(new_node != NULL);

    *source = new_node->next;

    new_node->next = *dest;

    *dest = new_node;
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
    struct Node* res = NULL;
    struct Node* a = NULL;
    struct Node* b = NULL;

    push(&a, 15);
    push(&a, 10);
    push(&a, 5);

    push(&b, 20);
    push(&b, 3);
    push(&b, 2);

    display(a);
    display(b);

    res = mergeSorted(a, b);

    cout<<"Merged Linked List is: "<<endl;
    display(res);
    return 0;
}
