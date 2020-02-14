#include<stdio.h>

int a, b, c, d, e, f;
int fn( int n )
{
   if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return ( fn(n-1) + fn(n-2));
}

int main()
{
    int n, caseno = 0, cases;
   // scanf("%d", &cases);
   scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
    printf("%d\n", fn(n));
    return 0;
}
