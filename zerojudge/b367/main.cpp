#include <iostream>

using namespace std;

int arr[11][11] , map[11][11] ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t , n , m ;
    cin >> t ;
    while (t--)
    {
        bool flag=true ;
        cin >> n >> m ;
        for (int i=0 ; i<n ; ++i)
        {
            for (int j=0 ; j<m ; ++j)
            {
                cin >> arr[i][j] ;
            }
        }
        for (int i=0 ; i<n ; ++i)
        {
            for (int j=0 ; j<m ; ++j)
            {
                map[i][j] = arr[n-1-i][m-1-j] ;
            }
        }
        for (int i=0 ; i<n && flag ; ++i)
        {
            for (int j=0 ; j<m ; ++j)
            {
                if (arr[i][j]!=map[i][j])
                {
                    flag = false ;
                    break ;
                }
            }
        }
        cout << ((flag) ? "go forward\n" : "keep defending\n") ;
    }
    return 0;
}
