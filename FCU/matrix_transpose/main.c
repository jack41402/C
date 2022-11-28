#include <stdio.h>
#include <stdlib.h>

int A[100][100]={0} , B[100][100]={0} ;

int main ()
{
    int m , n ;
    srand(0) ;
    printf ("Enter the size of matrix (m, n): ") ;
    scanf ("%d %d" , &m , &n) ;
    for (int i=0 ; i<m ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            A[i][j] = rand()%100 ;
            B[j][i] = A[i][j] ;
        }
    }
    printf ("\nMatrix A:\n") ;
    for (int i=0 ; i<m ; ++i)
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
        for (int j=0 ; j<m ; ++j)
        {
            printf ("%3d" , B[i][j]) ;
        }
        printf ("\n") ;
    }
    return 0;
}
