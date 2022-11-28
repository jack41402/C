#include <stdio.h>
#include <stdlib.h>

int A[100][100]={0} , B[100][100]={0} , C[100][100]={0} ;

int min (int x , int y)
{
    return ((x<y) ? x : y);
}

int max (int x , int y)
{
    return ((x>y) ? x : y);
}

void multiplication (int n , int ra , int sa , int rb , int sb)
{
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=max (0 , i-ra-rb) ; j<=min (n-1 , i+sa+sb) ; ++j)
        {
            for (int k=max (0 , max (i-ra , j-sb)) ; k<=min (n-1 , min (i+sa , j+rb)) ; ++k)
            {
                C[i][j] += A[i][k] * B[k][j] ;
            }
        }
    }
}

int main ()
{
    int n , ra , sa , rb , sb ;
    srand(0) ;
    printf ("Enter the size of matrix n: ") , fflush (stdout) ;
    scanf ("%d" , &n) ;
    printf ("Enter lower and upper bandwidth of matrix A: ") , fflush (stdout) ;
    scanf ("%d %d" , &ra , &sa) ;
    printf ("Enter lower and upper bandwidth of matrix B: ") , fflush (stdout) ;
    scanf ("%d %d" , &rb , &sb) ;
    printf ("\nMatrix A:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<max (0 , i-ra) ; ++j) printf ("   ") ;
        for (int j=max (0 ,  i-ra) ; j<=min (i+sa , n-1) ; ++j)
        {
            A[i][j] = rand()%100 ;
            printf ("%3d" , A[i][j]) ;
        }
        printf ("\n") ;
    }
    printf ("\nMatrix B:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<max (0 , i-rb) ; ++j) printf ("   ") ;
        for (int j=max (0 ,  i-rb) ; j<=min (i+sb , n-1) ; ++j)
        {
            B[i][j] = rand()%100 ;
            printf ("%3d" , B[i][j]) ;
        }
        printf ("\n") ;
    }
    // multiple
    multiplication (n , ra , sa , rb , sb) ;
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