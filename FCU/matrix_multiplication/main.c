#include <stdio.h>
#include <stdlib.h>

int A[100][100]={0} , B[100][100]={0} , C[100][100]={0} ;

void multiplication (int m , int n , int p)
{
    for (int i=0 ; i<m ; ++i)
    {
        for (int j=0 ; j<p ; ++j)
        {
            for (int k=0 ; k<n ; ++k)
            {
                C[i][j] = A[i][k] * B[k][j] ;
            }
        }
    }
}

int main ()
{
    int m , n , p ;
    srand(0) ;
    printf ("Enter the size of matrix m, n, and p: ") , fflush (stdout) ;
    scanf ("%d %d %d" , &m , &n , &p) ;
    for (int i=0 ; i<m ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            A[i][j] = rand()%100 ;
        }
    }
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<p ; ++j)
        {
            B[i][j] = rand()%100 ;
        }
    }
    // multiple
    multiplication (m , n , p) ;
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
        for (int j=0 ; j<p ; ++j)
        {
            printf ("%3d" , B[i][j]) ;
        }
        printf ("\n") ;
    }
    printf ("\nMatrix C:\n") ;
    for (int i=0 ; i<m ; ++i)
    {
        for (int j=0 ; j<p ; ++j)
        {
            printf ("%6d" , C[i][j]) ;
        }
        printf ("\n") ;
    }
    return 0;
}