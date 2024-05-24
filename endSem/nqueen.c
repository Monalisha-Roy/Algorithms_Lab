#include<stdio.h>
#include<stdlib.h>

int count = 0;
int x[10] = {0};

int place(int k , int i);
void nqueens(int k, int n);

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    nqueens(0, n);
    printf("The number of possible solutions: %d\n", count);
    return 0;
}

int place(int k, int i) {
    for(int j = 0; j < k; j++) {
        if(x[j] == i || abs(x[j] - i) == abs(j - k)) 
            return 0;
    }
    return 1;
}

void nqueens(int k, int n) {
    for(int i = 0; i < n; i++) {
        if(place(k, i)) {
            x[k] = i;
            if(k == n-1) {
                printf("[");
                for(int j = 0; j < n; j++) {
                    printf("%d ", x[j]);
                }
                printf("]\n");
                count++;
            }else 
                nqueens(k+1,n);
        }
    }
}