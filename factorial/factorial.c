#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

unsigned long factorial(int f)
{
    if (f <= 1)
    {
        return 1;
    }
    return f * factorial(f-1);
}

// 65! is the max that an unsigned long can accommodate.
const int max_input = 65;
long memos[max_input+1];

// factorial_memoed uses the memos array to avoid having to recompute
// factorials that have been previously calculated.
unsigned long factorial_memoed(int f)
{
    if (f <= max_input && memos[f] != 0)
    {
        return memos[f];
    }

    if (f <= 1)
    {
        return 1;
    }

    memos[f] = f * factorial_memoed(f-1);
    return memos[f];
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "%s: at least one numerical argument is required\n", argv[0]);
        return 1;
    }

    // Allow the user to set NOMEMO in the environment to force use of the
    // naive factorial function. We will invoke using a function pointer to
    // the desired implementation.
    unsigned long (*factorial_func)(int) = &factorial_memoed;
    char *no_memo = getenv("NOMEMO");
    if (no_memo != NULL)
    {
        factorial_func = &factorial;
    }

    int exit_code = 0;
    for (int i=1; i < argc; i++)
    {
        errno = 0;
        int f = atoi(argv[i]);
        if (errno)
        {
            fprintf(stderr, "%s: invalid numerical argument \"%s\"\n", argv[0], argv[i]);
            exit_code = 1;
            continue;
        }
        if (f < 0)
        {
            fprintf(stderr, "%s: numerical argument must be non-negative\n", argv[0]);
            exit_code = 1;
            continue;
        }
        if (f > max_input)
        {
            printf("Sorry, I can only compute up to %d!\n", max_input);
            continue;
        }
        printf("%d! = %lu\n", f, factorial_func(f));
    }

    return exit_code;
}

