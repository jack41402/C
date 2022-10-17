#include <iostream>

using namespace std;

int main()
{
    int n=1 ;
    while (n++)
    {
        if (1>n || 99<n) break ;
        int digit_1 , digit_2 ;
        //個位數
        digit_1 = n%10 ;
        //十位數
        digit_2 = n/10 ;
        //特別處理11~19的整數
        if (11<=n && n<=19)
        {
            switch (n)
            {
                case 11 :
                    cout << "eleven" ;
                    break ;
                case 12 :
                    cout << "twelve" ;
                    break ;
                case 13 :
                    cout << "thirteen" ;
                    break ;
                case 14 :
                    cout << "fourteen" ;
                    break ;
                case 15 :
                    cout << "fifteen" ;
                    break ;
                case 16 :
                    cout << "sixteen" ;
                    break ;
                case 17 :
                    cout << "seventeen" ;
                    break ;
                case 18 :
                    cout << "eighteen" ;
                    break ;
                case 19 :
                    cout << "nineteen" ;
                    break ;
            }
            cout << '\n' ;
            continue ;
        }
        //根據十位數的數字輸出對應的數字，沒有十位數就不輸出
        switch (digit_2)
        {
            case 1 :
                cout << "ten" ;
                break ;
            case 2 :
                cout << "twenty" ;
                 break ;
            case 3 :
                cout << "thirty" ;
                 break ;
            case 4 :
                cout << "forty" ;
                 break ;
            case 5 :
                cout << "fifty" ;
                 break ;
            case 6 :
                cout << "sixty" ;
                 break ;
            case 7 :
                cout << "seventy" ;
                 break ;
            case 8 :
                cout << "eighty" ;
                 break ;
            case 9 :
                cout << "ninety" ;
                 break ;
            default :
                break ;
        }
        //如果十位數與個位數皆不是零，輸出橫線'-'
        if (digit_2!=0 && digit_1!=0) cout << '-' ;
        //根據個位數的數字輸出對應的數字，沒有個位數就不輸出
        switch (digit_1)
        {
            case 1 :
                cout << "one" ;
                break ;
            case 2 :
                cout << "two" ;
                break ;
            case 3 :
                cout << "three" ;
                break ;
            case 4 :
                cout << "four" ;
                break ;
            case 5 :
                cout << "five" ;
                break ;
            case 6 :
                cout << "six" ;
                break ;
            case 7 :
                cout << "seven" ;
                break ;
            case 8 :
                cout << "eight" ;
                break ;
            case 9 :
                cout << "nine" ;
                break ;
            default :
                break ;
        }
        cout << '\n' ;
    }
    return 0;
}
