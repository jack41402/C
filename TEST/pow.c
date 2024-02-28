#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
//#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define swap(a, b) {typeof(a) temp=a; a=b; b=temp;}
#define debug(var) do { \
    _Generic((var), \
        int: printf("%s: %d\n", #var, var), \
        unsigned int: printf("%s: %u\n", #var, var), \
        long: printf("%s: %ld\n", #var, var), \
        unsigned long: printf("%s: %lu\n", #var, var), \
        long long int: printf("%s: %lld\n", #var, var), \
        unsigned long long int: printf("%s: %llu\n", #var, var), \
        float: printf("%s: %f\n", #var, var), \
        double: printf("%s: %lf\n", #var, var), \
        char: printf("%s: %c\n", #var, var), \
        char *: printf("%s: %s\n", #var, var), \
        default: printf("Unsupported type\n") \
    ); \
} while(0)
#define debug_array(arr) do { \
    int _size = sizeof(arr) / sizeof(arr[0]); \
    printf("%s: [", #arr); \
    for (int _i = 0; _i < _size; ++_i) { \
        _Generic((arr), \
            int*: printf("%d", arr[_i]), \
            unsigned int*: printf("%u", arr[_i]), \
            long*: printf("%ld", arr[_i]), \
            unsigned long*: printf("%lu", arr[_i]), \
            long long int*: printf("%lld", arr[_i]), \
            unsigned long long int*: printf("%llu", arr[_i]), \
            float*: printf("%f", arr[_i]), \
            double*: printf("%lf", arr[_i]), \
            char*: printf("%c", arr[_i]), \
            char**: printf("%s", arr[_i]), \
            default: printf("Unsupported type") \
        ); \
        if (_i != _size - 1) printf(", "); \
    } \
    printf("]\n"); \
} while(0)

int main()
{
    unsigned long long int base, power;
    unsigned long long int ans=1;
//    scanf("%llu%llu", &base, &power);
//    for (int i=0 ; i<=power ; ++i)
//    {
//        printf("%llu^%2d: %llu\n", base, i, ans);
//        ans *= base;
//    }


    int i;
    unsigned long long int residual, n, num, count;
    power=pow(2,63);
    char str[64];
    sscanf("FFFF", "%s", str);
    debug(str);
    sscanf(str, "%llx", &num);
    printf("Binary numeral: ");
    residual = num;
    count = 0;
    power = pow(2,63);
    while(count<64){
        printf("%u",residual/power);
        residual = residual%power;

        power = power/2;
        count++;
        if(count%8 == 0){
            printf(" ");
        }
    }

    printf("\nHexadecimal numeral: ");
    residual = num;
    count = 0;
    power = pow(16,15);
    while(count<16){
        if(residual/power==10){
            printf("A");
        }
        if(residual/power==11){
            printf("B");
        }
        if(residual/power==12){
            printf("C");
        }
        if(residual/power==13){
            printf("D");
        }
        if(residual/power==14){
            printf("E");
        }
        if(residual/power==15){
            printf("F");
        }
        printf("%u",residual/power);
        residual = residual%power;

        power = power/16;
        count++;
        if(count%4 == 0){
            printf(" ");
        }
    }
}