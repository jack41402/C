#include <stdio.h>
#include <string.h>

char dict[62]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"} ;
int digit[62] , value[62] ;

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
        scanf ("%d" , &base) ;
        unsigned long long int ans=0 , input ;
        char str[100] , to_62[100] ;
        //initialize base 62 to decimal
        initialize() ;
        // to decimal
        if (base==62)
        {
            scanf("%s" , str) ;
            for (int i=0 ; i< strlen(str) ; ++i)
            {
                ans *= 62 ;
                ans += value[str[i]] ;
            }
            printf ("%llu\n" , ans) , fflush(stdout) ;
        }
        else
        {
            scanf ("%llu" , &input) ;
            for (int i=0 ; i<100 && input!=0 ; ++i)
            {
                to_62[i] = dict[input%62] ;
                input /= 62 ;
            }
            printf ("%s\n" , to_62) , fflush(stdout) ;
        }
    }
    return 0;
}
