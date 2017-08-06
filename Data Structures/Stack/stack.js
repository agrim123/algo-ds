/* Stacks
    - Basic operations on Stacks:
        1. Push
        2. Pop
        3. Peek
*/

var Stack = function() {
    this.count = 0
    this.storage = {}

    this.push = function(value) {
        this.storage[this.count] = value
        this.count++
    }

    this.pop = function() {
        if (this.count === 0) {
            return undefined
        }

        this.count--
        var result = this.storage[this.count]
        delete this.storage[this.count]
        return result
    }

    this.size = function() {
        return this.count
    }

    this.peek = function() {
        return this.storage[this.count-1]
    }
}

var newStack = new Stack()

newStack.push(1)
newStack.push(2)
newStack.push("freeCodeCamp")
newStack.peek()
newStack.pop()
newStack.peek()
newStack.size()
newStack.peek()
newStack.pop()
newStack.peek()
console.log(newStack.storage)
