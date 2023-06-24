#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define Max_vert 50

typedef struct Graphs{
    int V;
    bool adj[Max_vert][Max_vert];

}Graph;

Graph* Graph_create(int V){

    Graph* g =(Graph*)malloc(sizeof(Graph));

    g->V = V;

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            g->adj[i][j] = false;
        }
    }

    return g;
}

void remove_graph(Graph* g){
    free(g);
}


void add_edge(Graph* g,int src,int dest){
    g->adj[src][dest] = true;
}


void top_sort_func(Graph *g,int v,bool visited[],int stack[],int *top){
int i;

visited[v]=true;

for(i = 0;i<g->V;i++){

if(g->adj[v][i] && !visited[i]){
    top_sort_func(g,i,visited,stack,top);

}
}

stack[++(*top)] = v;


}
void topo_sort(Graph *g){
    int i,t=-1;

    

    int stack[100];

    bool visited[g->V];

    for(i=0;i<g->V;i++){
        visited[i] = false;
    }

    for(i=0;i<g->V;i++){
        if(visited[i]==false)
        {
            top_sort_func(g,i,visited,stack,&t);
        }
    }


    while((t)!=-1){
        printf("%d ",stack[t]);
        (t)--;
    }
}



int main()
{
    // Create a graph given in the above diagram
    Graph* g = Graph_create(6);;
    add_edge(g,5,2);
    add_edge(g,5,0);
    add_edge(g,4,0);
    add_edge(g,4,1);
    add_edge(g,2,3);
    add_edge(g,3,1);
 
    printf("Following is a Topological Sort of the given graph\n");
 
    // Function Call
    topo_sort(g);
 
    return 0;
}
