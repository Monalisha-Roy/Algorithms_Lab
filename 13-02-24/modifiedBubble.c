#include<stdio.h>
int count=0;
void display(int *, int n);
void sort(int *, int n);
void swap(int *, int *);
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
    sort(A, n);
    display(A, n);
    printf("Sorting complete in %d steps\n", count);
}

void display(int *A, int n) {
    int i ;
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }printf("\n");
}

void sort(int *A, int n) {
    
    int i=0, j, flag = 1;
    while(i < n-1 && flag == 1) {
        count++;
        flag = 0;
        for(j = 0; j < n-i-1; j++) {
            if(A[j] > A[j+1]) {
                flag  = 1;
                swap(&A[j], &A[j+1]);
            }
        }
        i++;
    }
}
 
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}