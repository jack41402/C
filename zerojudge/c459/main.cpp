#include <iostream>

using namespace std;

long long int exp (int a , int b)
{
    int ans=1 ;
    for (int cur=a , t=b ; t>0 ; t/=2 , cur*=cur)
    {
        if (t&1) ans *= cur ;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    long long int b , n , num=0 , multiple=1 , count=0 , sum=0 ;
    cin >> b >> n ;
    long long int temp=n ;
    while (temp)
    {
        num += (temp%10)*multiple ;
        multiple *= b ;
        temp /= 10 ;
        count++ ;
    }
    temp = n ;
    for (int i=1 ; i<=count ; ++i)
    {
        sum += exp (temp%10 , count) ;
        temp /= 10 ;
    }
    (num==sum) ? cout << "YES\n" : cout << "NO\n" ;
    return 0;
}
