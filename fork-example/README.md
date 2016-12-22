# fork-example

I haven't written a line of C in a long time, and I got to thinking
about fork-bombs as a side effect of a conversation. It made me want
to write a C program again.

I tried to remember how `fork()` worked. I sort of did. I remembered,
correctly, that the child process would return a 0 from its fork.
I did have to look up the proper header to include for `fork()`.

What resulted was this demonstration, and the personality I'd sort of
given it made me want to save it rather than throw it away, so here
we are.

### Notes

This runs on OS X 10.11 El Capitan. It has not been tested on anything
else.
