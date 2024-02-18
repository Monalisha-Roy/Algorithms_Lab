#include<stdio.h>

int partition(int *, int lb, int ub);
void swap(int *, int *);
void display(int *, int n);
void qs(int *, int lb, int ub);

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
    qs(A, 0, n-1);
    display(A, n);
}

void qs(int *A, int lb, int ub) {
    if (lb < ub) {
        int loc = partition(A, lb, ub);
        partition(A, lb, loc-1);
        partition(A, loc+1, ub);
    }
}

int partition(int *A, int lb, int ub) {
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
    return i+1;  
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