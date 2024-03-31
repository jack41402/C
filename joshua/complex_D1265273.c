#include <stdio.h>
#include <math.h>
#include "complex_D1265273.h"

complex add (complex x, complex y)
{
	complex sum;
	sum.re= x.re + y.re;
	sum.im= x.im + y.im;
	return sum;
}
complex minus(complex x, complex y)
{
	complex diff;
	diff.re= x.re + y.re;
	diff.im= x.im - y.im;
	return diff;
}
complex multi(complex x, complex y)
{
	complex prod;
	prod.re= (x.re * y.re) - (x.im * y.im);
	prod.im= (x.re * y.im )+ (x.im * y.re);
	return prod;
}
complex divide(complex x, complex y)
{
	complex quot;
	quot.re= (x.re * y.re + x.im * y.im) / ((y.re)*(y.re)+(y.im)*(y.im));
	quot.im= (((-1)*(x.re)* y.im)+ y.im * y.re) / ((y.re)*(y.re)+(y.im)*(y.im));
	return quot;
}
float abso(complex x)
{
	float s;
	s= sqrt((x.re)*(x.re)+(x.im)*(x.im));
	return s;	
}
complex r2c(float n)
{
	complex c;
	c.re= n;
	c.im= 0;
	return c;
}
void printComplex(complex c)
{
	if (c.re< 0)
	{
		if (c.im<0)
		{
			printf("%1.4f%1.4fi",	c.re, c.im);
		}
		else if (c.im>0)
		{
			printf("%1.4f+%1.4fi", c.re, c.im);
		}
		else
		{
			printf("%1.4f", c.re);
		}
	}
	else if(c.re==0)
	{
		if (c.im>0)
		{
			printf("%1.4fi", c.im);
		}
		else
		{
			printf("%1.4fi", c.im);
		}
	}
	else
	{
		if (c.im>0)
		{
			printf("%1.4f+%1.4fi", c.re, c.im);
		}
		else if(c.im<0)
		{
			printf("%1.4f%1.4fi", c.re, c.im);
		}
		else
		{
			printf("%1.4f+%1.4fi", c.re, c.im);
		}
	}	
}

