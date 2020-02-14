#include <stdio.h>

int main()
{
    int i, j, n, isPrime; //isPrime is used as flag variable

    /* Reads upper limit to print prime */
    printf("Find prime numbers between 1 to : ");
    scanf("%d", &n);

    printf("\nAll prime numbers between 1 to %d are:\n", n);

    /* Finds all Prime numbers between 1 to n */
    for(i=2; i<=n; i++)
    {
        /* Assume that the current number is Prime */
        isPrime = 1;

        /* Check if the current number i is prime or not */
        for(j=2; j<=i/2; j++)
        {
            /*
             * If i is divisible by any number other than 1 and self
             * then it is not prime number
             */
            if(i%j==0)
            {
                isPrime = 0;
                break;
            }
        }

        /* If the number is prime then print */
        if(isPrime==1)
        {
            printf("%d is Prime number\n", i);
        }
    }

    return 0;
}
