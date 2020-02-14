#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
int time=0;
int smallest_component = 100000;
int count=0;

//these are the value that will be used to mark vertices
enum
{
    white, gray, black
}color;

// A structure to represent an adjacency list node
typedef struct _Node
{
    int dest;
    int color;
    struct _Node* next;
}Node;

/* This is the structure of the adjacency list
* It simply has an array of Nodes
*/
typedef struct _Adj
{
    Node *list;  // pointer to head node of list
}Adj;

int D[MAX];
int F[MAX];
int Color[MAX];

// Prototypes
void printGraph(Adj *list, int vertices);
void addEdge(Adj *list, int start, int end);
void DFS(Adj* list, int vertex);


int main(int argc, char **argv)
 {
 FILE *in = NULL;
int vertex1=0, vertex2=0;
int vertex_count=0;
Node *head = NULL;

int v=1;
int u=1;
int connected_components = 0;

//make sure enough arguments are supplied
//if(argc!=2)
{
    //printf("hw1 <vertices-file>\n");
   // return 1;
}

//open the file
in = fopen(argv[1], "r");

//check to see if the file was opened
if(in == NULL)
{
    printf("The file could not be opened");
    return 2;
}

//START THE INSERTION OF THE VERTICES

//grab the first number. It is the number of vertices
fscanf(in, "%d", &vertex_count);
int vertices = vertex_count + 1;

//Create the struct pointer and call the function to create the Graph
Adj* list = (Adj*)malloc(sizeof(Adj)*vertices);

for(v=1; v<vertices; v++){
    Color[v] = white;
}


//run through each pair of numbers
while(fscanf(in, "%d %d", &vertex1, &vertex2)!=EOF)
{
    // create the first list
    addEdge(list, vertex1, vertex2);
}

printf("\n\n");

Node *temp;

//run through the graph's nodes
for (v = 1; v < vertices; v++)
 {
    count = 0;
    if(Color[v] == white){
        DFS(list, v);
        connected_components++;

        if(smallest_component>count)
            smallest_component=count;
    }
 }

printf("The number of connected components is %d\n", connected_components);

printf("The smallest component has %d vertices\n", smallest_component);

free(list);

//printGraph(myGraph);
return 0;
}

//Run a DFS given the Adjacency list and vertex in the list
 void DFS(Adj* list, int vertex)
{
count++;
//printf("\nI am in DFS with node %d \n", vertex);

Color[vertex] = gray;

time = time + 1;
D[vertex] = time;
Node *temp;

for(temp = list[vertex].list; temp != NULL; temp = temp->next)
{
        if(Color[temp->dest] == white)
            DFS(list, temp->dest);
}

//get the new time, color, and end time
time = time+1;
F[vertex] = time;

//this means that we backtracked and now the node is black
Color[vertex] = black;
 }

/*
* This function creates the edge between the two vertices.
 * Since we have an UNDIRECTED graph, when I create the edges, I create them for both       vertex and destination
  */
void addEdge(Adj* list, int v, int dest)
{
//create the edge between vertex and destination
Node* temp = (Node*)malloc(sizeof(Node));
temp->next = list[v].list;
temp->dest = dest;
list[v].list = temp;

//create the edge between dest and vertex
Node* temp2 = (Node*)malloc(sizeof(Node));
temp2->next = list[dest].list;
temp2->dest = v;
list[dest].list = temp2;
}
