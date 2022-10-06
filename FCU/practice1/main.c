#include <stdio.h>

int main()
{
    double p , q , r , s , answer ;
    printf ("p: ") , fflush(stdout) ;
    scanf ("%lf" , &p) ;
    printf ("q: ") , fflush(stdout) ;
    scanf ("%lf" , &q) ;
    printf ("r: ") , fflush(stdout) ;
    scanf ("%lf" , &r) ;
    printf ("s: ") , fflush(stdout) ;
    scanf ("%lf" , &s) ;
    //p=-4 , q=3 , r=6 , s=-2
    answer = ((p*p-q*q*q-r*r*r)*(q*q+r-5*s+(4.5*p+2.8*q-5.2*s)/((p*p-r*r)/(3.6*p*r*r*s+2.5*p*p*q*s)))/((p*p-r*r)/(5.5*r+3.2*q-6.5*p-2.4*s))) ;
    printf ("f(p, q, r, s)=%E" , answer) ;
    return 0;
}
