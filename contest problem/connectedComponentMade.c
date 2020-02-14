#include <stdio.h>
int graph[20][20],color[20],distance[20],finishingTime[20],prev[20],time=0,nod,queue[20],r=0,graph_Transpose[20][20];

long int s1[4],s2[4];
int snakInput(long int snak[])
{
    int i;
    for(i=1;i<=4;i++)
        scanf("%ld",&snak[i]);

    //x or y axis check
    // if x1==x2 then the line is in Y-axis
    if(snak[1]==snak[3])
        {
            for(i=snak[2];i<=snak[4];i++)
            {
                graph[snak[1]][i]=2;
            }
        }

    // if y1==y2 then the line is in X-axis
    else
        return 1;

}

void DFS_Visit(int u)
{
    int v;
   color[u] = 2;
   distance[u] = ++time;
   for(v=1;v<=nod;v++)
   {
    if(graph[u][v]==1)
      {
         if(color[v] == 1)
            {
              prev[v]=u;
              DFS_Visit(v);
            }
      }
   }
   color[u] = 3;
   finishingTime[u] = ++time;
   queue[r++]=u;
}

//DFS Function declaration  start from here

void DFS()
   {
       int u,v;
       for(u=1;u<=nod;u++)
       {
          color[u] = 1;
          prev[u]=-1;
          finishingTime[u]=-1;
          distance[u]=-1;
       }
       //time = 0;
       for(u=1;u<=nod;u++)
         if (color[u] == 1)
             DFS_Visit(u);
   }




void DFS_Visit_Transpose(int u)
{
    int v;
   color[u] = 2;
   time = time+1;
   distance[u] = time;
   for(v=1;v<=nod;v++)
   {
    if(graph_Transpose[u][v]==1)
      {
         if(color[v] == 1)
            {
              printf("-> %c ",v+96);
              prev[v]=u;
              DFS_Visit_Transpose(v);
            }
      }
   }
   color[u] = 3;
   time = time+1;
   finishingTime[u] = time;
}



// DFS function for Transpose Graph
void DFSTranspose()
{
    int u,v;
   for(u=1;u<=nod;u++)
   {
      color[u] = 1;
      prev[u]=-1;
      finishingTime[u]=-1;
      distance[u]=-1;
   }
   time = 0;
   r=1;
   for(u=nod;u>0;u--)
     if (color[queue[u]] == 1)
     {
         printf("\nComponent %d is : %c ",r++,queue[u]+96);
         DFS_Visit_Transpose(queue[u]);
     }

}

void transpose()
{
    int m,n;
    for(m=1;m<=nod;m++){
        for(n=1;n<=nod;n++){
            graph_Transpose[n][m]= graph[m][n];
        }
    }
}

 main()
{
    s1Axis=snakInput(s1);
    s2Axis=snakInput(s2);

    int row,column;
    //printf("Enter total number of nodes: ");
    scanf("%d",&nod);
    printf("\nInput the Graphs Value:\n");
    for(row=1;row<=nod;row++)
    {
        for(column=1;column<=nod;column++)
        {
             scanf("%d",&graph[row][column]);
        }
    }
    DFS();
    transpose();
    /*//show the transpose matrix
    printf("\nThe Transpose matrix is :  \n");
    for(row=1;row<=nod;row++)
    {
        for(column=1;column<=nod;column++)
        {
           printf("%d ",graph_Transpose[row][column]);
        }
        printf("\n");
    }
    */

    DFSTranspose();
    printf("\n");
}

