#include <iostream>

using namespace std;

int main()
{
    int n ;
    cin >> n ;
    if (n<=2500)
    {
        (n%25==0) ? cout << "1 " << n/25 << ' ' << "25\n" : cout << "1 " << n/25+1 << ' ' << n%25 << '\n' ;
    }
    else if (n<=7500)
    {
        n -= 2500 ;
        (n%25==0) ? cout << "2 " << n/50 << ' ' << "50\n" : cout << "2 " << n/50+1 << ' ' << n%50 << '\n' ;
    }
    else
    {
        n -= 7500 ;
        (n%25==0) ? cout << "3 " << n/25 << ' ' << "25\n" : cout << "3 " << n/25+1 << ' ' << n%25 << '\n' ;
    }
    return 0;
}
