#include <stdio.h>
#include <stdlib.h>

double A[100][100]={0}  , A1[100][100]={0} , L[100][100]={0} , U[100][100]={0} ;

int min (int x , int y)
{
    return ((x<y) ? x : y);
}

int max (int x , int y)
{
    return ((x>y) ? x : y);
}

void LU_decompose (int n)
{
    for (int k=0 ; k<n ; ++k)
    {
        for (int j=k ; j<n ; ++j) U[k][j] = A[k][j] ;
        for (int i=k ; i<n ; ++i) L[i][k] = A[i][k]/A[k][k] ;
        for (int i=k+1 ; i<n ; ++i)
            for (int j=k+1 ; j<n ; ++j) A[i][j] -= L[i][k]*U[k][j] ;
    }
}

int main ()
{
    int n ;
    srand(0) ;
    printf ("Enter the size of matrix n: ") , fflush (stdout) ;
    scanf ("%d" , &n) ;
    printf ("\nMatrix A:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            A[i][j] = (rand()%10000+1) / 10000.0 ;
            A1[i][j] = A[i][j] ;
            printf ("%10.4lf" , A[i][j]) ;
        }
        printf ("\n") ;
    }
    // multiple
    LU_decompose (n) ;
    printf ("\nMatrix L:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<=i ; ++j)
        {
            printf ("%10.4lf" , L[i][j]) ;
        }
        printf ("\n") ;
    }
    printf ("\nMatrix U:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<i ; ++j)
        {
            printf ("          ") ;
        }
        for (int j=i ; j<n ; ++j)
        {
            printf ("%10.4lf" , U[i][j]) ;
        }
        printf ("\n") ;
    }
    return 0;
}