#include<stdio.h>
main()
{
    int n,i,j,temp,row,col,t;
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
        col=-1;

    //output char1
    for(i=0;i<2;i++)
    {
        for(j=0;j<n;j++,col++)
        {
           // level:
            if(ch[row][col]!='#')
            {

                if(ch[!row][col-1]=='#')
                {
                    col= col-2;
                    row=!row;
                   // goto level;
                }
            }
            else
            {
                ch[row][col]='1';
                printf("[%d][%d]->%c",row,col,ch[row][col]);
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


    }
}
