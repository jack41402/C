#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linear_list_dynamic_set.h"

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
        if (insertElem(&A , rand()%200)>=0)
    }
    return 0;
}
