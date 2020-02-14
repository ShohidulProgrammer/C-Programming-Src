#include<stdio.h>

main()
{
   int nb,nf,bs[100],fs[100],n,i,j,frg[100];

   printf("Enter the no of Blocks:\n");
   scanf("%d",&nb);
   int bn[nb];
   int temp[nb];

   printf("Enter the no of Files:\n");
   scanf("%d",&nf);

   for(i=0;i<nb;i++)
   {
       printf("Enter the Block size %d:\n",i+1);
       scanf("%d",&bs[i]);

   }

   for(i=0;i<nf;i++)
   {
       printf("Enter the File size:%d\n",i+1);
       scanf("%d",&fs[i]);
   }

   for(i=0,j=0,n=0;i<nb;i++)
   {

       if(fs[j]<=bs[i])
       {
           frg[j] = bs[i] - fs[j];
           bn[j]  = i;
           temp[j] = bs[i];
           j++;
           n++;

       }

   }

   //output
   printf("\nFileNo  FileSize  BlockNo  Blocksize  Fragment \n");
   for(i=0;i<n;i++)
   {
        printf("%d   \t%d \t\t%d   \t%d   \t%d \n",i+1,fs[i],bn[i]+1,temp[i],frg[i]);
   }
}
