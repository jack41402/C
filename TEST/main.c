#include <stdio.h>

int main()
{
    int a , b , c , flag ;
    do
    {
        printf ("Enter: ") , fflush(stdout) ;
        fflush(stdin) ;
        flag = scanf ("%d %d %d" , &a , &b , &c) ;
        printf ("%d %d %d\n" , a , b , c) ;
        printf ("%d" , flag) ;
    }
    while (flag != 3) ;
    return 0;
}
