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

//double area (int interval , int n , double a , double b)
//{
//    double ans=0 , sum=0 , temp , interval_size , point ;
//    interval_size = (b-a)/interval ;
//    point = a + interval_size / 2 ;
//    for (int i=1 ; i<=interval ; ++i)
//    {
//        temp = 0 ;
//        for (int j=0 ; j<=n ; ++j) temp += coeff[j]*pow(point , j) ;
//        ans += fabs(temp)*interval_size ;
//        point += interval_size ;
//    }
//    return ans;
//}

int main()
{
    int n , interval=1 ;
    double a , b , area=-1 , last=-2 , temp , point , interval_size ;
    printf ("Enter the degree of polynomial P(X): ") , fflush (stdout) ;
    scanf ("%d" , &n) ;
    printf ("Enter two real numbers a and b such that 0<b-a<=5: ") , fflush (stdout) ;
    scanf ("%lf %lf" , &a , &b) ;
    printf ("Polynomial P(X): \n") ;
    polynomial (n) ;
    printf ("Interval [a, b]: [%.4lf, %.4lf]\n" , a , b) ;
    int count=0 ;

    while (fabs(area-last)<1e6)
    {
        interval_size = (b - a) / interval; // Interval size.
        point = a + interval_size / 2; // Middle point of the first interval.
        last = area; // The area of the previous iteration.
        area = 0; // Initial area to zero.
        for (int i=0; i<interval; i++)
        { // Compute bar area of all intervals.
            temp = 0; // Initial polynomial value to 0.
            for (int j=0; j<=n; j++) temp += coeff[j] * pow(point, j); // Evaluate the polynomial area.
            area += fabs(temp) * interval_size ; // Accumulate the area of Riemann sum.
            point += interval_size; // The middle point of the next interval.
        }
        // Output the number of intervals, interval size, and area of this iteration.
        printf("Number of intervals: %d, interval size: %8.6lf, area: %8.6lf\n", interval, interval_size, area);
        fflush (stdout) ;
        interval = interval * 2; // Double the number of partitioned intervals.
    }

//    while (fabs(area-last)<1e6)
//    {
//        last = area ;
//        area = 0 ;
//        interval_size = (b-a)/interval ;
//        point = a + interval_size / 2 ;
//        for (int i=1 ; i<=interval ; ++i)
//        {
//            temp = 0 ;
//            for (int j=0 ; j<=n ; ++j) temp += coeff[j]*pow(point , j) ;
//            area += fabs(temp)*interval_size ;
//            point += interval_size ;
//        }
//        printf ("%.6lf\n" , area) , fflush (stdout) ;
//        count++ , interval *= 2 ;
//    }
    return 0;
}
