#include <iostream>

using namespace std;

int main()
{
    int t , n ;
    cin >> t ;
    for(int i=1 ; i<=t ; ++i)
    {
        cin >> n ;
        cout << "Case " << i << ": " ;
        ((n%4==0 && n%100!=0) || n%400==0) ? cout << "a leap year\n" : cout << "a normal year\n" ;
    }
    return 0;
}
