#include<stdio.h>
main()
{
    int length,t,half,i,j,temp;
    scanf("%d",&t);
   // while(t--)
    //{
        j=0;
        temp=1;
        scanf("%d",&length);

        half=(length/2);
            int input[length];
            for(i=0;i<length;i++)
            {
                scanf("%d",&input[i]);
            }

            for(i=0;i<=half;i++)
                {
                    j++;
                    if(input[i]!=j)
                    {
                        temp=0;
                        printf("\nNo1\n");
                        break;
                    }
                }
                j=1;
                for( i=(length-1);i>half;i--)
                {
                    j++;
                    if(input[i]!=j)
                    {
                        temp=0;
                        printf("\nNo2\n");
                        break;
                    }
                }


            if(temp!=0)
                printf("\nYes\n");
            else
                printf("\nNo\n");

   // }
}
