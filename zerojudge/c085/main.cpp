#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int z , i , m , l , count=1 ;
    while (cin>>z>>i>>m>>l)
    {
        if (z==0 && i==0 && m==0 && l==0) break ;
        long long int length=1 , seed=l , arr[10000]={0} ;
        while (true)
        {
            arr[l] = length ;
            l = (z*l+i)%m ;
            length++ ;
            if (arr[l]!=0) break;
        }
        cout << "Case " << count << ": " << length-arr[l] << '\n' ;
        count++ ;
    }
    return 0;
}
