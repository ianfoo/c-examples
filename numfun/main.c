#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>

#include "numfun.h"
#include "main.h"

int main(int argc, char* argv[])
{
	argv0 = basename(argv[0]);
	if (argc != 3)
	{
		return usage();
	}

	num_holder_t *x = malloc(sizeof *x);
	if (!x)
	{
		return error(mem_err);
	}
	num_holder_t *y = malloc(sizeof *y);
	if (!y)
	{
		free(x);
		return error(mem_err);
	}

	num_type_t x_t = parse_arg(argv[1], x);
	if (x_t == INVALID)
	{
		if (errno != 0)
		{
			perror(argv0);
		}
		return usage();
	}

	num_type_t y_t = parse_arg(argv[2], y);
	if (y_t == INVALID)
	{
		if (errno != 0)
		{
			perror(NULL);
		}
		return usage();
	}

	if (x_t != y_t)
	{
		// Both numbers are valid, but haven't been interpreted in the same way,
		// so coerce to double since they're different types.
		if (x_t == LONG)
		{
			x->d = (double)x->l;
		}
		if (y_t == LONG)
		{
			y->d = (double)y->l;
		}

		// x_t is used to detect type in the following switch, so force to double.
		x_t = DOUBLE;
	}

	switch (x_t) {
		case LONG:
			{
				printf("%s: detected long numbers: x: %ld y: %ld\n", argv0, x->l, y->l);
				long sum  = dynamic_long(x->l, y->l, sum_long);
				long prod = dynamic_long(x->l, y->l, mult_long);
				printf("sum:     %4ld\n", sum);
				printf("product: %4ld\n", prod);
			}
			break;
		case DOUBLE:
			{
				printf("%s: detected floating point numbers: x: %.3lf y: %.3lf\n", argv0, x->d, y->d);
				double sum  = dynamic_double(x->d, y->d, sum_double);
				double prod = dynamic_double(x->d, y->d, mult_double);
				printf("sum:     %8.3lf\n", sum);
				printf("product: %8.3lf\n", prod);
			}
			break;
		case INVALID:
			return usage();
	}

	// Clean up.
	free(x);
	free(y);
}

num_type_t parse_arg(char* arg, num_holder_t *nh)
{
	char *end;
	{
		long l = strtol(arg, &end, 10);
		if (errno == 0 && *end == '\0')
		{
			nh->l = l;
			return LONG;
		}
	}
	{
		double d = strtod(arg, &end);
		if (errno == 0 && *end == '\0')
		{
			nh->d = d;
			return DOUBLE;
		}
	}
	return INVALID;
}

int usage()
{
	fprintf(stderr, "usage: %s <number> <number>\n", argv0);
	return 1;
}

int error(char const *msg)
{
	fprintf(stderr, "%s: %s\n", argv0, msg);
	return 1;
}

