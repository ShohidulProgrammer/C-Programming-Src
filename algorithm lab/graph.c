//Graph element find Degree,in-degree,out-degree,directed, undirected, edge
#include<stdio.h>
main()
{
    int i,j,nod,alphabet=97,degree=0,edge=0,directed=0,undirected=0,outdegree=0;
    printf("Enter the number of Node= ");
    scanf("%d",&nod);
    int graph[nod][nod],indegree[nod];
    for(i=0;i<nod;i++){
        for(j=0;j<nod;j++){
            //clearing indegree garbage value
            indegree[i]=0;
            //input item
            printf("enter the row %c col=%c ",alphabet+i,alphabet+j);
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\n\nYour Graph Details: \n");
    for(i=0;i<nod;i++){
            for(j=0;j<nod;j++){
                //show input value
                //printf("the row %c and col=%c is=%d\n",alphabet+i,alphabet+j,graph[i][j]);
                if(graph[i][j]==1){
                degree++;
                outdegree++;
                //count InDegree of all individual node
                indegree[j]=(indegree[j]+1);
                //find undirected graph & count no of undirected connection
                if(graph[j][i]==1){
                    printf("%c ===== %c\n",alphabet+i,alphabet+j);
                    undirected++;
                    //if node connected with same node
                    if(i==j){
                        undirected++;
                    }
                }
                //else connection is directed
                else{
                    printf("%c ====>> %c\n",alphabet+i,alphabet+j);
                    directed++;
                }
            }
        }
        printf("The OutDegree of %c is=%d\n\n",alphabet+i,outdegree);
        //re-count OutDegree for individual node
        outdegree=0;
    }
    //display InDegree of all individual node
    for(j=0;j<nod;j++){
        printf("The InDegree of %c is=%d\n",alphabet+j,indegree[j]);
    }
    //checking graph directed or undirected
    if(undirected!=0){
        printf("\nThe Graph is Undirected\n");
        //total undirected node= half of finding undirected node
        undirected=undirected/2;
    }
    else {
        printf("\nThe Graph is Directed\n");
    }
    edge=directed+undirected;
    printf("Total Degree=%d\nTotal Undirected Node=%d\nTotal Directed Node=%d\nEdge=%d\n",degree,undirected,directed,edge);
}
