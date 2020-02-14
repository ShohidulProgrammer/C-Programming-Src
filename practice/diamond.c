#include<stdio.h>

main()
{
    int i,j,k=1;

    for(i=1;i<=5;i++)
    {
        for(j=1;j<=k;j++)
            printf("*");
    }
    k=k+2;
    printf("\n");
    for(i=6;i<=9;i++)
    {
        for(j=6;j<=k;j++)
            printf("*");
    }
    k=k+2;
    printf("\n");
}
