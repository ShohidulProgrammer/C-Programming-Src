#include <stdio.h>
#include <stdlib.h>
int main()

{
    int T,cas=0,S;
    char N[100],M[100];

    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",N);
        scanf("%s",M);
        S = atoi(N)+atoi(M);
        cas++;
        printf("Case %d:%d\n",cas,S);
    }
    return 0;
}
