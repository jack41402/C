#include <stdio.h>
#include <stdlib.h>
#include "assign2_d1128309.h"

void initial(List *L)
{
	*L=NULL;
}

int getSize(List L)
{
	int size=0;
	while(L!=NULL)
	{
		L=L->next;
		size++;
	}
	return size;
}

ElemType getElem(List L, int index)
{
    if (L==NULL || getSize(L)-1<index) return -1;
	Link current=L;
	int i;
	for(i=0;i<index;i++){ 
		if (current==NULL) return -1;
		else current=current->next;
	}
	return current->elem;
}

ElemType setElem(List L, ElemType a, int index)
{
	Link link=L;
	int i;
	for(i=0;i<index;i++)
	{
		if(link==NULL) return -1;
		else link=link->next;
	}
	link->elem=L->elem;
	return index;
}

int search(List L, ElemType a)
{
	Link link=L;
	int position=0;
	while (link!=NULL){
		if(link->elem==a) return position;
    	link=link->next;
		position++;
	}
	return -1;
}

int insertElem(List *L, ElemType e) {
	if(search(*L,e)!=-1)
	{
		return -1;
	} 
Link current = *L; // Pointer to the current node.
  Link previous = NULL; // Pointer to the previous node, initially NULL. 
  Link newNode; // Pointer to the new node.
  int position = 0; // Current node position.
	if (*L==NULL)
	{ // Case 1: The linear list is empty.
    newNode = (Link) malloc(sizeof(Node)); // Allocate memory for a new node.
    newNode->elem = e; // Set the data of the head node. 
    newNode->next = NULL; // Set the head node.
    *L = newNode; // The linear list points to the first node.
	return 0; // Return the position of the head node. 
	}
	
  do {
	    previous =  current;// The current node becomes the previous node. 
	    current = current->next; // Set the next node as the current node for the next step. 
	    position++; // Increment the position by 1.
  } while (current!=NULL); // If there are more nodes in the linear list, continue.
  newNode = (Link) malloc(sizeof(Node)); // Allocate memory for a new node.
  newNode->elem = e; // Set the data for the new node.
  newNode->next = NULL; // The last node, set its next node to NULL.
previous->next = newNode; // Put the newly added node at the end of the linear list.
  return position; // Return the position.
}

int deleteElem(List *L, ElemType e) {
	if(*L==NULL) return -1;
	if(search(*L,e)==-1) return -1;
	int pos=0;
	Link current=*L; 
	Link previous=NULL;
	while(current!=NULL){
		if(current->elem==e)
		{
			if(pos==0)
			{
				*L=current->next;
				free(current);
				return pos;				
			}
			else if(current->next!=NULL)
			{
				previous->next=current->next;
				free(current);
				return pos;					
			}
			else
			{
				previous->next=NULL;
				free(current);
				return pos;
			} 
		}
		else
		{
			previous=current;
			current = current->next;
			pos++;
		}
	}
	return -1;
}
void printList(List L)
{
  List current=L;
  int position=0;
  
  printf("The linear list has %3d elements.\n",getSize(L));
  while(current!=NULL){
    printf("%3d ",current->elem);
    if ((++position)%20==0) printf("\n");
    current=current->next;
  }
  if ((position%20)!=0) printf("\n");
  printf("\n");
} 

List append(List L1, List L2)
{
	int s1, s2, i, j;
	List L3,current, appendix; 
	current=L1;
	appendix=L2;
	initial(&L3);	
	while(current!=NULL)
	{
		insertElem(&L3,current->elem);
		current=current->next;
	}
	while(appendix!=NULL)
	{
		if(search(L1,appendix->elem)==-1){
			insertElem(&L3,appendix->elem);
		}
		appendix=appendix->next;
	}
	return L3;
}

List join(List L1, List L2)
{
	int s1, s2, i, j;
	List L4,current, common; 
	current=L1;
	common=L2;
	initial(&L4);
	while(common!=NULL)
	{
		if(search(L1,common->elem)==-1){
		insertElem(&L4,common->elem);
		}
		common=common->next;
	}
	return L4;
}

void sort(List *L)
{
	List current=*L;
	int i, j, Size;
	ElemType tmp;
	Size=getSize(*L);
	for(i=0;i<Size-1;i++)
	{
		current=*L;
		for(j=i;j<Size-1;j++){
			if(current->elem>current->next->elem)
				{
					tmp=current->elem;
					current->elem=current->next->elem;
					current->next->elem=tmp;
				}
			current=current->next;
		}	
	}
}
