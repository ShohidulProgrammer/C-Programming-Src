#include<stdio.h>
main()
{
    int f=0,r=0,n=6;
    int q[6];
    int item;
    while(1)
    {
        printf("enter a value:  ");
        scanf("%d",&item);
        r=(r+1)%6;

        if(r==f)
        {
            r=(r-1)%6;
            printf("the queue is full.\nand r=%d",r);
        }
        else
        q[r]=item;
        printf("the input value is: %d \nand the index number is: %d\n",item,r);

    }
}
