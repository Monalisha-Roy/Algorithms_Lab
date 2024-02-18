#include<stdio.h>

int BinaryS(int *A, int lb, int ub, int key);
void sort(int *A, int n);

void main() {
    int A[10], n, i, key, flag;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &A[i]);
    }
    sort(A, n);

    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    flag = BinaryS(A, 0, n, key);

    if(flag == -1) printf("Element not found in array\n");
    else printf("Element found in array\n");
}

int BinaryS(int *A, int lb, int ub, int key) {
    int mid;
    while(lb <= ub) {
        mid = (lb+ub)/2;
        if(A[mid] == key) {
            return mid;
        }
        else if(A[mid] < key) {
            return BinaryS(A, mid+1, ub, key);
        }
        else {
            return BinaryS(A, lb, mid-1, key);
        }
    }
    return -1;
}

void sort(int *A, int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(A[i] > A[j]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }printf("\n");

}