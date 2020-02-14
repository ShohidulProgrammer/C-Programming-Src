#include<stdio.h>

main()
{
    int n,t,half,i,j,coun=-1,temp=0,first,last;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        half=(n/2);
        int input[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&input[i]);
        }


        if(n%2==0)
        {
            first=input[0];
            last= input[n-1];
            if(first>=last)
            {
                coun = last;
            }
            else
            {
               coun = first;
            }


            //goto level;
        }
        else
        {
          while(temp==1){
                j=0;
            for(i=0;i<=half;i++)
            {
                j++;
                if(input[i]!=j)
                {
                    temp=0;
                    if(input[i]>j)
                    {
                        input[i]=input[i]+1;
                    }
                    else
                    {
                        input[i]=input[i]-1;

                    }

                }
                else
                    temp=1;
            }
            for( ;i<n;i++)
            {
                --j;
                if(input[i]!=j)
                {

                    temp = 0;
                    if(input[i]>j)
                    {
                        input[i]=input[i]+1;
                    }
                    else
                    {
                        input[i]=input[i]-1;

                    }
                }
                else
                    temp =1;

                    coun++;
                }

                 for(i=0;i<n;i++)
                    printf("%d",input[i]);
                 printf("\n");

            }


        }
         printf("\n%d\n",coun);
    }
}


