#include <iostream>

using namespace std;

int main()
{
    int n , temp , a[3]={0} ;
    cin >> n ;
    for (int i=n ; i>0 ; --i)
    {
        cin >> temp ;
        if (temp%3==0) a[0]++ ;
        else if (temp%3==1) a[1]++ ;
        else if (temp%3==2) a[2]++ ;
    }
    cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n' ;
    return 0;
}
