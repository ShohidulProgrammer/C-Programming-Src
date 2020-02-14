#include<stdio.h>
int main()
{
    int t,s,m,i,ln;

    scanf("%d",&t);
    while(t--)
    {
        s=0;
        m=0;
        char ch[100];
        scanf("%s",ch);
        ln=strlen(ch);
        int arr[ln];
        for(i=0;i<ln;i++)
        {

            arr[i]=0;
            if(ch[i]== 's' ||ch[i]== 'S')
            {
                arr[i]=1;
            }
            else if(ch[i]=='m' || ch[i]=='M')
            {
                m++;
                if((ch[i-1]=='s'|| ch[i-1]=='S') &&(arr[i-1]==1))
                {
                    arr[i-1]=0;
                }

                else if(ch[i+1] == 's'||ch[i+1] == 'S')
                {
                    arr[i+1]= 0;
                    i++;
                }
            }
        }

        for(i=0;i<ln;i++)
        {
            s=s+arr[i];
        }

        if(s==m)
        {
            printf("tie\n");
        }
        else if(m>s)
            printf("mongooses\n");
        else
            printf("snakes\n");

        printf("M:%d\tS:%d\n",m,s);

    }
    return 0;
}
