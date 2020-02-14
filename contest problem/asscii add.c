#include<stdio.h>
main()
{
    int i,t,sum=0;
    char word[3];
    scanf("%d",&t);
    fflush(stdin);
    fflush(stdout);
    while(t--)
    {
        printf("Give me a word with 3 letter\n");
        gets(word);
        for(i=0;i<3;i++)
        {
            sum = word[i] + sum;
        }
        printf("total= %d\n",sum);
        sum=0;
        printf("line no. =%d\n",t);

    }

}
