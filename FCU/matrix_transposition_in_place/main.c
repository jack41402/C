#include <stdio.h>
#include <stdlib.h>

int A[100][100]={0} , B[100][100]={0} ;

void swap(int *x , int *y)
{
    int temp ;
    temp = *x ;
    *x = *y ;
    *y = temp ;
    return;
}

void transpose(int n)
{
    for (int i=0 ; i<n ; ++i)
    {
        // The loop only scan half of the matrix elemets except the diagonl.
        // Therefore, j must less than i.
        for (int j=0 ; j<i ; ++j)
        {
            swap (&A[i][j] , &A[j][i]) ;
        }
    }
    return;
}

int main ()
{
    int n ;
    srand(0) ;
    printf ("Enter the size of square matrix n: ") , fflush (stdout) ;
    scanf ("%d" , &n) ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            A[i][j] = rand()%100 ;
        }
    }
    printf ("\nMatrix A Before:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            printf ("%3d" , A[i][j]) ;
        }
        printf ("\n") ;
    }
    // transpose
    transpose (n) ;
    printf ("\nMatrix A After:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            printf ("%3d" , A[i][j]) ;
        }
        printf ("\n") ;
    }
    return 0;
}
