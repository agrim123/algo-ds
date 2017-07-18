""" Binary Trees
    - Basic Operations
        - Preorder Traversal
        - Inorder Traversal
        - Postorder Traversal
"""


class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


# A function to do inorder tree traversal
def print_in_order(root):

    if root:
        # First recur on left child
        print_in_order(root.left)

        # then print the data of node
        print(root.val),

        # now recur on right child
        print_in_order(root.right)


# A function to do postorder tree traversal
def print_post_order(root):
    if root:

        # First recur on left child
        print_post_order(root.left)

        # the recur on right child
        print_post_order(root.right)

        # now print the data of node
        print(root.val),


# A function to do postorder tree traversal
def print_pre_order(root):
    if root:

        # First print the data of node
        print(root.val),

        # Then recur on left child
        print_pre_order(root.left)

        # Finally recur on right child
        print_pre_order(root.right)


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
print("Preorder traversal of binary tree is")
print_pre_order(root)

print("\nInorder traversal of binary tree is")
print_in_order(root)

print("\nPostorder traversal of binary tree is")
print_post_order(root)
