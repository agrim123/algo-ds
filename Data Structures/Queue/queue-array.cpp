/*
 * Queue: Array Implementation
 *
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* create_queue(unsigned capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Returns true if queue if full else returns false
// Time Complexity :: O(1)
int is_full(struct Queue* queue) {
    return queue->size == queue->capacity;
}

// Returns true if queue if empty else returns false
// Time Complexity :: O(1)
int is_empty(struct Queue* queue) {
    return queue->size == 0;
}

// Adds element at end of queue
// Time Complexity :: O(1)
void enqueue(struct Queue* queue, int x) {
    if (is_full(queue)) return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = x;
    queue->size = queue->size + 1;
}

// Removes element from front of queue
// Time Complexity :: O(1)
int dequeue(struct Queue* queue) {
    if (is_full(queue)) return 0;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Time Complexity :: O(1)
int front(struct Queue* queue) {
    if (is_empty(queue)) return 0;
    return queue->array[queue->front];
}

// Time Complexity :: O(1)
int rear(struct Queue* queue) {
    if (is_empty(queue)) return 0;
    return queue->array[queue->rear];
}

int main() {
    struct Queue* queue = create_queue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    cout<<dequeue(queue)<<" dequeued from queue"<<endl;

    cout<<"Front item is "<<front(queue)<<endl;
    cout<<"Rear item is "<<rear(queue)<<endl;

    return 0;
}
