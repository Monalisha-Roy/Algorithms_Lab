#include<stdio.h>

void BinaryS(int *arr, int n, int key);
void sort(int *, int n);
void swap(int *, int *);
void display(int *, int n);

void main() {
    int A[100], n, i, a,key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements: ",n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &A[i]);
    }

    printf("Array: ");
    sort(A, n);
    display(A, n);
    
    printf("Enter the value you want to search: ");
    scanf("%d", &key);
    
    BinaryS(A, n, key);
}

void BinaryS(int *arr, int n, int key) {
    int mid, lb=0, ub=n, count=0, flag = 0;
    while(lb<=ub) {
        mid = (lb+ub)/2;
        count++;
        if(arr[mid] == key) 
        {
            printf("Element found in array in %d steps", count);
            flag = 1;
            break;
        }
        else if(arr[mid] < key) 
            lb = mid + 1;
        else 
            ub = mid - 1;
    }
    if(flag == 0) printf("Element not found in array after %d steps\n", count);
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
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *A, int n) {
    int i ;
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }printf("\n");
}