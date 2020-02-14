//Graph implementation by 2-D Array
#include<stdio.h>

int main()
{
    int i,j,a[5][5],n;
   // printf("Enter the size of the matrix:");
   for(i=0;i<=4;i++)
   {
       for(j=0;j<=4;j++)
       {
           printf("%d%d ",i,j);
       }

      printf("\n");
   }
   printf("\n");
   for(i=0;i<=4;i++)
   {
       for(j=0;j<=4;j++)
       {
           scanf("%d",&a[i][j]);
       }

      printf("\n");
   }
 for(i=0;i<=4;i++)
   {
       for(j=0;j<=4;j++)
       {
           printf("%d ",a[i][j]);
       }

      printf("\n");
   }



   return 0;
}
