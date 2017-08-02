/*
    Binary Search Trees
        - Basic Operations
            - Search
            - Insert
            - Delete
              - Node to be deleted is leaf
              - Node to be deleted has only one child
              - Node to be deleted has two children
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

// new_node() allocates a new node with the given key and NULL left and right pointers.
struct Node* new_node(int key) {
    // Allocate memory for new node
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->key = key;
    node->left = node->right = NULL;

    return node;
}

void in_order(struct Node *root) {
    if (root != NULL) {
        in_order(root->left);
        cout<<root->key<<endl;
        in_order(root->right);
    }
}

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct Node * minValueNode(struct Node* node) {
    struct Node* current = node;

    // loop down to find the leftmost leaf
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Time Complexity:: O(h) where h is height of Binary Search Tree.
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key) return root;

    // key is greater than root's key
    if (root->key < key) return search(root->right, key);

    // key is smaller than root's key
    return search(root->left, key);
}

// Time Complexity:: O(h) where h is height of Binary Search Tree.
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return new_node(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // return the (unchanged) node pointer
    return node;
}

struct Node* delete_node(struct Node* root, int key) {
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = delete_node(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = delete_node(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    in_order(root);
    cout<<search(root, 20)<<endl;
    root = delete_node(root, 20);
    printf("Inorder traversal of the modified tree \n");
    in_order(root);

    printf("\nDelete 30\n");
    root = delete_node(root, 30);
    printf("Inorder traversal of the modified tree \n");
    in_order(root);

    printf("\nDelete 50\n");
    root = delete_node(root, 50);
    printf("Inorder traversal of the modified tree \n");
    in_order(root);
    return 0;
}
