#include<stdio.h>
int g[20][20],color[20],prev[20],d[20],f[20],n,time;
void DFS_Visit(int u){
    int v;
    color[u] = 2;
    time= time+1;
    d[u] = time;
    for(v=1;v<=n;v++){
        if(g[u][v] == 1){
            if(color[v] == 1){
                prev[v]=u;
                DFS_Visit(v);
            }
        }
    }
    color[u] = 3;
    time = time+1;
    f[u] = time;
}
void DFS(){
    int u,v;
    for(u=1;u<=n;u++)
   {
        color[u]= 1;
		prev[u]=-1;
		f[u]=-1;
		d[u]=-1;
   }
   time = 0;
   for(u=1;u<=n;u++){
    if(color[u] == 1){
        DFS_Visit(u);
    }
   }
}

int main()
{
    int i,j,s;
    printf("Enter node no: ");
    scanf("%d",&n);
    printf("Enter node input: \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    //printf("Enter source no: ");
    //scanf("%d",&s);
    DFS();
    printf("\ncolor :  ");
    for(i=1;i<=n;i++)
    {
        printf("%c=%d ",96+i,color[i]);
    }
    printf("\nStarting Time : ");
     for(i=1;i<=n;i++)
    {
        printf("%c=%d ",96+i,d[i]);
    }
    printf("\nFinishing Time :    ");
    for(i=1;i<=n;i++)
    {
        printf("%c=%d ",96+i,f[i]);
    }
    printf("\nprev :    ");
    for(i=1;i<=n;i++)
    {
        printf("%c=>%c ",96+i,96+prev[i]);
    }
    //disconnectNod();
return 0;
}
