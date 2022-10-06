#include <iostream>

using namespace std;

int arr[13] ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int temp , cases=1 ;
    while(true)
    {
        bool flag=true ;
        // arr[0]=s
        for (int i = 0; i < 13; ++i)
        {
            if (arr[0]==-1)
            {
                flag = false ;
                break ;
            }
            cin >> arr[i];
        }
        if (!flag) break ;
        cout << "Case " << cases << ":\n" ;
        for (int i = 1; i < 13; ++i)
        {
            cin >> temp;
            if (temp <= arr[i - 1])
            {
                arr[i - 1] -= temp;
                arr[i] += arr[i - 1];
                cout << "No problem! :D\n";
            }
            else
            {
                arr[i] += arr[i - 1];
                cout << "No problem. :(\n";
            }
        }
        cases++ ;
    }
    return 0;
}
