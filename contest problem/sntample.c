#include<stdio.h>
main()
{
    int n,t,half,i,j,temp,first,last,max=0,min=9999999999;
    scanf("%d",&t);
    while(t--)
    {
        j=0;
        temp=0;
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
                if(last>1)
                last=last-1;
                printf("\n%d\n",last);
            }
            else
            {
                if(first>1)
                first= first -1;
                printf("\n%d\n",first);
            }


            //goto level;
        }
        else
        {
          for(i=0;i<=half;i++)
            {
                j++;
                if(input[i]!=j)
                {
                    if(input[i]>j)
                    {
                        if(input[i]>max)
                        {
                            max = input[i];
                            temp = j;
                        }

                    }
                    else
                    {
                        if(input[i]<min)
                        {
                            min = input[i];
                            temp = j;
                        }

                    }

                }
            }
            for( ;i<n;i++)
            {
                --j;
                if(input[i]!=j)
                {
                    if(input[i]>j)
                    {
                        if(input[i]>max)
                        {
                            max = input[i];
                            temp = j;
                        }

                    }
                    else
                    {
                        if(input[i]<min)
                        {
                            min = input[i];
                            temp = j;
                        }
                    }
                }
            }
            int countmin,countmax;
            countmax = max - temp;
            countmin = temp - min;

            if(countmin>countmax)
            {
                printf("\n%d\n",countmin);
            }
            else
            {
                printf("\n%d\n",countmax);
            }
        }
    }
}

