#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linear_list_dynamic_set.h"

List Union (List R , List S)
{
    List T ;
    int size1= getSize(R) , size2=getSize(S) ;
    ElemType e1 , e2 ;
    int i1=0 , i2=0 ;
    initial(&T) ;

    while (i1<size1 && i2<size2)
    {
        e1 = getElem(R , i1) ;
        e2 = getElem(S , i2) ;
        if (e1==e2)
        {
            insertElem(&T , e1) ;
            i1++ , i2++ ;
        }
        else if (e1<e2)
        {
            insertElem(&T , e1) ;
            i1++ ;
        }
        else
        {
            insertElem(&T , e2) ;
            i2++ ;
        }
    }
    while (i1<size1) insertElem(&T , getElem(R , i1++)) ;
    while (i2<size2) insertElem(&T , getElem(S , i2++)) ;
    return T;
}

List Intersection (List R , List S)
{
    List T ;
    int size1=getSize(R) , size2=getSize(S) ;
    ElemType e1 , e2 ;
    int i1 , i2 ;
    initial(&T) ;

    while (i1<size1 && i2<size2)
    {
        e1 = getElem(R , i1) ;
        e2 = getElem(S , i2) ;

        if (e1==e2)
        {
            insertElem(&T , e1) ;
            i1++ , i2++ ;
        }
        else if (e1<e2) i1++ ;
        else i2++ ;
    }
    return T;
}

List Difference (List R , List S)
{
    List T ;
    int size= getSize(R) ;
    ElemType e ;
    int i=0 ;
    initial(&T) ;

    while (i<size)
    {
        e = getElem(R , i++) ;
        if (search(S , e)<0) insertElem(&T , e) ;
    }
    return T;
}

int main ()
{
    List A , B , C ;
    int length1 , length2 , count ;
    srand(time(NULL)) ;

    initial(&A) , initial(&B) ;
    do
    {
        printf("Enter the size (between 1 and 100 (inclusive)) of set A: ") ;
        scanf("%d" , &length1) ;
    }
    while (length1<0 || length1>100) ;
    do
    {
        printf("Enter the size (between 1 and 100 (inclusive)) of set B: ") ;
        scanf("%d" , &length2) ;
    }
    while (length2<0 || length2>100) ;
    printf("-------------------------------------------\n") ;

    count = 0 ;
    while (count<length1)
    {
        if (insertElem(&A , rand()%200)>=0) count++ ;
    }
    printf("Set A:\n") ;
    printlst(A) ;

    count = 0 ;
    while (count<length2)
    {
        if (insertElem(&B , rand()%200)>=0) count++ ;
    }
    printf("Set B:\n") ;
    printlst(B) ;

    C = Union(A , B) ;
    printf("Union of sets A and B:\n") ;
    printlst(C) ;

    clear(&C) ;
    C = Intersection(A , B) ;
    printf("Intersection of sets A and B:\n") ;
    printlst(C) ;

    clear(&C) ;
    C = Difference(A , B) ;
    printf("Difference of sets A and B:\n") ;
    printlst(C) ;
    return 0;
}
