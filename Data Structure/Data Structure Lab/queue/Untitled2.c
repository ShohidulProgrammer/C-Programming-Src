#include<stdio.h>
int graph[20][20],nod,color[20],prev[20],distance[20],queue[20],f=1,r=1;

void ENQUEUE(int a)
{
   queue[r]=a;
   r++;
}
int DEQUEUE()
{
    int a;
   a=queue[f];
   f++;
   return a;
}

void BFS(int s) // BFS starts from here
{
    int u,v,i;
   for(u=1;u<=nod;u++)
   {
        color[u]= 1;
		distance[u]=-1;
		prev[u]=-1;
   }
   color[s]=2;
   distance[s]=0;
   prev[s]=-50;

	ENQUEUE(s);
    while(f!=r)
     {
       u = DEQUEUE();
       for(v=1;v<=nod;v++)
        {
            if(graph[u][v]==1)
            {
                if (color[v] == 1)
                {
                     color[v] = 2;
                     distance[v] = distance[u] + 1;
                     prev[v] = u;
                     ENQUEUE(v);
                     //print_path(u,s,v);
                }
               else if(color[v] == 2){
                    printf("\ncycle has been detected\n");
                }
            }

         }
         color[u] = 3;
       }
}
