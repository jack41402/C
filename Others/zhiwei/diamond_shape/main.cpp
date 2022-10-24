#include <iostream>

using namespace std;

int main ()
{
    int n ;
    do
    {
        cin >> n ;
        if (n%2==0) cout << "The integer variable n should be odd.\n" ;
    }
    while (n<1 || n>27 || n%2==0) ;
    for (int i=1 ; i<=n/2+1 ; ++i)
    {
        for (int j=i ; j<=n/2 ; ++j) cout << ' ' ;
        for (int j=1 ; j<=2*i-1 ; ++j) cout << '*' ;
        cout << '\n' ;
    }
    for (int i=n/2 ; i>=1 ; --i)
    {
        for (int j=i ; j<=n/2 ; ++j) cout << ' ' ;
        for (int j=1 ; j<=2*i-1 ; ++j) cout << '*' ;
        cout << '\n' ;
    }
    return 0;
}
