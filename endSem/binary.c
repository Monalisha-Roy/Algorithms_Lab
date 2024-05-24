#include<stdio.h>

void display(int *A, int n);
int  binarySearch(int *A, int lb, int ub, int key);

void main() {
    int n;
    printf("ENter size of array: ");
    scanf("%d", &n);

    int A[n];
    printf("ENter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Array: ");
    display(A, n);

    printf("ENter element you want to search for: ");
    int key;
    scanf("%d", &key);
    int a = binarySearch(A, 0, n-1, key);
    if(a!= -1) printf("Element found!!");
    else printf("Element not found!!");
}

void display(int *A, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }printf("\n");
}

int  binarySearch(int *A, int lb, int ub, int key) {
    int mid ;

    if(lb <= ub) {
        mid = (lb+ub)/2;
        if(A[mid] == key) return mid;
        else if(A[mid] < key) return binarySearch(A, mid+1, ub, key);
        else return binarySearch(A, lb, mid-1,key);
    }
    return -1;
}