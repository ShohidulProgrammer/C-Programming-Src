#include<stdio.h>

// Lines in (Max) plane in C programming using CF method
// cf: Ln = {n(n+1)/2} + 1;

int cf(int n)
{
    return (n*(n+1)/2) + 1;
}

int main()
{
    int n; // Number of Lines
    while(1)
    {
        printf("\n\nEnter the Total Number of Lines: ");
        scanf(" %d",&n);

        printf("The Maximum Plane is: %d", cf(n));
    }

    return 0;
}
