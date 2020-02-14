#include<stdio.h>
#include<string.h>
int main()
{
     char f[15], s[15];
     int word, b, i, temp = 0,t, cas = 1;
     scanf("%d",&t);
     while(t--)
     {
        temp = 0;
        scanf("%s %s", f, s);
        word= strlen(f);
        for(i = 0; i < word; i++)
          {
           if(f[i] != s[i])
            temp++;
          }
        if(temp == 0)
            printf("Case %d: Great, No Mistakes.\n", cas);
        else
           printf("Case %d: Ohh No, %d Mistakes.\n", cas, temp);
        cas++;
     }
    return 0;
}
