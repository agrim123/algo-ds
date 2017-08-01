// Double Linked Lists

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node {
	int x;
	Node *next;
	Node *prev;
};

// Print Linked list
void display(struct Node *head) {
	cout<<head->x;
    if (head->next == NULL){
    	cout<<endl;
        return;
    } else {
    	cout<<" => ";
    }
    display(head->next);
}

// Push new node to head of linked list
void push_to_head(struct Node** head_ref, int new_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->x = new_data;
	new_node->prev = NULL;
	new_node->next = (*head_ref);
	if((*head_ref)!= NULL) {
		(*head_ref)->prev = new_node;
	}
	(*head_ref) = new_node;
}

// Insert after node
void insert_after(struct Node* prev_node, int new_data) {
	if (prev_node->prev == NULL) {
		cout<<"Not possible";
		return;
	}
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->x = new_data;
	new_node->next = prev_node->next;
	new_node->prev = prev_node;
	prev_node->next = new_node;
	if (new_node->next != NULL) {
		new_node->next->prev = new_node;
	}
}

void delete_node(struct Node** head_ref, struct Node *del) {
	if (*head_ref == NULL || del == NULL)
		return;
	if (*head_ref == del)
		*head_ref = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
	return;
}

int main() {
	Node *root;
	Node *conductor;
	root = new Node;
	root->next = 0;
	root->prev = 0;
	root->x =12;
	conductor = new Node;
	conductor->next = 0;
	conductor->prev = root;
	conductor->x = 1;
	root->next = conductor;
	push_to_head(&root,9);
	push_to_head(&root,34);
	insert_after(conductor,87);
	display(root);
	delete_node(&root,root->next);
	delete_node(&conductor,conductor->next);
	display(root);
}
