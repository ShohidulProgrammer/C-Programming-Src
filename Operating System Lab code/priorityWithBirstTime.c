#include<stdio.h>
int main()
{
    int process;
    printf("Enter the number of process: ");
    scanf("%d", &process);

    int i=0, j=0, p[process], prt[process], bt[process],wt[process],tat[process], n = process;
    while(process--)
    {
        p[i] = i;

        printf("\nEnter the priority for process %d: ", i+1);
        scanf("%d", &prt[i]);

        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &bt[i]);

        i++;
    }

    // bubble sort for priority swap
    int temp;
    for(i=0; i < n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(prt[i] > prt[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = bt[i];
                bt[i]=bt[j];
                bt[j]= temp;

                temp = prt[i];
                prt[i]= prt[j];
                prt[j]= temp;
            }
        }
    }

    // Again bubble sort If there have same priority then Burst Time swap
    for(i=0; i < n; i++)
    {
        for(j=i+1; j < n; j++)
        {
            if(prt[i] == prt[j])
            {
                if(bt[i] > bt[j])
                {
                    temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;

                    temp = bt[i];
                    bt[i] =bt[j];
                    bt[j] = temp;

                    temp = prt[i];
                    prt[i] = prt[j];
                    prt[j] = temp;
                }
            }
        }
    }

    int awt = 0, atat = bt[0];

    wt[0] =0;
    tat[0] = bt[0];
    for(i=1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        awt = awt + wt[i];

        tat[i] = bt[i] + wt[i];
        atat = atat + tat[i];
    }

    printf("\n\nProcess    priority    Burst Time   Waiting Time    Turn Around Time\n");
    for(i = 0; i < n; i++)
    {
        printf("%-12d %-13d %-15d %-17d %d\n",p[i]+1, prt[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time: %.2lf", (awt*1.0)/n);
    printf("\nAverage Turn Around Time: %.2lf", (atat*1.0)/n);
    return 0;

}
