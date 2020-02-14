#include<stdio.h>
int graph[20][20],nod,Traverse[20],prev[20],distance[20],weight=0;
void get_Graph_In_Matrix()
{
    int row,col;
    printf("Enter node no: ");
    scanf("%d",&nod);
    //input graph within matrix
    printf("\nInput all nodes weight:\n");
    for(row=0;row<nod;row++)
    {
        for(col=0;col<nod;col++)
        {
            scanf("%d",&graph[row][col]);
        }
    }

    /*
    printf("\n");
    for(row=0;row<nod;row++)
    {
        for(col=0;col<nod;col++)
        {
            printf("%d ",graph[row][col]);
        }
        printf("\n");
    }
    */
}
//prim's algorithm start from here.
void MST_Prim()
{

    int u,v,step,minDistance,temp=0;


    //declare initial value.
    for(u=0;u<nod;u++)
    {
        Traverse[u]= 0;
		distance[u]=9999;
		prev[u]=-1;
    }


    u=temp;
    distance[u]=temp;
    prev[u]=temp;
    printf("\n");


    // finding minimum spanning tree.
    for(step=1;step<=nod;step++)
     {
        // Go to smallest nod's row.
        u = temp;
        Traverse[u]=step;


        printf("%c=>%c weight: %d\n",97+prev[u],97+u,distance[u]);
        weight = weight+distance[u];


        //initialized smallest nod as infinity value.
        minDistance=9999;
        for(v=0;v<nod;v++)
        {
            //update eadges if small weight found and if not traverses
            if((Traverse[v] ==0) && (graph[u][v] < distance[v]))
            {
                distance[v] = graph[u][v];
                prev[v] = u;
            }


            //update smallest nod & min distance
            if((Traverse[v] ==0) && (distance[v] < minDistance) ){
                temp = v; //update smallest node
                minDistance = distance[v]; //update min distance
                //printf("\nsmallestNod:%c=%d \n",97+v,distance[v]);
            }

        }
    }
 }

int main()
{
    int i;
    get_Graph_In_Matrix();
    MST_Prim();

    //print minimum spanning tree
    printf("\ntraverse :  ");
    for(i=0;i<nod;i++)
    {
        printf("%c=%d ",97+i,Traverse[i]);
    }

    printf("\ndistant : ");
     for(i=0;i<nod;i++)
    {
        printf("%c=%d ",97+i,distance[i]);
    }

    printf("\nprev :    ");
    for(i=0;i<nod;i++)
    {
        printf("%c<=>%c ",97+i,97+prev[i]);
    }

    printf("\n\n\tTotal weight: %d\n",weight);

    return 0;
}
