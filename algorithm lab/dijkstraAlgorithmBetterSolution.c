#include<stdio.h>
#define INFINITY 9999
#define MAX 20

void dijkstra(int G[MAX][MAX],int n,int source);

int main()
{
    int G[MAX][MAX],i,j,nod,u;
    printf("Enter no. of vertices:");
    scanf("%d",&nod);

    // input graph
    printf("\nEnter the adjacency matrix: \n");
    for(i=0;i<nod;i++)
        for(j=0;j<nod;j++)
            scanf("%d",&G[i][j]);

    // take source node
    printf("\nEnter the starting node: ");
    scanf("%d",&u);

    //dijkstra algorithm call
    dijkstra(G,nod,u);

    return 0;
}

// dijkstra algorithm definition
void dijkstra(int G[MAX][MAX],int nod,int source)
{

    int cost[MAX][MAX],distance[MAX],prev[MAX];
    int visited[MAX],count,minDistance,nextNode,i,j;

    //prev[] stores the previous of each node
    //count gives the number of nodes seen so far

    //create the cost of the matrix
    for(i=0;i<nod;i++)
        for(j=0;j<nod;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    //initialize prev[],distance[] and visited[]
    // if source connected with any node then take the weight
    // other wise infinity
    for(i=0;i<nod;i++)
    {
        distance[i]=cost[source][i];
        prev[i]=source;
        visited[i]=0;
    }

    distance[source]=0;
    visited[source]=1;
    count=1;

    while(count<nod-1)
    {
        minDistance=INFINITY;

        // nextNode gives the node at minimum distance
        for(i=0;i<nod;i++)
            if(distance[i]<minDistance&&!visited[i])
            {
                minDistance=distance[i];
                nextNode=i;
            }

            // if can't go from source node to others node then exit the program
            if(minDistance==INFINITY)
            {
                printf("There has no path from %c to others node",source+97);
                goto level;
            }

            //check if a better path exists through nextNode
            visited[nextNode]=1;
            for(i=0;i<nod;i++)
                if(!visited[i])
                    if(minDistance+cost[nextNode][i]<distance[i])
                    {
                        distance[i]=minDistance+cost[nextNode][i];
                        prev[i]=nextNode;
                    }
        count++;
    }


    // print the path and distance of each node
    for(i=0;i<nod;i++)
        if(i!=source)
        {
            if(distance[i]==INFINITY)
            {
                printf("\nCan't go from %c to %c ",source+97,i+97);
            }

            else
            {

                printf("\nDistance of node: %c=%d",i+97,distance[i]);
                printf("\nPath: %c",i+97);

                j=i;
                do
                {
                    j=prev[j];
                    printf("<=%c",j+97);
                }while(j!=source);
            }
        }
    level: printf("\n");
}
