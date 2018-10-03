#include "numfun.h"

// Perform arithmetic on two longs with the passed strategy.
long dynamic_long(long x, long y, long (*strategy)(long, long))
{
	return strategy(x, y);
}

long sum_long(long x, long y)
{
	return x+y;
}

long mult_long(long x, long y)
{
	return x*y;
}

// Perform arithmetic on two doubles with the passed strategy.
double dynamic_double(double x, double y, double (*strategy)(double, double))
{
	return strategy(x, y);
}

double sum_double(double x, double y)
{
	return x+y;
}

double mult_double(double x, double y)
{
	return x*y;
}
