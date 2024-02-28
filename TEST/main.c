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
#define epsilon 0.000001 // Difference error.

// Declare globe variables.
double a, b, c, d; // Points A(a, 0), B(0, b), C(c,0), and D(0, d).
int T; // Number of the partitioned intervals.

// ***** Complete the implementation of functions in Step a and Step b.

// a. Define and implement four functions double f1(double x), double f2(double x),
//    double f3(double x), and double f4(double x) for lines AB, BC, CD, and DA.

double f1(double x) {
    return (-b/a)*x+b;
};

double f2(double x) {
    return (-b/c)*x+b;
};

double f3(double x) {
    return (-d/c)*x+d;
};

double f4(double x) {
    return (-d/a)*x+d;
};

// b. Define and implement function
//      double right_Riemann_sum(double r, double s, double (*f)(double), double (*g)(double))
//    to compute the area covered by two functional parameters f and g between interval (r, s)
//    along the X axis.

double right_Riemann_sum(double r, double s, double (*f)(double), double (*g)(double)) {
    double interval; // Size of the partitioned interval.
    double point; // The left-end point of each individual interval.
    double area; // Area of the covered region, left Riemann sum of the current iteration.
    double last; // Left Riemann sum of the previous iteration.
    int i; // Loop variable.

    T = 1;
    area = -1;
    last = -2;
    while(fabs(last - area)>epsilon){
        interval = fabs(s-r)/T;
        point = r + interval;
        last = area;
        area = 0;
        for(i=0;i<T;i++){
            area += fabs(f(point)) * interval;
            area += fabs(g(point)) * interval;
            point+=interval;
        }
        printf("Number of intervals: %d, interval size: %1.6lf, area: %2.6lf\n", T, interval, area);
        T = T*2;
    }
    printf("The number of intervals: %d\n\n", T/2);
    return area;
}

int main(void) {
    double areaBCD, areaBAD; // Area of triangle BCD and triangle BAD.
    double area; // Area of the quadrilateral.

    // c. Enter four real numbers (double type) a, b, c and d, where c<0<a and d<0<b, to
    //    represent points A(a, 0), B(0, b), C(c,0), and D(0, d).
    printf("Enter real number a for point A(a, 0), a>0: ");
    scanf("%lf", &a); // Input point A.
    printf("Enter real number b for point B(0, b), b>0: ");
    scanf("%lf", &b); // Input point B.
    printf("Enter real number c for point C(c, 0), c<0: ");
    scanf("%lf", &c); // Input point C.
    printf("Enter real number c for point D(0, d), d<0: ");
    scanf("%lf", &d); // Input point D.
    printf("\nPoints: A=(%6.4lf, 0), B=(0, %6.4lf), C=(%6.4lf, 0), D=(0, %6.4lf)\n\n", a, b, c, d);

    // ***** Complete the program of the following steps.
    printf("**** Compute the area of triangle BCD.\n");
    areaBCD = right_Riemann_sum(c, 0, f2, f3);
    // d. Compute the area of quadrilateral ABCD using right Riemann sum approach.

    // e. Print the area of triangle BCD, the area of triangle BAD, and the area of quadrilateral ABCD.
    printf("**** Compute the area of triangle BAD.\n");
    areaBAD = right_Riemann_sum(0, a, f1, f4);
    // f. Verify the result with the area formula 1/2|(a-c)(b-d)|.
    printf(">>>> Area of triangle BCD: %2.6lf\n", areaBCD);
    printf(">>>> Area of triangle BCD: %2.6lf\n", areaBAD);
    printf(">>>> Area of the quadrilateral ABCD: %2.6lf\n", areaBCD+areaBAD);
    area = fabs(0.5*((a-c)*(b-d)));
    printf(">>>> The result of 1/2|(a-c)(b-d)| is: %2.6lf\n", area);
    printf(">>>> The error is: %.6lf\n", area-(areaBCD+areaBAD));
    return 0;
}