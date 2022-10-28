#include<iostream.h>
#include<conio.h>

struct operation
{
	int real;
	int imag;
};

struct operation add(struct operation a, struct operation b)
{
	struct operation d;
	d.real=a.real+b.real;
	d.imag=a.imag+b.imag;
	return d;
}
struct operation sub(struct operation a, struct operation b)
{
	struct operation d;
	d.real=a.real-b.real;
	d.imag=a.imag-b.imag;
	return d;
}
struct operation multiply(struct operation a, struct operation b)
{
	struct operation d;
	d.real=(a.real*b.real)-(a.imag*b.imag);
	d.imag=(a.real*b.imag)+(a.imag*b.real);
	return d;
}

int main()
{
clrscr();
	struct operation d1={24,67};
	struct operation d2={14,76};

	struct operation x= add(d1,d2);
	struct operation y= sub(d1,d2);
	struct operation z= multiply(d1,d2);

	cout<<"ADD- "<<x.real<<"+"<<x.imag<<"i\n";
	cout<<"SUB- "<<y.real<<"-"<<y.imag<<"i\n";
	cout<<"Multiply- "<<z.real<<"*"<<z.imag<<"i\n";

return 0;
}

