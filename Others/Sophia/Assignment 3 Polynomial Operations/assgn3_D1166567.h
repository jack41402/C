typedef int Degree; // Polynomial degree.
typedef float Coeff; // Polynomial coefficient. 

typedef struct node { // Define linked list node 
	int degree; // Degree of a polynomial term.
	float  coeff; // Coefficient of a polynimial term. 
	struct node* next; // Node link, defined recursively
} Node; // Node type 

typedef Node* Term; // Node link, pointer to a node.

// A polynomial is a pointer to an ordered single-link linear list.
// The linear list is stored in the decreasing order.
// The first node points to the highest degree term.
typedef Term Polynomial; 

// Initialize polynomial.
void initial(Polynomial *);

// Get number of terms of the polynomial. 
int getTerm(Polynomial); 

// Get a polynomial term with given degree.
// If no term with the specified degree, return -99.
float getCoeff(Polynomial, int);

// Search a polynomial term with a specified degree. 
// If successful, return the degree of the term; otherwise, return -1.
int searchTerm(Polynomial, int);  

// Replace a polynomial term of a specified degree with given coefficient.
// If coefficient is 0.0, the correspoinding term is removed. 
// If the term of specified degree does not exist, insert a new term.
// Return degree of the term.
int replaceTerm(Polynomial *, int, float);

// Clear the polynomial.
void clear(Polynomial *);

// Checks whether the polynomial is empty. Return 1, if empty; otherwise, return 0.
int is_empty(Polynomial); 

// Print the polynomial.
void printPoly(Polynomial);

double evalPolynomial(Polynomial, float);

