#include<stdio.h>
#include<stdlib.h>
main()
{
    char *input=NULL;
    int i,n,temp,t;
    scanf("%d",&t);
    while(t--)
    {
        prev:
        temp=1;
        scanf("%d",&n);
        input = (char *) calloc(n,sizeof(char));
        //realloc(input, (sizeof(char)*n));
        if(input!=NULL)
        {
            for(i=0;i<=n;i++)
            {
                scanf("%c",input+i);
            }

            i=0;
            while(i<=n){
                if(input[i]=='H'){
                   while(input[i]!='T')
                   {
                       i++;
                       if(input[i]=='H')
                        {
                            temp=0;
                            goto level;
                        }
                        if(i>n)
                        {
                           temp=0;
                           goto level;
                        }
                   }
                }
                else if(input[i]=='T')
                {
                    temp=0;
                    goto level;
                }
                    i++;
            }
            level:
            if(temp!=0)
                printf("Valid\n");
            else
                printf("Invalid\n");
            }
            else
            {
                t++;
                goto prev;
            }
            free(input);
    }
}
