#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int count=0 ;

double determinant (double **matrix , int n)
{
    double **cofactor ;
    double det=0 ;
    if (n==1) det = matrix[0][0] ;
    else
    {
        cofactor = (double **) malloc (sizeof (double *) * (n-1));
        for (int j=0 ; j<n-1 ; j++) cofactor[j] = (double *) malloc(sizeof (double) * (n-1));
        for (int j=0 ; j<n ; ++j)
        {
            for (int p=0 ; p<n-1 ; ++p)
            {
                for (int q=0 ; q<n-1 ; ++q)
                {
                    if (q<j) cofactor[p][q] = matrix[p+1][q] ;
                    else if (q>=j) cofactor[p][q] = matrix[p+1][q+1] ;
                }
            }
            det += pow (-1 , j%2) * matrix[0][j] * determinant (cofactor , n-1) ;
        }
        for (int j=0 ; j<n-1 ; j++) free (cofactor[j]) ;
        free (cofactor) ;
    }
    count++ ;
    return det;
}

int main ()
{
    int n ;
    double **A ;
    clock_t start , finish ;
    srand(0) ;
    do
    {
        printf ("Enter the size of matrix n (1<=n<=12): ") , fflush (stdout);
        scanf ("%d" , &n);
    }
    while (!(1<=n && n<=12)) ;

    printf ("\nMatrix A:\n") ;
    A = (double **) malloc (sizeof (double *) * n) ;
    for (int i=0 ; i<n ; i++)
    {
        A[i] = (double *) malloc (sizeof (double) * n) ;
        for (int j=0 ; j<n ; j++)
        {
            A[i][j] = rand() % 10000 / 10000.0 ;
            printf ("%8.4lf" , A[i][j]) ;
        }
        printf ("\n") ;
    }

    start = clock() ;
    printf ("\nDeterminant: %8.4f\n\n", determinant(A, n)) ;
    finish = clock() ;

    printf ("The number of function calls to determinant() is %d.\n", count) ;
    printf ("The computing time of determinant() is : %6.4E seconds\n\n" , (double)(finish - start) / CLOCKS_PER_SEC) ;

    for (int i=0 ; i<n ; i++) free (A[i]) ;
    free (A) ;

    return 0;
}