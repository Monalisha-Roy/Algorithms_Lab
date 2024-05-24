#include<stdio.h>
#include<stdlib.h>
#define INF 32000
int V;

void enterEdges(int G[V][V]);
void kruskal(int G[V][V]);
int findParent(int a, int parent[V]);
int isCycle(int a, int b, int parent[V]);

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int G[V][V];
    enterEdges(G);
    kruskal(G);
    return 0;
}

void enterEdges(int G[V][V]) {
    int i, j;
    for(i = 0; i < V; i++) {
        for(j = 0; j< V; j++) {
            G[i][j] = 0;
        }
    }

    printf("Enter the weight of the edges of the graph: ");
    for(i = 0; i < V; i++) {
        for(j = i+1; j < V; j++) {
            printf("%d - %d: ", i, j);
            scanf("%d", &G[i][j]);
            G[j][i] = G[i][j];
        }
    }

    printf("\nThe Adjacency Matrix of the graph is: \n");
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) 
            printf("%d ", G[i][j]);
        printf("\n");
    }
}

int findParent(int a, int parent[V]) {
    while(parent[a])
        a = parent[a];
    return a;
}

int isCycle(int a, int b, int parent[V]) {
    if(a != b) {
        parent[b] = a;
        return 1;
    }
    return 0;
}

void kruskal(int G[V][V]) {
    int i, j , x, y, min, sum=0, no_edge=0, parent[V];
    
    for(i = 0; i < V; i++)
        parent[i] = 0;
    
    printf("\nMinimum Spanning Tree: \n");
    while (no_edge < V-1)
    {
        min = INF;
        for(i = 0; i < V; i++) {
            for(j = 0; j < V; j++) {
                if(min > G[i][j] && G[i][j] != 0 && findParent(i, parent) != findParent(j, parent)) {
                    min = G[i][j];
                    x = i; y = j;
                }
            }
        }
        int a = findParent(x, parent);
        int b = findParent(y, parent);
        if(isCycle(a, b, parent) == 1) {
            sum += min;
            printf("%d - %d: %d\n", x, y, G[x][y]);
            G[x][y] = G[y][x] = INF;
            no_edge++;
        }
    }
    printf("Total cost of the graph is: %d\n", sum);
    
}