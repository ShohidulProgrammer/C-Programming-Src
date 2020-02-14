#include<stdio.h>
#include<stdlib.h>
main()
{
    int i,n,temp,t;
    scanf("%d",&t);
    while(t--)
    {
        temp=1;
        scanf("%d",&n);
        char input[n];
        for(i=0;i<=n;i++)
        {
            scanf("%c",&input[i]);
        }

        i=0;
        while(i<=n){
            if((input[i]=='H')||(input[i]=='h')){
                while((input[i]!='T')&&(input[i]!='t'))
                {
                    i++;
                    if((input[i]=='H')||(input[i]=='h'))
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
            else if((input[i]=='T')||(input[i]=='t'))
            {
                temp=0;
                goto level;
            }
                i++;
        }
        level:
        if(temp!=0)
            printf("\nValid\n");
        else
            printf("\nInvalid\n");
    }
}

