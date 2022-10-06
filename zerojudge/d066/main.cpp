#include <iostream>

using namespace std;

int main()
{
    int h , m ;
    cin >> h >> m ;
    if (450<=h*60+m && h*60+m<1020)
    {
        cout << "At School \n" ;
    }
    else cout << "Off School\n" ;
    return 0;
}
