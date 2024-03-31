typedef struct{
	float re;
	float im;
}complex;

complex add (complex, complex);

complex minus (complex, complex);

complex multi (complex, complex);

complex divide (complex, complex);

float abso (complex);

complex r2c (float);

void printComplex(complex);
