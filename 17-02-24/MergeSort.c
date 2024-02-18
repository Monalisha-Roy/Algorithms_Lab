#include<stdio.h>

void MS(int *, int lb, int ub);
void M2SL(int *, int lb, int mid, int ub);
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
    MS(A, 0, n);
    display(A, n);
}

void MS(int *A, int lb, int ub) {
    int mid;
    if(lb < ub) {
        mid = (lb+ub)/2;
        MS(A, lb, mid);
        MS(A, mid+1, ub);
        M2SL(A, lb, mid, ub);
    }
}

void M2SL(int *A, int lb, int mid, int ub) {
    int i = lb, j = mid+1, k = lb;
    int B[10];
    while(i <= mid && j <= ub) {
        B[k++] = (A[i] < A[j]) ? A[i++] : A[j++];
    }

    if(j > ub) {
        while(i <= mid) {
            B[k] = A[i];
            k++; i++;
        }
    }
    
    if(i > mid) {
        while(j <= ub) {
            B[k] = A[j];
            k++; j++;
        }
    }

    for(k = lb; k <= ub; k++) {
        A[k] = B[k];
    }
}

void display(int *A, int n) {
    int i ;
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }printf("\n");
}