#include<stdio.h>

int main()
{
    int i,j,k=1;
        for(i=1;i<=5;i++)
        {
            for(j=1;j<=k;j++)
            {
                printf("*");
            }
            k=k+2;
            printf("\n");
        }
        for(i=1;i<=5;i++)
        {
            k=k-2;
            for(j=1;j<=k;j++)
            {
                printf("*");
            }

            printf("\n");
        }
}
