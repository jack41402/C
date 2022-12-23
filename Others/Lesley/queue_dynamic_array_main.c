#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"queue_dynamic_array.h"
int main(){
	Queue q;
	srand(time(NULL));
	initial_queue(&q);
	int i, j, enqueue_count, dequeue_count;
	int trial = rand() % 10 + 1;
	for(i=0;i<trial;i++){
		printf(">>>> Trial %d:\n",i+1);
		enqueue_count = rand() % 100 + 1;
		printf("Insert %d elements to queue Q. Content of queue Q after inserting elements:\nQueue capacity: %d\nQueue size    : %d\n", enqueue_count, q.capacity, get_size(q));
		for(j=0;j<enqueue_count;j++){
			enqueue(&q, rand() % 100);
		}
		print_queue(q);
		dequeue_count = rand() % get_size(q) + 1;
		printf("\n\nRemove %d elements to queue Q. Content of queue Q after removing elements:\nQueue capacity: %d\nQueue size    : %d\n", dequeue_count, q.capacity, get_size(q));
		for(j=q.head;j<q.tail;j++){
			dequeue(&q);
		}
		print_queue(q); 
		Queue newq;
		for(j=q.head;j<q.tail;j++){
			enqueue(&newq, dequeue(&q));
		}
		newq.elem = (int *)realloc(q.elem,q.capacity);
	}  
	return 0;
}
