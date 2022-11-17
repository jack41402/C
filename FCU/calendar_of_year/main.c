#include <stdio.h>

const char *name_of_month[12] = {"January" , "February" ,"March" , "April" , "May" , "June" , "July" , "August" , "September" , "October" ,"November" ,"December"} ;
const int days_of_month[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int main()
{
    // Compute the day of week of January 1 of the entered year.
    // Note that when n<0, n%7 is between -6 and 0.
    // Hence, (n%7)+7 will turn it to the postivie congruent value.
    // Howerver, if n%7>=0, we pefrorm modulo operation one more time,
    // ((n%7)+7)%7, to make (n%7)+7 between 0 and 6.
    weekday = ((ww + count) % 7 + 7) % 7;
    return 0;
}
