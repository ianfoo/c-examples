# numfun

Okay, maybe **numfun** is a bit ambitious as a name. Most of the fun was had in
developing this toy, and less is in using it.

## Motivation

I saw something on a web page that involving a C function that took a function
pointer as a parameter and it made me want to call something using a function
passed as a function pointer. Then I added a couple things incrementally.

I used a combination of memory and man(3) pages, mostly, a touch of Stack
Overflow to jog the memory, and a couple lookups in
[Dash](https://kapeli.com/dash).

## Concepts

This C program illustrates usages of the following concepts:

* using functionality from other user-defined compilation units (`numfun.*`)
* function pointers
* dynamic memory allocation
* parsing numbers from strings
* type declaration
* enums and unions

## Notes

Developed on macOS High Sierra 10.13.6 with the following
**[clang](https://clang.llvm.org)**:

```
$ clang --version
Apple LLVM version 10.0.0 (clang-1000.10.44.2)
Target: x86_64-apple-darwin17.7.0
```

## Caveats

**[splint](https://www.splint.org)** reports a parse error upon encountering
the first usage of `num_holder_t` in `main.c`, but as far as I know, I've used
`typedef` correctly. macOS' `clang` does not complain with all warnings enabled
(`-Weverything`).  I'm sure splint isn't *wrong*, but I'm not sure how to make
it happy, even after a couple searches, and I've spent enough time on this
example. If you see this and know why it's complaining, [tweet at me or DM
me](https://twitter.com/ianfoo).

## Thoughts

Writing something silly that barely does anything in C is fun for its own sake,
but requires working at a low level of abstraction, and still yields clumsy
code (as illustrated here) without an undue amount of consideration, and
reminds me why when I want to actually get something done for real, I'll use
[Go](https://golang.org).

