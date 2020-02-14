#include<stdio.h>
int main()
{
 char s[9][5] = {"Hello", "Lazy", "Hello", "Lazy", "Hello", "for", "the", "Lazy", "Judge"};
 int i, j, k, m, n, num, count, mod;
 while(printf("Enter team number: ") && scanf("%d", &num) != EOF)
 {
  if(num == 9)
  {
   for(i = 0; i < num; i++)
   {
    printf("Team%d: ", i+1);
    for(j = 0; j < 5; j++)
     printf("%c",s[i][j]);
    printf("\n");
   }
   printf("\n");
  }
  else if(num < 9)
  {
   for(i = 0; i < num; i++)
   {
    printf("Team%d: ", i+1);
    for(j = 0; j < 5; j++)
     printf("%c",s[i][j]);
    printf("\n");
   }
   i = 0;
   k = 1;
   for(i = num + i; i < 9; i++)
   {
    printf("Team%d: ", k);
    if(k == num)
     k = 1;
    else
     k++;
    for(j = 0; j < 5; j++)
     printf("%c",s[i][j]);
    printf("\n");
   }
   printf("\n");
  }
  else if(num > 9)
  {
   count = 0;
   m = 1;
   for(i = 0; i < 9; i++)
   {
    count++;
    printf("Team%d: ", m);
    m++;
    for(j = 0; j < 5; j++)
     printf("%c",s[i][j]);

    printf("\n");
    if(i == 8)
     i = -1;
    if(count == num)
     break;
   }
   mod = num % 9;
   m = 1;
   if(mod != 0)
   {
    for(i = mod; i < 9; i++)
    {
     printf("Team%d: ", m);
     m++;
     for(j = 0; j < 5; j++)
      printf("%c",s[i][j]);
     printf("\n");
    }
   }
  }
  printf("\n");
 }
 return 0;
}
