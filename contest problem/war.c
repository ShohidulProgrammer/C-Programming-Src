#include<stdio.h>
int main()
{
     int bs, es, t, T, i, add = 0, sum = 0, count = 0;
     scanf("%d", &t);

     while(t--)
     {
      scanf("%d", &T);
      count++;
      while(T--)
      {
       scanf("%d", &bs);
       add += bs;
       scanf("%d", &es);
       sum += es;
      }

      if(add >= sum)
       printf("Case %d: Yes\n", count);
      else
       printf("Case %d: No\n", count);
      add = 0;
      sum = 0;
     }

     return 0;
}
