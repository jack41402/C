#include <iostream>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , maxx=-1 , minn=1e4 , temp , count ;
    cin >> n ;
    count = n ;
    while (count--)
    {
        cin >> temp ;
        maxx = max (maxx , temp) ;
        minn = min (minn , temp) ;
    }
    cout << minn << ' ' << maxx ;
    (maxx-minn+1==n) ? cout << " yes\n" : cout << " no\n" ;
    return 0;
}
