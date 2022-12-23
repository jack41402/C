#include<stdio.h>
#include<stdlib.h>
#include"queue_dynamic_array.h"
void initial_queue(Queue *q){
	q->elem=(int *)malloc(sizeof(SEGMENT));
	q->head=q->tail=0;
	free(q->elem);
	q->capacity=SEGMENT;
}
// Set a queue to empty, i.e., reset head and tail of a queue.
void enqueue(Queue *q, int e){
	if(q->tail>=q->capacity) q->elem=(int *)realloc(q->elem, q->capacity+SEGMENT);
	q->elem[q->tail]=e;
	q->tail++;
}
// Insert an element to the tail of a queue.
int dequeue(Queue *q){
	if(is_empty(*q)){
		printf("The queue is empty.\n");
		return 0;
	}
	Queue newq;
	if(get_size(*q)%50==1){
		q->capacity-=SEGMENT;
	}
//	newq.elem = (int *)realloc(q->elem,q->capacity);
//	free(q->elem);
//	q->elem=newq.elem;
//	q->head=0;
//	q->tail=get_size(*q);
	
	//dequeue
	int newElem;
	newElem = q->elem[q->head % q->capacity++];
	return newElem;
}
// Remove an element from the head of a queue.
int head(Queue q){
	return q.elem[q.head ];
}
// Get the element at the head of a queue.
int is_empty(Queue q){
	if(q.head==q.tail) return 1;
	return 0;
}
// Check if a queue is empty or not.¤U
int get_size(Queue q){
	return q.tail-q.head;
}
// Get size of queue (not a basic operation).
void clear(Queue *q){
	free(q->elem);
}
// Clear queue and set capacity to one segment (not a basic operation).
void print_queue(Queue q){
	printf("****Queue elements from head to tail:\n");
	int i;
	for(i=q.head;i<q.tail;i++){
		printf("%d ", q.elem[i]);
	}		
}
// Print elements of a queue from the head to the tail (not a basic operation)

void reAlloc(Queue *q, int size){
	int queue_size = get_size(*q);
	int i;
	Queue newQueue;
	newQueue.elem = (int*) malloc(size * sizeof(int));
	newQueue.head = -1;
	newQueue.tail = -1;
	newQueue.capacity = size;
	for(i=0; i<queue_size; ++i){
		enqueue(&newQueue, dequeue(q));
	}
	
	free(q->elem);
	q->elem = newQueue.elem;
	q->head = newQueue.head;
	q->tail = newQueue.tail;
	q->capacity = size;	
}
