#include <stdio.h>
#include <string.h>

char dict[62]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"} ;
int value[128] ;

void to_int (char str[] , unsigned long long int *input)
{
    *input = 0 ;
    for (int i=0 ; i<strlen(str) ; ++i)
    {
        *input *= 10 ;
        *input += (str[i]-'0') ;
    }
}

void initialize ()
{
    for (int i=0 ; i<62 ; ++i)
    {
        value[dict[i]] = i ;
    }
}

int main()
{
    int base ;
    while (1)
    {
        printf ("Input the numeral base and the numeral as a string: ") , fflush(stdout) ;
        scanf ("%d" , &base) ;
        unsigned long long int ans=0 , input ;
        char str[100]={} , to_62[100]={} ;
        //initialize base 62 to decimal
        initialize() ;
        scanf("%s" , str) ;
        if (base==0 && str[0]=='0') break ;
        // to decimal
        if (base==62)
        {
            printf ("Base62 numeral %s is equivalent to decimal numeral: " , str) ;
            for (int i=0 ; i< strlen(str) ; ++i)
            {
                ans *= 62 ;
                ans += value[str[i]] ;
            }
            printf ("%llu\n" , ans) ;
        }
        else if (base==10)
        {
            printf ("Decimal number %s is equivalent to base62 numeral: " , str) ;
            to_int(str , &input) ;
            for (int i=0 ; i<100 && input!=0 ; ++i)
            {
                to_62[i] = dict[input%62] ;
                input /= 62 ;
            }
            for (int i=strlen(to_62)-1 ; i>=0 ; --i)
            {
                printf("%c" , to_62[i]) ;
            }
            printf ("\n") ;
        }
        printf ("\n") ;
        fflush (stdout) ;
    }
    return 0;
}
