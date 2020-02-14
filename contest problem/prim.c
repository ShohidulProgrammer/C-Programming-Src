#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000000
int cas=0;

void prime(int n)
{
    int i,j,temp,count=0;
    cas++;

    for(i=2;i<=MAX;i++)
    {
        temp=0;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                temp=1;
                break;
            }
        }
        if(temp==0)
        {
            count++;
        }
        if(count==n)
        {

            if(i%2== 0)
            {
                printf("Case %d: EVEN\n",cas);
            }
            else
                printf("Case %d: ODD\n",cas);
            break;
        }
    }
}

int main()
{
    int n,t;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        prime(n);

    }

   return 0;
}
