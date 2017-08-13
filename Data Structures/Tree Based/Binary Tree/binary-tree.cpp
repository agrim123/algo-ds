/*
    Binary Trees
        Basic Operations
        - Preorder Traversal
        - Inorder Traversal
        - Postorder Traversal
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* new_node(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return node;
}

void print_post_order(struct Node* node) {
    if (node == NULL)
        return;

    // first recur on left subtree
    print_post_order(node->left);

    // then recur on right subtree
    print_post_order(node->right);

    // now deal with the node
    cout<<node->data<<" ";
}

void print_in_order(struct Node* node) {
    if (node == NULL) return;

    // first recur on left child
    print_in_order(node->left);

    // then print the data of node
    cout<<node->data<<" ";

    // now recur on right child
    print_in_order(node->right);
}

void print_pre_order(struct Node* node) {
    if (node == NULL) return;

    // first print data of node
    cout<<node->data<<" ";

    // then recur on left sutree
    print_pre_order(node->left);

    // now recur on right subtree
    print_pre_order(node->right);
}

int main() {
    struct Node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);

    cout<<"Preorder traversal of binary tree is : ";
    print_pre_order(root);
    cout<<endl;
    cout<<"Inorder traversal of binary tree is : ";
    print_in_order(root);
    cout<<endl;
    cout<<"Postorder traversal of binary tree is : ";
    print_post_order(root);
    cout<<endl;

    return 0;
}
