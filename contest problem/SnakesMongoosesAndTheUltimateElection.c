#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,snake_count=0,mongoose=0,l,snake[105];
        char str[105];
        scanf("%s",str);
        l=strlen(str);
        for(i=0;i<l;i++)
          {
               if(str[i]=='s')
                snake[i]=1;
               else
                snake[i]=2;
          }
        for(i=0;i<l;i++)
        {
          //  printf("i=%d,snake=%d,mon=%d\n",i,snake_count,mongoose);
            if(str[i]=='s')
                snake_count++;
            else
            {
                mongoose++;
                if(str[i-1]=='s'&&(i-1)>=0 && snake[i-1]==1)
                {
                    snake_count--;
                    snake[i-1]--;
                }
                else if(str[i+1]=='s'&&(i+1)<l && snake[i+1]==1)
                {
                    snake[i+1]--;
                    i++;
                }
            }
        }
        //printf("\nsnake=%d,mon=%d\n",snake_count,mongoose);
        if(snake_count==mongoose)
            printf("tie\n");
        else if(snake_count>mongoose)
            printf("snakes\n");
        else
            printf("mongooses\n");
    }
    return 0;
}
