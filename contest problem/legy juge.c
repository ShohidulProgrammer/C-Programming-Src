#include<stdio.h>
int main()
{
    int i,j,team,n=1,teamCount=1;
    //Hello Lazy Hello Lazy Hello for the Lazy Judge
    char song[9][6]= {"Hello","Lazy","Hello","Lazy","Hello","for","the","Lazy","Judge"};
    printf("Enter the Number of team: ");
    scanf("%d",&team);
    while(1)
    {
        for(i=0;i<9;i++)
        {
            printf("team%d:",n);
            for(j=0;j<=4;j++)
            {
                printf("%c",song[i][j]);
            }
            if(n==team)
            n=1;
            else
                n++;
            printf("\n");
            teamCount++;
        }
        if(teamCount>team)
            break;
    }
    return 0;
}
