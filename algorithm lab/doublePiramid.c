#include<stdio.h>
main()
{
    int i,j,k=0;
    for(i=1;i<=5;i++){
        for(j=5;j>i;j--)
            printf(" ");
        for(j=1;j<=(i+k);j++)
            printf("*");
        /*for(j=1;j<=i;j++)
            printf("*");
        for(j=2;j<=i;j++)
            printf("*");*/
            k++;
        printf("\n");
    }

}
