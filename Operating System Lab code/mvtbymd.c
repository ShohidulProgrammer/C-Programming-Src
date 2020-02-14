#include<stdio.h>

main()
{
    int ts,p=1,ps[100],i,e;
    char ch;
    printf("Enter the total memory size: ");
    scanf("%d",&ts);

    for(i=0;i<e;i++)
    {
        printf("\nEnter memory required for process: %d\n",i+1);
        scanf("%d",&ps[i]);

        if(ts>=ps[i])
        {
            ts = ts-ps[i];
            printf("\nMemory is allocated for process: %d\n",i+1);
        }
        else if(ts<=0)
        {
            printf("\nthere are no Remaining Memory\n ");
            exit(1);
        }
        else
        {
            printf("Memory is not allocated for process: %d due to insufficient memory space\n",i+1);

        }

        printf("\n External Fragmentation is: %d\n",ts);
        printf("\nDo you continue?(Y/N)\n");
        scanf(" %c", &ch);
        if(ch =='n'||ch =='N')
        {
            exit(1);
        }
    }

    return 0;
}
