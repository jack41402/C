#include <iostream>

using namespace std;

int main()
{
    int a , ans=0 ;
    cin >> a ;
    while (a>0)
    {
        ans = ans*10 + a%10 ;
        a /= 10 ;
    }
    cout << ans << '\n' ;
    return 0;
}
