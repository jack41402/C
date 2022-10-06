#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr(3) ;
    cin >> arr[0] >> arr[1] >> arr[2] ;
    int max=*max_element(arr.begin() , arr.end()) ;
    cout << max << '\n' ;
    return 0;
}
