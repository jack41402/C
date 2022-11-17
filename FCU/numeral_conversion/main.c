#include <stdio.h>
#include <string.h>

void print_bin (unsigned int num)
{
    printf ("Binary numeral:      ") ;
    for (int i=1 ; i<=32 ; ++i)
    {
        if ((num>>(32-i))==0) continue ;
        printf ("%d" , (num>>(32-i))&1) ;
        if (i%4==0) printf (" ") ;
    }
    printf ("\n") ;
}

void print_oct (unsigned int num)
{
    printf ("Octal numeral:       ") ;
    for (int i=1 ; i<=11 ; ++i)
    {
        if ((num>>(33-3*i))==0) continue ;
        printf ("%d" , (num>>(33-3*i))&7) ;
        if ((i+1)%3==0) printf (" ") ;
    }
    printf ("\n") ;
}

void print_dec (unsigned int num)
{
    printf ("Decimal numeral:     %u\n" , num) ;
}

void print_hex (unsigned int num)
{
    printf ("Hexadecimal numeral: ") ;
    for (int i=1 ; i<=8 ; ++i)
    {
        if ((num>>(32-4*i))==0) continue ;
        printf ("%X" , (num>>(32-4*i))&15) ;
        if (i%4==0) printf (" ") ;
    }
    printf ("\n") ;
}

int power (int base , int pow)
{
    if (base==0) return 0;
    int ans=1 ;
    while (pow)
    {
        if (pow&1) ans *= base ;
        base *= base ;
        pow >>= 1 ;
    }
    return ans;
}

int main()
{
    int base ;
    unsigned int sum=0 ;
    char num[100]={} ;
    while (1)
    {
        printf ("Input the numeral base and the numeral as a string: ") , fflush(stdout) ;
        scanf ("%d %s" , &base , num) ;
        if (base==0 && strcmp(num , "0")==0) break ;
        printf ("The input numeral %s of base %d has the decimal value: " , num , base) ;
        if (base!=16)
        {
            for (int i=0 ; i< strlen(num) ; ++i)
            {
                sum += (num[i]-'0')*power(base , strlen(num)-i-1) ;
            }
        }
        else
        {
            for (int i=0 ; i< strlen(num) ; ++i)
            {
                if ('0'<=num[i] && num[i]<='9') sum += (num[i]-'0')*power(16 , strlen(num)-i-1) ;
                else if ('A'<=num[i] && num[i]<='F') sum += (num[i]-'A'+10)*power(16 , strlen(num)-i-1) ;
            }
        }
        printf ("%u\n" , sum) ;
        if (base!=2) print_bin (sum) ;
        if (base!=8) print_oct (sum) ;
        if (base!=10) print_dec (sum) ;
        if (base!=16) print_hex (sum) ;
    }
    return 0;
}
