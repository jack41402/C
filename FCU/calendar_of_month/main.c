#include <stdio.h>

char name_of_month[12][10]={"January" , "February" , "March" , "April" , "May" , "June" , "July" , "August" , "September" , "October" , "November" , "December"};
int days_of_month[12]={31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31} ;

int main()
{
    do
    {
        int month , day , weekday , count ;
        printf (">>>> Enter a month (0 to quit): ") ;
        scanf ("%d" , &month) ;
        if (month==0) break ;
        else if (0<=month && month<=12)
        {
            printf ("\n>>>> Enter a day (between 1 and %d): " , days_of_month[month-1]) ;
            scanf ("%d" , &day) ;
            if (1<=day && day<=days_of_month[month-1])
            {
                printf ("\n0: Sunday    1: Monday  2: Tuesday  3: Wednesday\n") ;
                printf ("4: Thursday  5: Friday  6: Saturday\n") ;
                printf (">>>> Enter a weekday (between 0 and 6): ") ;
                scanf ("%d" , &weekday) ;
                if (0<=weekday && weekday<=6)
                {
                    weekday = ((weekday - day + 1) % 7 + 7) % 7 ;
                    printf("\n    %s\n", name_of_month[month-1]) ;
                    printf("    Sun Mon Tue Wed Thu Fri Sat\n") ;
                    printf("    ") ;
                    count = days_of_month[month-1] ;
                    for (int i=0 ; i<weekday ; i++) printf("    ") ;
                    for (int i=1 ; i<=days_of_month[month-1] ; ++i)
                    {
                        printf ("%2d" , i) ;
                        weekday = (weekday+1)%7 ;
                        if (weekday==0) printf ("\n    ") ;
                    }
                    if (weekday!=0) printf("\n") ;
                }
                else printf("****Error: %d is not a valid weekday.\n" , weekday) ;
            }
            else printf("****Error: %d is not a valid day for the month of %s.\n" , day , name_of_month[month-1]) ;
        }
        else printf ("****Error: %d is not a valid month.\n" , month) ;
        printf("\n---------------------------------------------------------------\n\n");
    }
    while (1) ;
    return 0;
}
