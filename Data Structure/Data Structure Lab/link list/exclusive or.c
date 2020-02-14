#include<stdio.h>
main()
{
    int a,b,c;
    while(1)
    {
        printf("Enter two Number: ");
        scanf("%d %d",&a,&b);
        c=a^b;
        printf(" %d + %d = %d \n",a,b,c);

    }

}
