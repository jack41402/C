#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n ;
double **A , **A1 , **L , **U ;

void LU_decompose ()
{
    for (int k=0 ; k<n ; ++k)
    {
        for (int j=k ; j<n ; ++j) U[k][j] = A[k][j] ;
        for (int j=k ; j<n ; ++j) L[j][k] = A[j][k] / A[k][k] ;
        for (int i=k+1 ; i<n ; ++i)
            for (int j=k+1 ; j<n ; ++j) A[i][j] = A[i][j] - L[i][k] * U[k][j] ;
    }
}

int main ()
{
    printf ("Enter the size n of the matrix: ") , fflush (stdout) ;
    scanf ("%d" , &n) ;
    A = (double **) malloc (n * sizeof (double*)) ;
    A1 = (double **) malloc (n * sizeof (double*)) ;
    L = (double **) malloc (n * sizeof (double*)) ;
    U = (double **) malloc (n * sizeof (double*)) ;
    for (int i=0 ; i<n ; ++i)
    {
        A[i] = (double *) malloc (n * sizeof (double)) ;
        A1[i] = (double *) malloc (n * sizeof (double)) ;
        L[i] = (double *) malloc ((i+1) * sizeof (double)) ;
        U[i] = (double *) malloc ((n-i) * sizeof (double)) ;
    }
    srand (time(NULL)) ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<n ; ++j)
        {
            A[i][j] = ((rand() % 10000) + 1 )/10000.0 ;
            A1[i][j] = A[i][j] ;
            printf ("%10.4lf" , A[i][j]) ;
        }
        printf ("\n") ;
    }
    LU_decompose() ;
    printf ("\n\nMatrix L:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<=i ; ++j)
        {
            printf ("%10.4lf" , L[i][j]) ;
        }
        printf ("\n") ;
    }
    printf ("\n\nMatrix U:\n") ;
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
/*
  A = (float **) malloc(n * sizeof(float *)); // Allocate the first dimension of matrix A.
  A1 = (float **) malloc(n * sizeof(float *)); // Allocate the first dimension of matrix A1.
  L = (float **) malloc(n * sizeof(float *)); // Allocate the first dimension of matrix L.
  U = (float **) malloc(n * sizeof(float *)); // Allocate the first dimension of matrix U.
  for (i=0; i<n; i++) {
  	A[i] = (float *) malloc(n * sizeof(float)); // Allocate the second dimension of matrix A.
  	A1[i] = (float *) malloc(n * sizeof(float)); // Allocate the second dimension of matrix A1.
  	L[i] = (float *) malloc((i+1) * sizeof(float)); // Allocate the second dimension of matrix L.
  	U[i] = (float *) malloc((n-i) * sizeof(float)); // Allocate the second dimension of matrix U.
  }
*/