
#include<stdio.h>

main()
{
    int n,t,half,i,j,coun=-1,temp=0,first,last,min=9999999999;
    scanf("%d",&t);

    while(t--)
    {
        j=0;
        scanf("%d",&n);

        // value input
        int input[n+1];
        input[n]= 9999999999;
        for(i=0;i<n;i++)
        {
            scanf("%d",&input[i]);
        }

        // find minimum
        for(i=0;i<n;i++)
        {
            if(input[i]<=min)
            {
                min= input[i];
                temp=i;
            }
        }

        //find next minimum
        if(input[temp-1]>input[temp+1])
        {
            for(i=input[temp+1];i<n;i++)
            {
                if(max<input[i])
                {
                    max = input[i];
                }
            }
        }
        else
        {
            for(i=input[temp-1];i>=0;i--)
            {
                if(max<input[i])
                {
                    max = input[i];
                }
            }
        }




        half=(n/2);
        for(i=0;i<=half;i++)
        {
            arr[i]=++j;
        }
        for( ;i<n;i++)
        {
            arr[i]=--j;
        }



        for(i=0;i<n;i++)
        {
            if(input[i]<arr[i])
            {
                temp=arr[i]-input[i];
            }
            else if(input[i]>arr[i])
            {
                temp= input[i]-arr[i];
            }
            if(count<temp)
            {
                count= temp;
            }
        }

        if(n%2==0)
        {
            first=input[0];
            last= input[n-1];
            if(first<=last)
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

            printf("\n%d\n",coun);
        }
    }
}


