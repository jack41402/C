#include <stdio.h>

int main()
{
    int a , b , c , flag ;
    do
    {
        printf ("Enter: ") , fflush(stdout) ;
        fflush(stdin) ;
        flag = scanf ("%d %d %d" , &a , &b , &c) ;
    }
    while (flag != 3) ;
    return 0;
}
