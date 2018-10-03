#ifndef MAIN_H
#define MAIN_H

typedef enum num_type
{
	INVALID  = 0,
	LONG     = 1,
	DOUBLE   = 2
} num_type_t;

typedef union num_holder
{
	long   l;
	double d;
} num_holder_t;

static const char* const mem_err = "error: unable to allocate memory";
static const char *argv0;

int usage(void);
int error(char const *);
num_type_t parse_arg(char* arg, num_holder_t *nh);

#endif
