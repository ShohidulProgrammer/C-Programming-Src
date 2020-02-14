//the Adjacency Matrix
#include<stdio.h>
void bfs(source,vertex);
void ENQUEUE();
int DEQUEUE();
int main()
{
    int row,col,alphabet=97,degree=0,nod=0,indegree=0,outdegree=0,totalindegree=0,totaloutdegree =0;
    printf("Enter the number of vertex:");
    scanf("%d",&nod);
    int graph[nod][nod],color[nod];
    printf("\nPress [1] for connected\nPress [0] for not connected\n");
    for(row=0;row<nod;row++){
        //color 1 for white or not touch.
        color[row]=1;
        for(col=0;col<nod;col++){
            printf("%c to %c ",alphabet+row,alphabet+col);
            scanf("%d",&graph[row][col]);
        }
    }
 for (row = 0; row <nod; row++){
        for (col = 0; col <nod; col++){
            outdegree = outdegree + graph[row][col] ;
            indegree = indegree + graph[col][row] ;
            if(graph[row][col] == 1 )
                degree++;
        }
        printf("Outdegree of the %c is = %d\n",alphabet+row,outdegree);
        printf("Indegree of the %c is = %d\n",alphabet+row,indegree);
        totaloutdegree = totaloutdegree + outdegree;
        totalindegree =totalindegree + indegree;
        outdegree = indegree =0;
    }
        printf("\nTotal Number Of Degree:%d\n\n",degree);
        if(totaloutdegree == totalindegree){
            printf("\nThe Graph Is Undirected\n");
        }
        else{
            printf("\nThe Graph Is Directed\n");
        }
    return 0;
}
void bfs(source,vertex){
    int color[];
    for(v=0;v<nod;v++){
        for(u=0;u<nod;u++){
            color[u]=1;
            prev[u]=1;
            d[u]=1;
        }
    }
    color[s]= 2; //color 2 for touch or gray
    d[s]=0;
    prev[s]=1;
    queue=empty;
    enqueue(q,s)
}
    while(){
    u=deque(q);
    for(v=0;v<nod;v++){
        for(u=0;u<nod;u++){
            if(color[v]==1){
                //color 2 for touch or gray
                color[v]=2;
                d[v]=d[u]+1;
                prev[v]=u;
                enqueue(q,v);
            }
        }
        //color=3 for task completed
        color[u]=3;
    }
}
print_path(g,s,v){
    if(v==s)
        printf("s=%d",s);
    else if(prev[v]==1)
        printf("No Path\n");
    else{
        print_path(g,s,prev[v]);
        printf("v=%d",v);
    }

}
