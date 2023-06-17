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

void bfs(Graph* g,int s){

    bool visited[Max_vert];
    for(int i=0;i<g->V;i++){
        visited[i] = false;

    }

    int queue[Max_vert];

    int front=0,rear=0;

    visited[s] = true;
    queue[rear++] = s;

    while(front!=rear){
        s = queue[front++];
        printf("%d ",s);


        for(int adjacent = 0;adjacent<g->V;adjacent++){

            if(g->adj[s][adjacent] && !visited[adjacent]){
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }

    }

}




void Graph_DFSUtil(Graph* g, int v, bool visit[])
{
    visit[v] = true;
    printf("%d ", v);

    for (int i = 0; i < g->V; i++) {
        if (g->adj[v][i] && !visit[i]) {
            Graph_DFSUtil(g, i, visit);
        }
    }
}



void dfs(Graph* g,int s){
    bool visit[Max_vert];
    for(int i=0;i<g->V;i++){
        visit[i] = false;

    }

    // int stack[Max_vert];
    // int top = -1;

    // visit[s] = true;

    // // stack[++top] = s;


    // while(top<Max_vert){

    //     s = stack[top--];
    //     printf("%d",s);

    //     for(int adjacent = 0;adjacent<g->V;adjacent++){

    //         if(g->adj[s][adjacent] && !visit[adjacent]){
    //             visit[adjacent] = true;
    //             stack[++top] == adjacent;
    //         }
    //     }

    Graph_DFSUtil(g,s,visit);

    }

   




int main(){
    Graph* g = Graph_create(4);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 0);
    add_edge(g, 2, 3);
    add_edge(g, 3, 3);
 
    printf("Following is Breadth First Traversal "
           "(starting from vertex 2) \n");
    bfs(g, 2);
    printf("\n");

    printf("Following is Depth First Traversal "
           "(starting from vertex 2) \n");
    dfs(g,2);
    
    
    remove_graph(g);
    



    return 0;
}
