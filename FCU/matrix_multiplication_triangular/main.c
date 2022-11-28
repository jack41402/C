#include <stdio.h>
#include <stdlib.h>

int A[100][100]={0} , B[100][100]={0} , C[100][100]={0} ;

int min (int x , int y)
{
    return ((x<y) ? x : y);
}

void multiplication (int n)
{
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            for (int k=0 ; k<=min (i , j) ; ++k)
            {
                C[i][j] += A[i][k] * B[k][j] ;
            }
        }
    }
}

int main ()
{
    int n ;
    srand(0) ;
    printf ("Enter the size of matrix n: ") , fflush (stdout) ;
    scanf ("%d" , &n) ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<=i ; ++j)
        {
            A[i][j] = rand()%100 ;
        }
    }
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=i ; j<n ; ++j)
        {
            B[i][j] = rand()%100 ;
        }
    }
    // multiple
    multiplication (n) ;
    printf ("\nMatrix A:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<=i ; ++j)
        {
            printf ("%3d" , A[i][j]) ;
        }
        printf ("\n") ;
    }
    printf ("\nMatrix B:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<i ; ++j)
        {
            printf ("   ") ;
        }
        for (int j=i ; j<n ; ++j)
        {
            printf ("%3d" , B[i][j]) ;
        }
        printf ("\n") ;
    }
    printf ("\nMatrix C:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            printf ("%6d" , C[i][j]) ;
        }
        printf ("\n") ;
    }
    return 0;
}