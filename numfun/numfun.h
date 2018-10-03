#ifndef NUMFUN_H
#define NUMFUN_H

// Perform arithmetic on two longs with the passed strategy.
long dynamic_long(long x, long y, long (*strategy)(long, long));
long sum_long(long x, long y);
long mult_long(long x, long y);

// Perform arithmetic on two doubles with the passed strategy.
double dynamic_double(double x, double y, double (*strategy)(double, double));
double sum_double(double x, double y);
double mult_double(double x, double y);

#endif
