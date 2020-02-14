#include<stdio.h>
main()
{
    int t=1,c,n,d;
    float x,y;
    scanf("%d",&c);
    while(t<=c)
    {
        scanf("%d %d",&n,&d);
        x= (float)(n+d)/2;
        y=n-x;
        printf("Case %d: %.2f %.2f\n",t,x,y);
        t++;
    }

}
