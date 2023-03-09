// Use a ordered linear list with no duplicate elements to implement set operations.
#include <stdio.h>
#include <stdlib.h>
#include "linear_list_dynamic_set.h"

// Initialize the linear list L, set size to 0.
void initial (List *L)
{
    L->elem = (ElemType *) calloc(SEGMENT , sizeof(ElemType)) ;
    L->size = 0 ;
    L->capacity = SEGMENT ;
}

// The length of the linear list L, returns the number of elements, namely size.
int getSize (List L)
{
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
    // Overflow
    for (int j=L->size-1 ; j>=pos ; --j)
    {
        L->elem[j+1] = L->elem[j] ;
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
}

// Destroy the linear list L and release its memory space.
void destroy (List *L);

// Clear the linear list L.
void clear (List *L);

// Check whether the linear list L is empty.
// Returns 1 if empty; otherwise, returns 0.
int is_empty (List L);

// Print elements of the linear list.
// We add this function because of its necessity.
void printlst (List L);