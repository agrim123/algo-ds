// Binary Search Tree

class Node {
  constructor(val, left = null, right = null) {
    this.val = val
    this.left = left
    this.right = right
  }
}

class BinarySearchTree {
  constructor() {
    this.root = null
  }

  insert(val) {
    const node = this.root
    if (node === null) {
      this.root = new Node(val)
      return
    } else {
      const searchTree = (node) => {
        if (val < node.val) {
          if (node.left === null) {
            node.left = new Node(val)
            return
          } else if (node.left !== null) {
            return searchTree(node.left)
          }
        } else if (val > node.val) {
          if (node.right === null) {
            node.right = new Node(val)
            return
          } else if (node.right !== null) {
            return searchTree(node.right)
          }
        } else {
          return null
        }
      }
      return searchTree(node)
    }
  }

  findMin() {
    let current = this.root
    while (current.left !== null) {
      current = current.left
    }
    return current.val
  }

  findMax() {
    let current = this.root
    while (current.right !== null) {
      current = current.right
    }
    return current.val
  }

  find(val) {
    let current = this.root
    while (current.val !== val) {
      if (val < current.val) {
        current = current.left
      } else {
        current = current.right
      }
      if (current === null) {
        return null
      }
    }
    return current
  }

  isPresent(val) {
    let current = this.root
    while (current) {
      if (val === current.val) {
        return true
      }
      if (val < current.val) {
        current = current.left
      } else {
        current = current.right
      }
    }
    return false
  }

  remove(val) {
    const removeNode = (node, val) => {
      if (node == null) {
        return null
      }
      if (val == node.val) {
        // node has no children
        if (node.left == null && node.right == null) {
          return null
        }
        // node has no left child
        if (node.left == null) {
          return node.right
        }
        // node has no right child
        if (node.right == null) {
          return node.left
        }
        // node has two children
        var tempNode = node.right
        while (tempNode.left !== null) {
          tempNode = tempNode.left
        }
        node.val = tempNode.val
        node.right = removeNode(node.right, tempNode.val)
        return node
      } else if (val < node.val) {
        node.left = removeNode(node.left, val)
        return node
      } else {
        node.right = removeNode(node.right, val)
        return node
      }
    }
    this.root = removeNode(this.root, val)
  }

  isBalanced() {
    return (this.findMinHeight() >= this.findMaxHeight() - 1)
  }

  findMinHeight(node = this.root) {
      if (node == null) {
          return -1
      }
      let left = this.findMinHeight(node.left)
      let right = this.findMinHeight(node.right)
      if (left < right) {
          return left + 1
      } else {
          return right + 1
      }
  }

  findMaxHeight(node = this.root) {
      if (node == null) {
          return -1
      }
      let left = this.findMaxHeight(node.left)
      let right = this.findMaxHeight(node.right)
      if (left > right) {
          return left + 1
      } else {
          return right + 1
      }
  }

  inOrder() {
    if (this.root == null) {
      return null
    } else {
      var result = new Array()
      let traverseInOrder = (node) => {
        node.left && traverseInOrder(node.left)
        result.push(node.val)
        node.right && traverseInOrder(node.right)
      }
      traverseInOrder(this.root)
      return result
    }
  }

  preOrder() {
    if (this.root == null) {
      return null
    } else {
      var result = new Array()
      let traversePreOrder = (node) => {
        result.push(node.val)
        node.left && traversePreOrder(node.left)
        node.right && traversePreOrder(node.right)
      }
      traversePreOrder(this.root)
      return result
    }
  }

  postOrder() {
    if (this.root == null) {
      return null
    } else {
      var result = new Array()
      let traversePostOrder = (node) => {
        node.left && traversePostOrder(node.left)
        node.right && traversePostOrder(node.right)
        result.push(node.val)
      }
      traversePostOrder(this.root)
      return result
    }
  }

  levelOrder() {
    let result = []
    let Q = []
    if (this.root != null) {
      Q.push(this.root)
      while(Q.length > 0) {
        let node = Q.shift()
        result.push(node.val)
        if (node.left != null) {
          Q.push(node.left)
        }
        if (node.right != null) {
          Q.push(node.right)
        }
      }
      return result
    } else {
      return null
    }
  }
}

const bst = new BinarySearchTree()

bst.insert(3)
bst.insert(34)
bst.insert(2)
bst.insert(25)
bst.insert(74)
bst.insert(51)
bst.insert(7)
bst.insert(46)
bst.insert(31)

console.log(bst.findMinHeight())
console.log(bst.findMaxHeight())
console.log(bst.isBalanced())
bst.insert(10)
console.log(bst.findMinHeight())
console.log(bst.findMaxHeight())
console.log(bst.isBalanced())
console.log('inOrder: ' + bst.inOrder())
console.log('preOrder: ' + bst.preOrder())
console.log('postOrder: ' + bst.postOrder())
console.log('levelOrder: ' + bst.levelOrder())
