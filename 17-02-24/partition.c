#include<stdio.h>

void partition(int *, int lb, int ub);
void swap(int *, int *);
void display(int *, int n);

void main() {
    int A[10], n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Array: ");
    display(A, n);
    
    printf("Sorted array: ");
    partition(A, 0, n-1);
    display(A, n);
}

void partition(int *A, int lb, int ub) {
    int i, j, x;
    i = lb-1; j = lb; x = A[ub];

    while(j < ub) {
        
        if(A[j] < x) {
        i++;
        swap(&A[i], &A[j]);
        }
        j++;
    }
    swap(&A[i+1], &A[j]);  
}

void display(int *A, int n) {
    int i ;
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}