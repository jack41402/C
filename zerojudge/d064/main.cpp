#include <iostream>

using namespace std;

int main()
{
    int n ;
    cin >> n ;
    (n&1) ? cout << "Odd\n" : cout << "Even\n" ;
    return 0;
}
