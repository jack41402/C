#include <stdio.h>

int main()
{
    unsigned int num ;
    printf ("Input a positive integer: ") , fflush(stdout) ;
    scanf ("%u" , &num) ;
    printf ("Binary numeral:      ") ;
    for (int i=1 ; i<=32 ; ++i)
    {
        printf ("%d" , (num>>(32-i))&1) ;
        if (i%4==0) printf (" ") ;
    }
    printf ("\nOctal numeral:       ") ;
    for (int i=1 ; i<=11 ; ++i)
    {
        printf ("%d" , (num>>(33-3*i))&7) ;
        if ((i+1)%3==0) printf (" ") ;
    }
    printf ("\nHexadecimal numeral: ") ;
    for (int i=1 ; i<=8 ; ++i)
    {
        printf ("%X" , (num>>(32-4*i))&15) ;
        if (i%4==0) printf (" ") ;
    }
    return 0;
}
