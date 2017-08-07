/*
    Single Linked List
    - Operations
        - Push at head of list
        - Insert after a node
        - Append node at end
        - Delete node with given key
        - Delete node at given position
*/

function SingleLinkedList() {
  var size = 0
  var head = null

  var Node = function(val) {
    this.val = val
    this.next = null
  }

  this.size = function() {
    return size
  }

  this.head = function() {
    return head
  }

  this.push = function(val) {
    var node = new Node(val)
    if(head === null){
        head = node
    } else {
        var currentNode = head

        while(currentNode.next){
            currentNode  = currentNode.next
        }

        currentNode.next = node
    }

    size++
  }

  this.remove = function(val){
    var currentNode = head
    var previousNode
    if(currentNode.val === val){
        head = currentNode.next
    } else {
      while(currentNode.val !== val) {
          previousNode = currentNode
          currentNode = currentNode.next
      }
      previousNode.next = currentNode.next
    }
    size --
  }

  this.positionOf = function(val) {
    var currentNode = head
    var index = -1

    while (currentNode) {
      index++
      if(currentNode.val === val){
          return index
      }
      currentNode = currentNode.next
    }
    return -1
  }

  this.insertAt = function(index, val){
    var node = new Node(val)

    var currentNode = head
    var previousNode
    var currentIndex = 0

    if(index > size){
        return false
    }

    if(index === 0){
        node.next = currentNode
        head = node
    } else {
        while(currentIndex < index){
            currentIndex++
            previousNode = currentNode
            currentNode = currentNode.next
        }
        node.next = currentNode
        previousNode.next = node
    }
    size++
    return true
  }

  this.removeAt = function(index) {
    var currentNode = head
    var previousNode
    var currentIndex = 0
    if (index < 0 || index >= size){
        return null
    }
    if(index === 0){
        head = currentNode.next
    } else {
        while(currentIndex < index) {
            currentIndex ++
            previousNode = currentNode
            currentNode = currentNode.next
        }
        previousNode.next = currentNode.next
    }
    size--
    return currentNode.val
  }

  this.display = function() {
    var currentNode = head
    var list = ''
    while (currentNode !== null) {
      list += currentNode.val + " => "
      currentNode = currentNode.next
    }
    console.log(list)
  }

}

var list = new SingleLinkedList()
list.push('Google')
list.push('Facebook')
list.push('Stack Overflow')
list.push('Gmail')
list.push('Github')
console.log(list.size())
console.log(list.removeAt(3))
console.log(list.positionOf('Gmail'))
console.log(list.size())
if (!list.insertAt(2, 'Added')) {
  console.log('Index Out of range!!')
}
list.display()
