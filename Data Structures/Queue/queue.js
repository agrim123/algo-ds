/*
 * Queue: Array Implementation
 *
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
