#include <iostream>
#include <cstring>

using namespace std;

int b[100] ;
bool sum[20001] ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , count=1 ;
    while (cin>>n)
    {
        bool flag=false ;
        memset(sum , false , 20001) ;
        for (int i=0 ; i<n ; ++i)
        {
            cin >> b[i] ;
        }
        for (int i=0 ; i<n && !flag; ++i)
        {
            for (int j=i ; j<n ; ++j)
            {
                if (sum[b[i]+b[j]])
                {
                    flag = true ;
                    break ;
                }
                sum[b[i]+b[j]] = true ;
            }
        }
        cout << "Case #" << count << ": It is " << ((!flag) ? "a B2-Sequence.\n" : "not a B2-Sequence.\n") ;
        count++ ;
    }
    return 0;
}
