// Priority Queue

function PriorityQueue () {
  let store = []

  this.printStore = () => {
    console.log(store)
  }

  this.enqueue = (el) => {
    if (this.isEmpty()){
      store.push(el)
    } else {
      let added = false
      for (let i=0 ;i<store.length ;i++) {
        if (el[1] < store[i][1]) {
          store.splice(i,0,el)
          added = true
          break
        }
      }
      if (!added){
        store.push(el)
      }
    }
  }

  this.dequeue = () => {
    let value = store.shift()
    return value[0]
  }

  this.front = () => {
    return store[0]
  }

  this.size = () => {
    return store.length
  }

  this.isEmpty = () => {
    return (store.length === 0)
  }
}

let p = new PriorityQueue()
p.enqueue(['Google', 9])
p.enqueue(['Facebook', 3])
p.enqueue(['Stack Overflow', 1])
p.enqueue(['Gmail', 7])
p.printStore()
p.dequeue()
console.log(p.front())
p.printStore()
