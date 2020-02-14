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
void print_path(int g,int s,int v){
    if(v==s){
        printf("\n%c ",96+s);
    }
    else if(prev[v]== -1)
        printf("No Path\n");
    else{
        print_path(g,s,prev[v]);
        printf("%c ",96+v);
    }
}

void disconnectNod(){
    int i;
    for(i=1;i<=nod;i++){
        if(color[i]== 1){
            printf("\n\nThe Nod=%c is Disconnected!",96+i);
        }
    }

}

int main()
{
    int row,col,s;
    printf("Enter node no: ");
    scanf("%d",&nod);
    //input graph within matrix
    for(row=1;row<=nod;row++)
    {
        for(col=1;col<=nod;col++)
        {
            scanf("%d",&graph[row][col]);
        }
    }
    printf("Enter source no: ");
    scanf("%d",&s);
    BFS(s);
    printf("\ncolor :  ");
    for(row=1;row<=nod;row++)
    {
        printf("%c=%d ",96+row,color[row]);
    }
    printf("\ndistant : ");
     for(row=1;row<=nod;row++)
    {
        printf("%c=%d ",96+row,distance[row]);
    }
    printf("\nprev :    ");
    for(row=1;row<=nod;row++)
    {
        printf("%c=>%c ",96+row,96+prev[row]);
    }
    disconnectNod();
return 0;
}
