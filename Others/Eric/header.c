#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//typedef int ElemType;
//typedef struct node {
//	ElemType elem;
//	struct node* next;
//} Node;
//typedef Node* Link;
//typedef Link List;

// Initialize a linear list, set its size to 0.
void initial(List *head){
	head = NULL;
	return;
}

// The length of a linear list, returns the number of elements, namely size.
int getSize(List lst){
	int size = 0;
	
	while(lst.next != NULL){
		lst = lst.next;
		size++;
	}
	return size;
}

// Get the element at a position from a linear list, return the designated element.
ElemType getElem(List lst, int index){
	int ecx = 0;
	
	while(ecx != index){
		lst = lst.next;
		ecx++;
	}
	return lst.elem;
}

// Set the element at a position in a linear list to a specific element.
void setElem(List lst, ElemType data, int index){
	int ecx = 0;
	
	while(ecx != index){
		lst = lst.next;
		ecx++;
	}
	lst.elem = data;
	return;
}

// Find the position of an element in L. If successful, return the position of the
// element; otherwise, returns -1.
int search(List lst, ElemType data){
	index = 0;
	
	while (lst.next != NULL){ // loop until the end of list
		if (lst.elem == data){
			return index;
		}
		index++;
	}
	return -1;
}

// Insert an element after the end of a linear list, return the position of the
// inserted element. If the inserted element exists in the linear list or the linear list
// is overflow, insertElem() fails, and returns -1.
int insertElem(List *lst, ElemType data){
	
	return;
}

// Delete an element from a list. If the element is in the linear list, delete it and
// return its position; otherwise, return -1.
int deleteElem(List *lst, ElemType data){
	return;
}

// Print all elements of the linear list starting from the head.
int printList(List lst){
	return;
}