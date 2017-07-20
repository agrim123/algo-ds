""" Binary Search Trees
     Basic Operations
      - Search
      - Insert
      - Delete
        - Node to be deleted is leaf
        - Node to be deleted has only one child
        - Node to be deleted has two children
"""


class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


# Function to search a given key in BST
def search(root, key):
    # Base Cases: root is null or key is present at root
    if root is None or root.val == key:
        return root
    # Key is greater than root's key
    if root.val < key:
        return search(root.right, key)

    # Key is smaller than root's key
    return search(root.left, key)


# Function to insert a new node with the given key
def insert(root, node):
    if root is None:
        root = node
    else:
        if root.val > node.val:
            if root.left is None:
                root.left = node
            else:
                insert(root.left, node)
        else:
            if root.right is None:
                root.right = node
            else:
                insert(root.right, node)


# Function to do inorder tree traversal
def inorder(root):
    if root:
        inorder(root.left)
        print(root.val)
        inorder(root.right)


def minValueNode(node):
    current = node

    # loop down to find the leftmost leaf
    while(current.left is not None):
        current = current.left

    return current


# Given a binary search tree and a key, this function
# delete the key and returns the new root
def delete_node(root, key):
    # Base Case
    if root is None:
        return root

    # If the key to be deleted is similiar than the root's
    # key then it lies in left subtree
    if key < root.val:
        root.left = delete_node(root.left, key)

    # If the kye to be delete is greater than the root's key
    # then it lies in right subtree
    elif(key > root.val):
        root.right = delete_node(root.right, key)

    # If key is same as root's key, then this is the node
    # to be deleted
    else:
        # Node with only one child or no child
        if root.left is None:
            temp = root.right
            root = None
            return temp
        elif root.right is None:
            temp = root.left
            root = None
            return temp

        # Node with two children: Get the inorder successor
        # (smallest in the right subtree)
        temp = minValueNode(root.right)

        # Copy the inorder successor's content to this node
        root.val = temp.val

        # Delete the inorder successor
        root.right = delete_node(root.right, temp.val)

    return root

root = Node(50)
insert(root, Node(30))
insert(root, Node(20))
insert(root, Node(40))
insert(root, Node(70))
insert(root, Node(60))
insert(root, Node(80))

print("Inorder traversal of the given tree")
inorder(root)

print("\nDelete 20")
root = delete_node(root, 20)
print("Inorder traversal of the modified tree")
inorder(root)

print("\nDelete 30")
root = delete_node(root, 30)
print("Inorder traversal of the modified tree")
inorder(root)

print("\nDelete 50")
root = delete_node(root, 50)
print("Inorder traversal of the modified tree")
inorder(root)
