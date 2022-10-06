#include <iostream>

using namespace std;

int arr[100][100] ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m ;
    while (cin>>n>>m)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> arr[i][j];
            }
        }
        for (int j = 0; j < m; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
