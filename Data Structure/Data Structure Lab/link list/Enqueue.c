#include<stdio.h>
main()
{
    int f=0,r=0,n=6;
    int q[n];
    int item;
    //r=r-1%n;
    //printf("r= %d",r);

    {
        printf("\nenter a value:  ");
        scanf("%d",&item);
        r=(r+1)%n;

        if(r==f)
        {
            r=(r-1)%n;
            printf("\nthe queue is full.");
            //printf("\n\nand r=%d",r);
        }
        else
        {
            q[r]=item;
            printf("\nthe input value is: %d \nand the index number is: %d",item,r);
        }

    }
}
