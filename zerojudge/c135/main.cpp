#include <iostream>

using namespace std;

bool number[10][5][3]=
        {
            {0 , 1 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 1 , 0} ,
            {0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0} ,
            {0 , 1 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 1 , 0} ,
            {0 , 1 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 1 , 0} ,
            {0 , 0 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0} ,
            {0 , 1 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 1 , 0} ,
            {0 , 1 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0} ,
            {0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0} ,
            {0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0} ,
            {0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 1 , 0}
        };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s ;
    string n ;
    while (cin>>s>>n)
    {
        if (s==0 && n=="0") break ;
        for (int i=0 ; i<5 ; ++i)
        {
            if (i%2==1)
            {
                for (int j=1 ; j<=s ; ++j)
                {
                    for (int k=0 ; k<n.size() ; ++k)
                    {
                        cout << ((number[n[k]-'0'][i][0]) ? '|' : ' ') ;
                        for (int l=1 ; l<=s ; ++l) cout << ' ' ;
                        cout << ((number[n[k]-'0'][i][2]) ? '|' : ' ') ;
                        cout << ' ' ;
                    }
                    cout << '\n' ;
                }
            }
            else
            {
                for (int j=0 ; j<n.size() ; ++j)
                {
                    cout << ' ' ;
                    for (int k=1 ; k<=s ; ++k)
                    {
                        cout << ((number[n[j]-'0'][i][1]) ? '-' : ' ') ;
                    }
                    cout << ' ' ;
                    cout << ' ' ;
                }
                cout << '\n' ;
            }
        }
    }
    return 0;
}
