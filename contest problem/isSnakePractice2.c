#include<stdio.h>
main()
{
    int n,i,j,temp,row,col,t,*p;
    scanf("%d",&t);
    while(t--)
    {
        fflush(stdin);
        fflush(stdout);

        scanf("%d",&n);
        char ch[2][n];

    // input char
    for(i=0;i<2;i++)
    {
        scanf("%s",ch[i]);
        //input[0][i]=0;

    }

        temp=0;
        row=0;
        col=0;
        j=0;

    //output char1
    for(row=0,i=0;i<2;i++,row++)
    {
        while(j<n)
        {
           printf("\n[%d][%d]->%c",row,j,ch[row][j]);

            if(ch[row][j]!='#')
            {

                if((ch[!row][j]=='#')&&(i==0))
                {
                    j= j-1;
                    row=!row;
                   // goto level;
                }
                else if((ch[!row][j-1]=='#')&&(i==1))
                else
                    break;
            }
            else
            {
                ch[row][j]='1';
                printf("[%d][%d]->%c",row,j,ch[row][j]);
            }


        }
    }
      for(i=0;i<2;i++)
      {
          for(j=0;j<n;j++)
          {
              if(ch[i][j]=='#')
                {
                    temp++;
                }
          }
      }
      if(temp)
        printf("\nno\n");
      else
        printf("\nyes\n");

        p=&ch;
        p=NULL;

    }
}
