#include<stdio.h>

int main()
{
    int bt[50], wt[50], tt[50], i, p ;
    float avgwt, avgtt ;

    printf("Enter The number of process: ");
    scanf("%d", &p);

    for(i=0; i<p; i++)
    {
        printf("Enter burst time for the process %d: ",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0] = avgwt = 0 ;
    tt[0] = avgtt = bt[0] ;

    for(i=1; i<p; i++)
    {
        wt[i]= wt[i-1] + bt[i-1] ;
        tt[i]= tt[i-1] + bt[i] ;

        avgwt= avgwt + wt[i] ;
        avgtt= avgtt + tt [i] ;
    }

    printf("\tprocess \tburst_time \twaiting_time \tturn_around_time");
    for(i=0 ; i<p ; i++)
    {
        printf("\n\t p%d \t\t%d \t\t%d \t\t%d", i, bt[i], wt[i], tt[i]);
    }

    printf("\n\nAverage waiting time= %.1f ", avgwt/p);
    printf("\n\nAverage turn around time= %.1f \n", avgtt/p);

    return 0;


}

