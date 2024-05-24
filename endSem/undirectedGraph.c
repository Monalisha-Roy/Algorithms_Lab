#include<stdio.h>

void main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int G[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            G[i][j] = 0;
        }
    }

    printf("Enter the weights of the edges: ");
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            printf("%d - %d: ", i, j);
            scanf("%d", &G[i][j]);
            G[j][i] = G[i][j];
        }
    }

    printf("Adjacency Matrix: \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", G[i][j]);
        }printf("\n");
    }
}