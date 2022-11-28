#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double coeff[15] ;

void polynomial (int n)
{
    srand (time (NULL)) ;
    for (int i=n ; i>=0 ; --i)
    {
        coeff[i] = (rand() % 2001) / 1000.0 - 1.0 ; // (1 -(-1)) * rand() / (RAND_MAX + 1.0) - 1
        if (i==n) printf ("%.4lf X^%d" , coeff[i] , n) ;
        else
        {
            printf (" %c %.4lf %s" , (coeff[i]>0) ? '+' : '-' , fabs(coeff[i]) , (i!=0) ? "X^" : "") ;
            if (i!=0) printf ("%d" , i) ;
        }
    }
    printf ("\n") ;
}

void area (int n , double a , double b)
{
    int interval=1 ;
    double area=-1 , last=-2 , temp , point , interval_size ;
    while (fabs(area-last)>1e-6)
    {
        last = area ;
        area = 0 ;
        interval_size = (b-a)/interval ;
        point = a + interval_size / 2 ;
        for (int i=1 ; i<=interval ; ++i)
        {
            temp = 0 ;
            for (int j=0 ; j<=n ; ++j) temp += coeff[j]*pow(point , j) ;
            area += fabs(temp)*interval_size ;
            point += interval_size ;
        }
        printf ("Number of intervals: %d, interval size: %8.6lf, area: %8.6lf\n" , interval , interval_size , area) , fflush (stdout) ;
        interval *= 2 ;
    }
    printf ("\nThe number of intervals: %d\n" , interval/2) ;
    printf ("Area of polynomial P(x) between (%6.4lf, 0.0) and (%6.4lf, 0.0): %8.6lf\n" , a , b , area) ;
    return;
}

int main()
{
    int n ;
    double a , b ;
    printf ("Enter the degree of polynomial P(X): ") , fflush (stdout) ;
    scanf ("%d" , &n) ;
    printf ("Enter two real numbers a and b such that 0<b-a<=5: ") , fflush (stdout) ;
    scanf ("%lf %lf" , &a , &b) ;
    printf ("Polynomial P(X): \n") ;
    polynomial (n) ;
    printf ("Interval [a, b]: [%.4lf, %.4lf]\n" , a , b) ;
    area (n , a , b) ;
    return 0;
}