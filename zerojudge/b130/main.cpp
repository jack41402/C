#include <iostream>
#include <set>

using namespace std;

int arr[100] ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ;
    while (cin>>n)
    {
        for (int i=0 ; i<n ; ++i)
        {
            cin >> arr[i] ;
        }
        set<int> s(arr , arr+n) ;
        cout << s.size() << '\n' ;
        for (auto &i : s) cout << i << ' ' ;
        cout << '\n' ;
    }
    return 0;
}
