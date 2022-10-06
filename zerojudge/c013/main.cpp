#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , a , f ;
    cin >> n ;
    while (n--)
    {
        cin >> a >> f ;
        for (int i=1 ; i<=f ; ++i)
        {
            for (int j=1 ; j<=a ; ++j)
            {
                for (int k=1 ; k<=j ; ++k)
                {
                    cout << j ;
                }
                cout << '\n' ;
            }
            for (int j=a-1 ; j>=1 ; --j)
            {
                for (int k=1 ; k<=j ; ++k)
                {
                    cout << j ;
                }
                cout << '\n' ;
            }
            cout << '\n' ;
        }
    }
    return 0;
}
