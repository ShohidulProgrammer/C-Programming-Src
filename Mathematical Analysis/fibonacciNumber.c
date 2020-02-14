// Fibonacci Number Series in C programming
// Fib = 1,1,2,3,5,8,13,.....,
// fib = c = a + b, a = b, b = c;

#include<stdio.h>

int fibonacciSeries(int n)
{
    if(n>0)
    {
        // Fibonacci Number using Recursion
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else
        {
            return(fibonacciSeries(n - 1) + fibonacciSeries(n - 2));
        }
    }
    else
    {
        printf("\nFibonacci Series Can't be Negative.");
    }

    // Fibonacci Series
    /*
        int a=1,b=1,c,i;
        printf("The N'th Fibonacci Series Is: \n");
        printf("%d, %d",a,b);
        for(i=3; i<=n; i++)
        {
            c = a + b;
            a = b;
            b = c;
            printf(", %d",c);
        }
    */
}

int main()
{
    int n;
    char request = 'y';

    while(request == 'y' || request == 'Y')
    {
        // Take N'th value Input for Fibonacci Series
        printf("\nEnter the N'th value: ");
        scanf(" %d",&n);

        // function call for The N'th Fibonacci Series
        fibonacciSeries(n);

        // Request for Continue or Exit
        printf("\nPress\n[Y] for continue,[N] for exit: ");
        scanf(" %c",&request);
    }

    return 0;
}
