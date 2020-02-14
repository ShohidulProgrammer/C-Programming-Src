//the Adjacency Matrix
#include<stdio.h>
int main()
{
    int row,col,alphabet=97,degree=0,nod=0,indegree=0,outdegree=0,totalindegree=0,totaloutdegree =0;
    printf("Enter the number of vertex:");
    scanf("%d",&nod);
    int graph[nod][nod];
    printf("\nPress [1] for connected\nPress [0] for not connected\n");
    for(row=0;row<nod;row++){
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
