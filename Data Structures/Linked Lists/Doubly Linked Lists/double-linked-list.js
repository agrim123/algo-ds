// Double Linked Lists

function DoubleLinkedList() {
  var head = null

  var Node = function(val) {
    this.val = val
    this.next = null
    this.prev = null
  }

  this.head = function() {
    return head
  }

  this.push = function(val) {
    var node = new Node(val)
    node.next = head
    if (head !== null) {
      head.prev = node
    }
    head = node
  }

  this.remove = function(val){
    var currentNode = head
    var previousNode
    if(currentNode.val === val){
        head = currentNode.next
        currentNode.next.prev = head
    } else {
      while(currentNode.val !== val) {
          previousNode = currentNode
          currentNode = currentNode.next
      }
      previousNode.next = currentNode.next
    }
  }

  this.insertAt = function(index, val){
    var new_node = new Node(val)

    var currentNode = head
    var previousNode
    var currentIndex = 0

    if(index === 0){
        new_node.next = currentNode
        new_node.prev = null
        head.prev = new_node
        head = new_node
    } else {
        while(currentIndex < index){
            currentIndex++
            previousNode = currentNode
            currentNode = currentNode.next
        }
      new_node.next = currentNode
      previousNode.next = new_node
    }
    return true
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

var list = new DoubleLinkedList()
list.push('Google')
list.push('Facebook')
list.push('Stack Overflow')
list.push('Gmail')
list.push('Github')
list.remove('Github')
if (!list.insertAt(4, 'Added')) {
  console.log('Index Out of range!!')
}
list.display()
