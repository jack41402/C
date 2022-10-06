#include <iostream>

using namespace std;

int main()
{
    int n ;
    while(cin >> n)
    {
        int ans=0 ;
        while(n>=3)
        {
            int tmp=n/3 ;
            ans += tmp*3 ;
            n %= 3 ;
            n += tmp ;
        }
        if(n==2) n++ ;
        ans += n ;
        cout << ans << '\n' ;
    }
    return 0;
}