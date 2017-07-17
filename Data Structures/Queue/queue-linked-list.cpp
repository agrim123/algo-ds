/* Queue
   - Linked Lists Implementation
   - First In First Out (FIFO)
   - Three basic operations on Queues:
        1. Enqueue -> add item to rear
        2. Dequeue -> remove item from front
        3. Front
        4. Rear
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

// A linked list node to store a queue entry
struct QNode {
    int key;
    struct QNode *next;
};

// The queue, front stores the front node of linked list and rear stores the last node of linked list
struct Queue {
    struct QNode *front, *rear;
};

// Function to create an linked list node
struct QNode* new_node(int x) {
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = x;
    temp->next = NULL;
    return temp; 
}


// Function to create an empty queue
struct Queue *create_queue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add a key k to queue
// Time Complexity :: O(1)
void enqueue(struct Queue *queue, int k)
{
    // Create a new Linked List node
    struct QNode *temp = new_node(k);
 
    // If queue is empty, then new node is front and rear both
    if (queue->rear == NULL)
    {
       queue->front = queue->rear = temp;
       return;
    }
 
    // Add the new node at the end of queue and change rear
    queue->rear->next = temp;
    queue->rear = temp;
}
 
// Function to remove a key from given queue queue
// Time Complexity :: O(1)
struct QNode *dequeue(struct Queue *queue)
{
    // If queue is empty, return NULL.
    if (queue->front == NULL)
       return NULL;
 
    // Store previous front and move front one node ahead
    struct QNode *temp = queue->front;
    queue->front = queue->front->next;
 
    // If front becomes NULL, then change rear also as NULL
    if (queue->front == NULL)
       queue->rear = NULL;
    return temp;
}

int main() {
    struct Queue *q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    struct QNode *n = dequeue(q);
    if (n != NULL)
      cour<<"Dequeued item is "<<n->key<<endl;
    return 0;
}