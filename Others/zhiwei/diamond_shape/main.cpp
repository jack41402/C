#include <iostream>

using namespace std;

int main ()
{
    int n ;
    do
    {
        //輸入正整數 n
        cin >> n ;
        //當 n 是偶數時，提示使用者
        if (n%2==0) cout << "The integer variable n should be odd.\n" ;
    }
    //當 n 不介於 1~27 或是不是奇數的時候，重新輸入 n
    while (n<1 || n>27 || n%2==0) ;
    //控制 1~(n/2+1) 層
    for (int i=1 ; i<=n/2+1 ; ++i)
    {
        //輸出 (n/2)-i 個空白
        for (int j=i ; j<=n/2 ; ++j) cout << ' ' ;
        //輸出 2*i-1 個 *
        for (int j=1 ; j<=2*i-1 ; ++j) cout << '*' ;
        //輸出完換行
        cout << '\n' ;
    }
    //控制 (n/2+2)~n 層
    for (int i=n/2 ; i>=1 ; --i)
    {
        //輸出 (n/2)-i 個空白
        for (int j=i ; j<=n/2 ; ++j) cout << ' ' ;
        //輸出 2*i-1 個 *
        for (int j=1 ; j<=2*i-1 ; ++j) cout << '*' ;
        //輸出完換行
        cout << '\n' ;
    }
    return 0;
}
