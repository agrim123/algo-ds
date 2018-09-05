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

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* new_node(int data) {
    struct TreeNode* TreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    TreeNode->data = data;

    TreeNode->left = NULL;
    TreeNode->right = NULL;
    return TreeNode;
}

void print_post_order_recur(struct TreeNode* node) {
    if (node == NULL)
        return;

    // first recur on left subtree
    print_post_order_recur(node->left);

    // then recur on right subtree
    print_post_order_recur(node->right);

    // now deal with the node
    cout<<node->data<<" ";
}

void print_in_order_recur(struct TreeNode* node) {
    if (node == NULL) return;

    // first recur on left child
    print_in_order_recur(node->left);

    // then print the data of node
    cout<<node->data<<" ";

    // now recur on right child
    print_in_order_recur(node->right);
}

void print_pre_order_recur(struct TreeNode* node) {
    if (node == NULL) return;

    // first print data of node
    cout<<node->data<<" ";

    // then recur on left sutree
    print_pre_order_recur(node->left);

    // now recur on right subtree
    print_pre_order_recur(node->right);
}

int height(TreeNode* node) {
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

void printLevelOrder(TreeNode* A, int l) {
    if (!A) return;
    if (l == 1) cout<<A->data<<" ";
    else if (l > 1) {
        printLevelOrder(A->left, l-1);
        printLevelOrder(A->right, l-1);
    }
}

void levelOrder(TreeNode* root) {
    int h = height(root);
    for(int i=1;i<=h;i++)
        printLevelOrder(root, i);
    cout<<endl;
}

int main() {
    struct TreeNode *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);

    cout<<"Height of binary tree is : "<<height(root)<<endl;
    cout<<"Preorder traversal of binary tree is : ";
    print_pre_order_recur(root);
    cout<<endl;
    cout<<"Inorder traversal of binary tree is : ";
    print_in_order_recur(root);
    cout<<endl;
    cout<<"Postorder traversal of binary tree is : ";
    print_post_order_recur(root);
    cout<<endl;
    levelOrder(root);

    return 0;
}
