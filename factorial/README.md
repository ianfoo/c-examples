# factorial

I felt like writing a C program for some reason, something more than Hello
World, but not anything that took any substantial sort of effort. I wanted to
see if I could write a C program from memory. Factorial fit the bill. It is
unnecessarily complicated, offering two factorial implementations, especially
since `time` reveals absolutely no difference in running time on my Skylake
Core i7 960 machine. But I wanted to invoke something via a function pointer,
so there you have it.

I did write just about everything from memory--I even guessed correctly that
`atoi` was defined in `stdlib.h`. I wasn't really expecting to be right. I did
consult documentation on atoi (how does it indicate an error--I'm missing Go's
multiple return values here), and how to pull an environment variable.

## usage

I'm not sure why I'm even including this section, since no one is going to use
this, but, for completeness' sake and for the sake of my own enjoyment of talking
to myself:

* invoke factorial with any number of non-negative integers as arguments
* 66 factorial exceeds ULONG_MAX, so the program will complain if you enter a
  value greater than 65
* Set NOMEMO in the environment to force a non-memoized factorial implementation
