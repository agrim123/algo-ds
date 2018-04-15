#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void display(struct Node *head);

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node** head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void reverse (struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void swapNodes(struct Node** head, int x, int y)
{
    // Assuming distinct elements
    if (x == y) return;

    struct Node* currentX = *head;
    struct Node* prevX = NULL;

    while (currentX && currentX->data != x)
    {
        prevX = currentX;
        currentX = currentX->next;
    }
    cout<<endl;
    display(currentX);
    display(prevX);
    cout<<endl;
    struct Node* currentY = *head;
    struct Node* prevY = NULL;

    while (currentY && currentY->data != y)
    {
        prevY = currentY;
        currentY = currentY->next;
    }
    cout<<endl;
    display(currentY);
    display(prevY);
    cout<<endl;

    if (currentX == NULL || currentY == NULL) return;

    if (prevX != NULL)
        prevX->next = currentY;
    else
        *head = currentY;

    if (prevY != NULL)
        prevY->next = currentX;
    else
        *head = currentX;

    struct Node* temp = currentY->next;
    currentY->next = currentX->next;
    currentX->next = temp;
}

void display(struct Node *head)
{
    cout<<head->data;
    if (head->next == NULL){
        cout<<" -> NULL"<<endl;
        return;
    } else {
        cout<<" -> ";
    }
    display(head->next);
}

int main()
{
    struct Node *head;
    head = new Node;
    head->data = 0;
    head->next = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    display(head);
    swapNodes(&head, 1, 3);
    display(head);
}
