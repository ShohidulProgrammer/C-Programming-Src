// Harmonic Number in C Programming
// Hn= 1/1 + 1/2 + 1/3 + 1/4 + ...... + 1/n = n_Summation_k=1 (1/k)

#include<stdio.h>

double harmonicNumber(double n)
{
    if(n > 1)
    {
        return (1/n)+harmonicNumber(n-1);
    }
    else
    {
        return 1;
    }

}

int main()
{
    double n;
    char request = 'y';

    while(request == 'y' || request == 'Y')
    {
        printf("\n\nEnter the value of N: ");
        scanf(" %lf",&n);

        printf("The Harmonic Number Is: %.5lf",harmonicNumber(n));

        printf("\nPress\n[Y] for continue,[N] for exit: ");
        scanf(" %c",&request);
    }

    return 0;
}
