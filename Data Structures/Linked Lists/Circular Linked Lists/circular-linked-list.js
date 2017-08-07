/* Circular Linked List
*/

function CircularLinkedList() {
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
    var ptr = new Node(val)
    var temp = head
    ptr.next = head

    if (head !== null) {
      while(temp.next != head) {
        temp = temp.next
      }
      temp.next = ptr
    } else {
      ptr.next = ptr
    }
    head = ptr
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

  this.display = function() {
    var temp = head
    var list = ''
    if (head !== null) {
      while(1) {
        list += temp.val + " => "
        temp = temp.next
        if (temp == head)
            break
      }
    }
    console.log(list)
  }
}

var list = new CircularLinkedList()
list.push('Google')
list.push('Facebook')
list.push('Stack Overflow')
list.push('Gmail')
list.push('Github')
list.remove('Gmail')
list.display()
