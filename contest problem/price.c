#include<stdio.h>
main()
{
    int m,r,c,T=0;
    scanf("%d",&c);
    while(T<c && T<=25)
    {
        T++;
        scanf("%d %d",&m,&r);
         if(m==r)
            {
                printf("Both gets equal chocolates.\n");
            }
        else if(m<r)
           {
               printf("Raju\n");
           }
        else
        {
             printf("Mina\n");
        }

    }
}

