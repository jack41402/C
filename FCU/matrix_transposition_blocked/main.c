#include <stdio.h>
#include <stdlib.h>

int A[100][100]={0} , B[100][100]={0} ;

void transpose(int n , int b)
{
    for (int i0=0 ; i0<n/b ; ++i0)
    {
        for (int j0=0 ; j0<n/b ; ++j0)
        {
            for (int i1=0 ; i1<b ; ++i1)
            {
                for (int j1=0 ; j1<b ; ++j1)
                {
                    B[j0*b+j1][i0*b+i1] = A[i0*b+i1][j0*b+j1] ;
                }
            }
        }
    }
    return;
}

int main ()
{
    int n , b ;
    srand(0) ;
    printf ("Enter the size of square matrix n: ") , fflush (stdout) ;
    scanf ("%d" , &n) ;
    do
    {
        printf ("Enter the size of block b (b%%n=0): ") , fflush (stdout) ;
        scanf ("%d" , &b) ;
    }
    while (n%b!=0) ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            A[i][j] = rand()%100 ;
        }
    }
    // transpose
    transpose (n , b) ;
    printf ("\nMatrix A:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            printf ("%3d" , A[i][j]) ;
        }
        printf ("\n") ;
    }
    printf ("\nMatrix B:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            printf ("%3d" , B[i][j]) ;
        }
        printf ("\n") ;
    }
    return 0;
}
