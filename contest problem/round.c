#include<stdio.h>
main()
{
    int r,t=1,c,m;
    scanf("%d",&c);

    while(t<=c && t<=20)
    {
        t++;
        scanf("%d",&m);
        r=5-m+1;
        if(m<=5)
        {
            printf("%d\n",r);
        }
        else
            printf("Yes\n");
    }
}
