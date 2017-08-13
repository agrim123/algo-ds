=begin
    Binary Search Trees
       Basic Operations
        - Search
        - Insert
        - Delete
          - Node to be deleted is leaf
          - Node to be deleted has only one child
          - Node to be deleted has two children
        - Preorder Traversal
        - Inorder Traversal
        - Postorder Traversal
=end

module BinarySearchTree
  class Node
    attr_accessor :left, :right, :val

    def initialize(val = nil)
      @val  = val
      @left  = nil
      @right = nil
    end

    def insert(node)
      if val.nil?
        self.val = node.val
        return self
      end

      if node.val < val
        self.left = Node.new if left.nil?
        self.left.insert(node)
      elsif node.val > val
        self.right = Node.new if right.nil?
        self.right.insert(node)
      end
    end

    def search(node_val)
      return nil if val.nil?

      if node_val == val
        return self
      elsif node_val < val
        left.search(node_val)
      elsif node_val > val
        right.search(node_val)
      end
    end

    def destroy(node_val)
      if node = search(node_val)
        destroy_node(node)
      end
    end

    # Pre-order displays root node, left node and then right node
    def preorder
      tree = []
      tree << val
      tree << left.preorder unless left.nil?
      tree << right.preorder unless right.nil?

      tree
    end

    # In-order displays left node, root node and then right node
    def inorder
      tree = []
      tree << left.inorder unless left.nil?
      tree << val
      tree << right.inorder unless right.nil?

      tree
    end

    # Post-order displays left node, root node and then right node
    def postorder()
      tree = []
      tree << left.postorder unless left.nil?
      tree << right.postorder unless right.nil?
      tree << val

      tree
    end

    def inspect
      "{ #{val} :: #{left.inspect} | #{right.inspect} }"
    end

    protected

    def destroy_node(node)
      destroy_node(node.left) unless node.left.nil?
      destroy_node(node.right) unless node.right.nil?

      node.val = node.left = node.right = nil
    end
  end
end

tree       = BinarySearchTree::Node.new(10)
tree.left  = BinarySearchTree::Node.new(5)
tree.right = BinarySearchTree::Node.new(15)
tree.insert(BinarySearchTree::Node.new(3))
tree.insert(BinarySearchTree::Node.new(43))
tree.insert(BinarySearchTree::Node.new(73))
tree.postorder
puts tree.inspect
