#include<stdio.h>

int main()
{
    int p,bt[20],wt[20],tt[20],i,j;
    float avgwt=0,avgtt=0;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&p);

    printf("\nEnter Process Burst Time\n");
    for(i=0;i<p;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;    //waiting time for first process is 0

    //calculating waiting time
    for(i=1;i<p;i++)
    {
        wt[i] = wt[i-1]+ bt[i-1];
        avgwt+=(float)wt[i];
        //wt[i]=0;
        //for(j=0;j<i;j++)
            //wt[i]+=bt[j];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    //calculating turnaround time
    for(i=0;i<p;i++)
    {
        tt[i]=bt[i]+wt[i];

        avgtt+=(float)tt[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tt[i]);
    }

    avgwt/=(float)i;
    avgtt/=(float)i;
    printf("\n\nAverage Waiting Time:%.2f",avgwt);
    printf("\nAverage Turnaround Time:%.2f",avgtt);

    return 0;
}
