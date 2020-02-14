#include<stdio.h>
#include<stdlib.h>
long unsigned int fact(int n);
int modSum(long long int f);
main()
{
    long n;
    printf("Enter a Number:");
    scanf("%d",&n);
    printf("%d\n",fact(n));
    printf("modSum=%d\n", modSum(fact(n)));
}
int modSum(long long int div)
{
    int mod,sum=0;
    printf("Factorial is =%d\n",div);


      while(div!=0)
        {
            level:
            mod=div%10;
            printf("mod=%d\n",mod);
            sum=sum+mod;
            div=div/10;
            printf("div=%d\n\n",div);
        }

    if(sum>9)
    {
        div=sum;
        sum=0;
        printf("div=%d\n\n",div);
        goto level;
    }
    else
    {
         printf("return sum=%d\n\n",sum);
        return sum;
    }
}
long unsigned int fact(int n)
{

    if(n>=1)
    {
        return n*fact(n-1);
    }
    else
           return 1;


}
