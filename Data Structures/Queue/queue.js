/*
    Queue
        - Array Implementation
        - First In First Out (FIFO)
        - Three basic operations on Queues:
            1. Enqueue -> add item to rear
            2. Dequeue -> remove item from front
            3. Front
            4. Rear
*/

function Queue () {
    store = []
    this.print = () => {
        console.log(store)
    }

    this.enqueue = (element) => {
        store.push(element)
    }

    this.dequeue = () => {
        return store.shift()
    }

    this.front = () => {
        return store[0]
    }

    this.rear = () => {
        return store[store.length - 1]
    }

    this.size = () => {
        return store.length
    }

    this.isEmpty = () => {
        return (store.length === 0)
    }
}

let q = new Queue()
q.enqueue('a')
q.enqueue('b')
q.enqueue('c')
q.print()
q.dequeue()
console.log(q.front())
console.log(q.rear())
q.print()
