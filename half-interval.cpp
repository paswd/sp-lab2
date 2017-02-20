#include "mlisp.h"
#include "half-interval.h"

extern double tolerance;
bool close__enough_Q(double x, double y);

double half__interval__method(double a, double b) {
{
	double a__value = 0;
	double b__value = 0;
	a__value = fun(a);
	b__value = fun(b);
	return ((a__value < 0) && (b__value > 0) ? __SPA__try(a, b)
		:	(a__value > 0) && (b__value < 0) ? __SPA__try(b, a)
		:	b + 1);
}
}

double __SPA__try(double neg__point, double pos__point) {
{
	double midpoint = 0;
	double test__value = 0;
	midpoint = average(neg__point, pos__point);
	display("+");
	return (close__enough_Q(neg__point, pos__point) ? midpoint
		:	true ? (
				test__value = fun(midpoint),
				(test__value > 0 ? __SPA__try(neg__point, midpoint)
					:	test__value < 0 ? __SPA__try(midpoint, pos__point)
					:	midpoint)
			)
		:	_infinity);

}
}

bool close__enough_Q(double x, double y) {
{
	return abs(x - y) < tolerance;
}
}

double average(double x, double y) {
	return (x + y) / 2.;
}

double root(double a, double b) {
	double temp = 0;
	temp = half__interval__method(a, b);
	newline();
	display("interval=\t[");
	display(a);
	display(" , ");
	display(b);
	display("]\n");
	display("discrepancy=\t");
	display(fun(temp));
	newline();
	display("root=\t\t");
	//display((if(=(- temp b 1)0)"[bad]" "[good]"));
	display((temp - b - 1) == 0 ? "[bad]" : "[good]");
	return temp;
}

double tolerance = 0.00001;

double fun(double z) {
	z = z - (34.0 / 35.0) - 1.0 / pi;
	return z + sin(z) + cos(z);
}

int main(void) {
	display(" SPA variant 34");
	display(root(0, 1));
	newline();

	return 0;
}
