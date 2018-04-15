#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void display(struct Node *head);

struct Node
{
    char data;
    struct Node *next;
};

void push(struct Node** head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void reverse(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void delAlt(struct Node **head)
{
    struct Node* curr = *head;
    struct Node* next = (*head)->next;
    while (curr != NULL && next != NULL)
    {
        curr->next = next->next;
        free(next);
        curr = curr->next;
        if (curr != NULL)
        {
            next = curr->next;
        }
    }
}

void delAltRecur(struct Node **head)
{
    if (*head == NULL)
        return;
    struct Node* next = (*head)->next;
    if (next == NULL)
        return;
    (*head)->next = next->next;
    free(next);
    delAltRecur(&(*head)->next);
}

void deleteLoop(struct Node **head)
{

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
    head->data = 'R';
    head->next = NULL;
    push(&head, 'A');
    push(&head, 'D');
    push(&head, 'A');
    push(&head, 'R');
    display(head);
    delAltRecur(&head);
    display(head);
}
