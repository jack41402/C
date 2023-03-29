#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define error 0.0001
#include "assgn3_D1166567.h"

// (P1+P2)(X)
Polynomial polyAdd(Polynomial P1, Polynomial P2){
	Polynomial P, P3, P4;
	initial(&P);	
	initial(&P3);	
	initial(&P4);
	P3 = P1;
	P4 = P2;
	float a = P3->degree;
	float b = P4->degree;
	int p, i; // i=loop variable
//	printf("\ndeg = %d\n", a);
	if (a<b) p=b;
	else p=a;  // p is the higher degree.

	for(i=p; i>=0; i--){
		a = 0.0;
		b = 0.0;
		if(searchTerm(P3, i)!=-1) a = getCoeff(P3, i);
		if(searchTerm(P4, i)!=-1) b = getCoeff(P4, i);
//		printf("\na= %f, b = %f", a, b);
		replaceTerm(&P, i, a+b);
	}	
	return P;
}

// (P1-P2)(X)
Polynomial polyMinus(Polynomial P1, Polynomial P2){
//	printf("\nInto polyminus\n");
	Polynomial P, P3, P4;
	initial(&P);	
	initial(&P3);	
	initial(&P4);
	P3 = P1;
	P4 = P2;
	float a = P3->degree;
	float b = P4->degree;
	int i; // i=loop variable

	for(i=100; i>=0; i--){
		a = 0.0;
		b = 0.0;
		if(searchTerm(P3, i)!=-1) a = getCoeff(P3, i);
		if(searchTerm(P4, i)!=-1) b = getCoeff(P4, i);
//		printf("\na= %f, b = %f", a, b);
		if (a-b != 0) replaceTerm(&P, i, a-b);
	}
	return P;
}

// (P1*P2)(X)
Polynomial polyTime(Polynomial P1, Polynomial P2){
	Polynomial P, P3, P4;
	initial(&P);	
	initial(&P3);	
	initial(&P4);
	P3 = P1;
	P4 = P2;
	int a = P3->degree;
	int b = P4->degree;
	int i, j; // loop variable
	float p, q;
	float coeff = 0.0;
	
	for (i=a; i>=0; i--){
		for (j=b; j>=0; j--){
			p = 0.0;
			q = 0.0;
			if(searchTerm(P3, i)!=-1) p = getCoeff(P3, i);
			if(searchTerm(P4, j)!=-1) q = getCoeff(P4, j);
			if(getCoeff(P, i+j)!=-99){
				coeff = getCoeff(P, i+j) + p*q;
			}
			else coeff = p*q;
			replaceTerm(&P, i+j, coeff);
		}
	}
	return P;
}


int main(){
    setbuf(stdout , NULL) ;
	Polynomial P1, P2, P3, P4, P5;
	initial(&P1);
	initial(&P2);
	initial(&P3);
	initial(&P4);
	initial(&P5);
	
	int deg1, deg2;
	float coeff1, coeff2;
	int i;
	float a;
	
	do{
		printf("Enter degree of the polynomial P1 (between 0 and 100): ");
		scanf("%d", &deg1);
	}while(deg1 < 0 || deg1 > 100);

	do{
		printf("Enter degree of the polynomial P2 (between 0 and 100): ");
		scanf("%d", &deg2);
	}while(deg2 < 0 || deg2 > 100);

	do{
		printf("Enter value of a (between -1.0 and 1.0): ");
		scanf("%f", &a);
	}while(a < -1.0 || a > 1.0);	
	
	srand(0);
	
	coeff1 =  (rand() % 2001 - 1000) / 100.0; // Generate coefficient of the first term.
	replaceTerm(&P1, deg1, coeff1); // Insert the first term.
	for (i=deg1-1; i>=0; i--){ // Generate the remainding term. 
		if (rand()%3==0){ // Only 0.33% of terms have non-zero coefficient.
			coeff1 =  (rand() % 2001 - 1000) / 100.0;
			replaceTerm(&P1, i, coeff1);
		}
	}
	
	coeff2 =  (rand() % 2001 - 1000) / 100.0; // Generate coefficient of the first term.
	replaceTerm(&P2, deg2, coeff2); // Insert the first term.гл 
	for (i=deg2-1; i>=0; i--) { // Generate the remainding term. 
		if (rand()%3==0) { // Only 0.33% of terms have non-zero coefficient.
			coeff2 =  (rand() % 2001 - 1000) / 100.0;
			replaceTerm(&P2, i, coeff2);
		}
	}
	
	printf("\n>>>>Polynomial P1(X) has %d non-zero coefficient terms.\n", getTerm(P1)); // Print number of terms.
	printPoly(P1); // Print polynomial.
	printf("\n>>>>Polynomial P2(X) has %d non-zero coefficient terms.\n", getTerm(P2)); // Print number of terms.
	printPoly(P2); // Print polynomial.	
	printf("\n>>>>a = %.4f", a);
	
	float ans1, ans2, ans3, ans4, ans5;
	ans1 = evalPolynomial(P1, a);
	ans2 = evalPolynomial(P2, a);
	printf("\n>>>>Evaluation of Polynomial P1(a) = %.4E", ans1);
	printf("\n>>>>Evaluation of Polynomial P2(a) = %.4E\n", ans2);
	
	P3 = polyAdd(P1, P2);
	printf("\n>>>>Polynomial (P1+P2)(X) has %d non-zero coefficient terms.\n", getTerm(P3)); // Print number of terms.
	printPoly(P3); // Print polynomial.
	
	P4 = polyMinus(P1, P2);
	printf("\n>>>>Polynomial (P1-P2)(X) has %d non-zero coefficient terms.\n", getTerm(P4)); // Print number of terms.
	printPoly(P4); // Print polynomial.
		
	P5 = polyTime(P1, P2);
	printf("\n>>>>Polynomial (P1*P2)(X) has %d non-zero coefficient terms.\n", getTerm(P5)); // Print number of terms.
	printPoly(P5); // Print polynomial.	
	
	ans3 = evalPolynomial(P3, a);
	ans4 = evalPolynomial(P4, a);
	ans5 = evalPolynomial(P5, a);

	printf("\n>>>>Evaluation of Polynomial (P1+P2)(X) = %.4E", ans3);
	printf("\n>>>>Evaluation of Polynomial (P1-P2)(X) = %.4E", ans4);
	printf("\n>>>>Evaluation of Polynomial (P1*P2)(X) = %.4E\n", ans5);
	
//	printf("\n%f, %f", ans1+ans2, ans3);
	if (fabs(ans1 + ans2 - ans3) < error) printf("\n>>>>Prove: P1(a) + P2(a) == (P1+P2)(a)");
	
//	printf("\n%f, %f", ans1-ans2, ans4);
	if (fabs(ans1 - ans2 - ans4) < error) printf("\n>>>>Prove: P1(a) - P2(a) == (P1-P2)(a)");
	
//	printf("\n%f, %f", ans1*ans2, ans5);
	if (fabs(ans1 * ans2 - ans5) < error) printf("\n>>>>Prove: P1(a) * P2(a) == (P1*P2)(a)");
	
	return 0;
}
