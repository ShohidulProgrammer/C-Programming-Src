#include<stdio.h>
int main()
{
    int n,b,h,c,row,col,sum,t;
    scanf("%d",&t);
    while(t--)
    {
        b=0;h=0;c=0;sum=0;
        scanf("%d",&n);
        char ch[2][n];
       long int arr[n];
        arr[0]=1;

        for(row=0;row<2;row++)
        {
            scanf("%s",ch[row]);
        }


        for(row=0;row<2;row++)
        {
            for(col=0;col<n;col++)
            {
                if(ch[row][col]=='*')
                    b=1; c=1;
                if((ch[row][col+1]=='*' && b==1 )&&(arr[col]!=1))
                {
                    b=0;
                    arr[col]=1;
                    //printf("arr[%d]:%d\n",col,arr[col]);
                    sum++;
                }
                if((ch[!row][col+1]=='*' && c==1 )&&(arr[col]!=1))
                {
                    c=0;
                    arr[col]=1;
                    sum++;
                }
                if(ch[!row][col]=='*' && h!=1)
                {
                    h=1;
                }

                }
            }
            printf("%d\n",sum+h);
        }
        return 0;

}
