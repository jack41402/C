// Use a ordered linear list with no duplicate elements to implement set operations.
#include <stdio.h>
#include <stdlib.h>
#include "single_linked_order_linear_list_dynamic_set.h"

// Initialize the linear list L, set size to 0.
void initial (List *L)
{
    *L = NULL ;
}

// The length of the linear list L, returns the number of elements, namely size.
int getSize (List L)
{

    Link link=L ;
    int size=0 ;
    while (link!=NULL)
    {
        link = link->next ;
    }
    return L.size;
}

// Get the capacity of the linear list L.
int getCapacity (List L)
{
    return L.capacity;
}

// Get element e at position i from L, if 0<=i<size, returns e, otherwise; returns -1.
ElemType getElem (List L , int i)
{
    if (0<=i && i<L.size) return L.elem[i];
    else return -1;
}

// Finds the position of element e in L. If successful, returns the position of e;
// otherwise, returns -1.
int search (List L , ElemType e)
{
    for (int i=0 ; i<L.size ; ++i)
    {
        if (L.elem[i]==e) return i;
    }
    return -1;
}

// Insert the element e into L at the appropriate position.
// If successful, returns the position of e; otherwise, returns -1.
int insertElem (List *L , ElemType e)
{
    int pos=0 ;
    for (int i=0 ; i<L->size ; ++i , ++pos)
    {
        if (L->elem[i]>e) break ;
        else if (L->elem[i]==e) return -1;
    }
    for (int i=L->size-1 ; i>=pos ; --i)
    {
        L->elem[i+1] = L->elem[i] ;
    }
    L->elem[pos] = e ;
    L->size++ ;

    if (L->size==L->capacity)
    {
        L->elem = (ElemType *) realloc(L->elem , (L->capacity+SEGMENT) * sizeof(ElemType)) ;
        L->capacity += SEGMENT ;
    }
    return pos;
}

// Removes element e from L. If successful, returns the original position of e;
// otherwise, returns -1.
int removeElem (List *L , ElemType e)
{
    int pos=0 ;
    for (int i=0 ; i<L->size ; ++i , ++pos)
    {
        if (L->elem[i]==e) break ;
        else if (L->elem[i]>e) return -1;
    }
    if (pos==L->size) return -1;
    for (int i=pos ; i<L->size ; ++i)
    {
        L->elem[i] = L->elem[i+1] ;
    }
    L->size-- ;
    if ((L->capacity-L->size)>SEGMENT*2)
    {
        L->elem = (ElemType *) realloc(L->elem , (L->capacity-SEGMENT) * sizeof(ElemType)) ;
        L->capacity -= SEGMENT ;
    }
    return pos;
}

// Destroy the linear list L and release its memory space.
void destroy (List *L)
{
    free(L->elem) ;
    L->size = 0 ;
    L->capacity = SEGMENT ;
}

// Clear the linear list L.
void clear (List *L)
{
    L->elem = (ElemType *) realloc(L->elem , SEGMENT * sizeof(ElemType)) ;
    L->size = 0 ;
    L->capacity = SEGMENT ;
}

// Check whether the linear list L is empty.
// Returns 1 if empty; otherwise, returns 0.
int is_empty (List L)
{
    return L.size==0;
}

// Print elements of the linear list.
// We add this function because of its necessity.
void printlst (List L)
{
    printf("Linear list capacity: %3d\n" , L.capacity) ;
    printf("Number of linear list elements: %3d\n" , L.size) ;
    for (int i=0 ; i<L.size ; ++i)
    {
        printf("%4d" , L.elem[i]) ;
        if ((i+1)%20==0) printf("\n") ;
    }
    if (L.size%20!=0) printf("\n") ;
    printf("\n") ;
}