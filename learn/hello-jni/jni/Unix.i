%module Unix

%inline %{
#include "unix.c"
extern int    gcd(int x, int y);
extern double Foo;
%}

#include "unix.c"