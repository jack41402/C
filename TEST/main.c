#include <stdio.h>

unsigned long long arr[100]={0} ;

unsigned long long Fib (int n)
{
    if (arr[n]==0)
    {
        arr[n] = Fib(n-1) + Fib(n-2) ;
    }
    else return arr[n];
}

int main()
{
    arr[0]=1 , arr[1]=1 ;
    int n ;
    scanf ("%d" , &n) ;
    printf ("%llu\n" , Fib(n)) ;
}