#include <iostream>
#include <cstring>

using namespace std;

int arr[3000] ;
bool dif[3000]={false} ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n ;
    while (cin>>n)
    {
        int temp ;
        bool flag=true ;
        memset(dif , 0 , n) ;
        cin >> arr[0] ;
        for (int i=1 ; i<n ; ++i)
        {
            cin >> arr[i] ;
            dif[abs(arr[i]-arr[i-1])] = true ;
        }
        for (int i=1 ; i<=n-1 ; ++i)
        {
            if (!dif[i])
            {
                flag = false ;
                break ;
            }
        }
        (flag) ? cout << "Jolly\n" : cout << "Not jolly\n" ;
    }
    return 0;
}