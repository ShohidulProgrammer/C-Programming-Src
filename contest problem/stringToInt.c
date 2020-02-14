#include <stdio.h>
#include <stdlib.h>
main()

{
    int t,cas=0,s;
    char n[100],m[100];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",n);
        scanf("%s",m);
        s = atoi(n)+atoi(m);
        cas++;
        printf("Case %d: %d\n",cas,s);
    }

}
