#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "assgn3_D1166567.h"

typedef Node* Polynomial; 

// Initialize polynomial.
void initial(Polynomial *P){
	*P = NULL;
}

// Get number of terms of the polynomial. 
int getTerm(Polynomial P){
	Polynomial term = P; // node pointer. 
	int count = 0; // The number of terms of the the polynomial is set to 0.
	
	while (term!=NULL){
		term = term->next; // Next term.
		count++; // Increment term counter.
	}
	return count;
}

// Get a polynomial term with given degree.
// If no term with the specified degree, return -99.
float getCoeff(Polynomial P, int deg){
	Polynomial current = P;
	while (current != NULL){
		if (current->degree == deg) return current->coeff;
		else if (current->degree > deg) current = current->next;
		else return -99.0;	
	}
	return -99.0;
}

// Search a polynomial term with a specified degree. 
// If successful, return the degree of the term; otherwise, return -1.
int searchTerm(Polynomial P, int deg){
	Polynomial current = P;
	while (current != NULL){
		if (current->degree == deg) return deg;
		else if (current->degree > deg) current = current->next;
		else return -1;	
	}
	return -1;
}

// Replace a polynomial term of a specified degree with given coefficient.
// If coefficient is 0.0, the correspoinding term is removed. 
// If the term of specified degree does not exist, insert a new term.
// Return degree of the term.

int replaceTerm(Polynomial *P, int deg, float coeff){
	Term current = *P; // Pointer to the current term.
	Term previous = NULL; // Pointer to the previous term, initially NULL. 
	Term newNode; // Pointer to the new term.
	
	if (*P==NULL) { // Case 1: The polynomial is empty.
		if (coeff!=0.0) { // Insert a new term.
			newNode = (Polynomial) malloc(sizeof(Node)); // Allocate memory for a new node.
			newNode->degree = deg; // Copy degree.
			newNode->coeff = coeff; // Copy coefficient.
			newNode->next = NULL; // Set next term to NULL.
			*P = newNode; // The polynomial points to the first term.
		}
		return deg; // Return the degree. 
	}
	
	do { // Check the current term.
		// Cases 2 & 3: Find the insertion position and insert a new node before this node.
		if (current->degree==deg) { // The specified degree exists.
			if (coeff!=0.0) { // Coefficient is not 0.0, replace it.
				current->coeff = coeff; // Replace the coefficient.
				return deg; // Return the degree.
			}
			else { // If coefficient is zero, remove the current term.
				if (previous!=NULL) {
					previous->next = current->next; // Skip the current term.
					free(current); // Release the current term.
					return deg; // Return the degree.
				}
				else { // The first term is removed.
					*P = current->next; // The second term becomes the first term.
					free(current); // Release the current term.
					return deg; // Return the degree.
				}
			}
		}
		else if (current->degree<deg) { // Insert befor the current term.
			if (coeff!=0.0) { // Insert a new term.
				newNode = (Polynomial) malloc(sizeof(Node)); // Allocate memory for a new term.
				newNode->degree = deg; // Copy degree.
				newNode->coeff = coeff; // Copy coefficient.
				newNode->next = current; // Set up the new node's link.
				if (previous==NULL) *P = newNode; // Case 2: Insert the first term of the polynomial.
				else previous->next = newNode; // Case3: Modify the link of the previous term. 
			}
			return deg; /// Return the degree. 
		}
		else {
			previous = current;// The current term becomes the previous term. 
			current = current->next; // Set the next as the current term for the next step. 
		}
	} while (current!=NULL); // If there are more terms in the polynomial, continue. 

	// Case 4: The while loop ends, no degree returned, 
	//         and add to the last term of the polynomial. 
	if (coeff!=0.0) {
		newNode = (Polynomial) malloc(sizeof(Node)); // Allocate memory for a new term.
		newNode->degree = deg; // Copy degree.
		newNode->coeff = coeff; // Copy coefficient.
		newNode->next = NULL; // The last term, set its next term to NULL.
		previous->next = newNode; // Put the new term at the end of the polynomial.
	}
	return deg; /// Return the degree. 
}


// Clear the polynomial.
void clear(Polynomial *P){
	Polynomial current;
	while (*P != NULL){
		current = *P;
		*P = current->next;
		free(current);
	}
}

// Checks whether the polynomial is empty. Return 1, if empty; otherwise, return 0.
int is_empty(Polynomial P){
	if (P==NULL) return 1;	
	else return 0;
}

// Print the polynomial.
void printPoly(Polynomial P){
	Polynomial current = P;
	
	while (current!=NULL){ // There are more terms to print.
		if (current!=P && current->coeff>0) printf("+");
		if (current->degree>1)
			printf("%5.3f X^%d", current->coeff, current->degree); // Print degree i term, i>1.
		else if (current->degree==1)
			printf("%5.3f X", current->coeff); // Print degree 1 term.
		else printf("%5.3f", current->coeff); // Print degree 0 term.
		current = current->next; // Move to the next node. 
	}
	printf("\n"); // Print a newline. 
}

double evalPolynomial(Polynomial P, float a){
	Polynomial term = P;
	float value = 0.0;
	
	while (term!=NULL) { // Evaluate polynomial while there is a term.
		value = value + term->coeff * pow(a, term->degree);
		term = term->next; // Continue to the next term.
	} 
	return value; // Return the resulting evaluation.
}
