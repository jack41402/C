#include <stdio.h>
#include <math.h>

double upper_circle (double x)
{
    return sqrt (100-x*x);
}

double lower_circle (double x)
{
    return -sqrt (100-x*x);
}

void area (double a , double b)
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
            area += fabs(upper_circle (point)- lower_circle (point))*interval_size ;
            point += interval_size ;
        }
        printf ("Number of intervals: %d, interval size: %8.6lf, area: %8.6lf\n" , interval , interval_size , area) , fflush (stdout) ;
        interval *= 2 ;
    }
    printf ("\nThe number of intervals: %d\n" , interval/2) ;
    printf ("Area of polynomial P(x) between (%6.4lf, 0.0) and (%6.4lf, 0.0): %8.6lf\n" , a , b , area) ;
    return;
}

int main ()
{
    double a , b ;
    printf ("Enter two real numbers a and b between -10 and 10: ") , fflush (stdout) ;
    scanf ("%lf %lf" , &a , &b) ;
    area (a , b) ;
    return 0;
}
