#include<stdio.h>
main()
{
    int length,t,half,i,j,temp;
    scanf("%d",&t);
    while(t--)
    {
        j=0;
        temp=1;
        scanf("%d",&length);
        half=(length/2);
        int input[length];
        for(i=0;i<length;i++)
        {
            scanf("%d",&input[i]);
        }
        if(length%2==0)
        {
            temp=0;
            goto level;
        }

        for(i=0;i<=half;i++)
            {
                j++;
                if(input[i]!=j)
                {
                    temp=0;
                    break;
                }
            }
            for( ;i<length;i++)
            {
                --j;
                if(input[i]!=j)
                {
                    temp=0;
                    break;
                }
            }
            level:
            if(temp!=0)
                printf("\nyes\n");
            else
                printf("\nno\n");

    }
}
