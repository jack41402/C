#define SEGMENT 50 // Segment size.
// Type definition of queues using a dynamic array.
// The queue elements of integers.
typedef struct {
int *elem; // Pointer to queue container.
int head; // Index of the queue head.
int tail; // Index of the queue tail.
int capacity; //  of a queue.
} Queue;
void initial_queue(Queue *);// Set a queue to empty, i.e., reset head and tail of a queue.
void enqueue(Queue *, int);// Insert an element to the tail of a queue.
int dequeue(Queue *);// Remove an element from the head of a queue.
int head(Queue);// Get the element at the head of a queue.
int is_empty(Queue);// Check if a queue is empty or not.¤U
int get_size(Queue);// Get size of queue (not a basic operation).
void clear(Queue *);// Clear queue and set capacity to one segment (not a basic operation).
void print_queue(Queue);// Print elements of a queue from the head to the tail (not a basic operation)
