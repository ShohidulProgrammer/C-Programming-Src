#include<stdio.h>
int fn( int n )
{
   if( n == 0 ) return 1;
    if( n == 1 ) return 1;
    //if( n == 2 ) return 3;
    //if( n == 3 ) return 4;
    //if( n == 4 ) return 5;
    //if( n == 5 ) return 6;
    return ( fn(n-1) + fn(n-2));
}
main()
{
    int n=9,sum;
    sum=fn(n);
    printf("sum: %d\n",sum);

}
