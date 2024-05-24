#include<stdio.h>
#define INF 32000
int V;

void enterEdges(int G[V][V]);
void prims(int G[V][V]);

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int G[V][V];
    enterEdges(G);
    prims(G);
    return 0;
}

void enterEdges(int G[V][V]) {
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            G[i][j] = 0;
        }
    }
    printf("Enter the weight of the edges of the graph: \n");
    for(int i=0; i<V; i++) {
        for(int j=i+1; j<V; j++) {
            printf("%d - %d: ", i, j);
            scanf("%d", &G[i][j]);
            G[j][i] = G[i][j];        
        }
    }

    printf("\nThe adjacency matrix for the graph is : \n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("%d " ,G[i][j]);
        }printf("\n");
    }
}

void prims(int G[V][V]) {
    int  i, j, x, y, min, sum=0, no_edge=0;
    int selected[V];
    for(i = 0; i < V; i++) 
        selected[i] = 0;
    
    selected[0] = 1;
    printf("\nMinimum spanning Tree: \n");
    while(no_edge < V-1) {
        min = INF;
        for(i = 0; i < V; i++) {
            if(selected[i] == 1) {
                for(j = 0; j < V; j++) {
                    if(selected[j] == 0 && G[i][j] != 0) {
                        if(min > G[i][j]) {
                            min = G[i][j];
                            x = i; y = j;
                        }
                    }
                }
            }
        }
        sum += min;
        printf("%d - %d: %d\n", x, y, G[x][y]);
        selected[y] = 1;
        no_edge++;
    }
    printf("Total cost of the graph: %d\n", sum);
}   