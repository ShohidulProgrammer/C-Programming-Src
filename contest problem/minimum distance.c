#include<stdio.h>
main()
{
    int c,t=1;
    float a,ans;
    scanf("%d",&c);
    while(t<=c)
    {
        scanf("%f",&a);
        ans = 2.0*sqrt(a/3.14159);
        printf("Case %d: %f\n",t,ans);
        t++;
    }
}
