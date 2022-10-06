#include <iostream>

using namespace std;

int main()
{
    int n , temp , ans=0 ;
    cin >> n ;
    for (int i=1 ; i<=n ; ++i)
    {
        cin >> temp ;
        ans += temp*i ;
    }
    cout << ans << '\n' ;
    return 0;
}
