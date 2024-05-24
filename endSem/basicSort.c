#include<stdio.h>

void display(int *A, int n);
void bubbleSort(int *A, int n);
void insertionSort(int *A, int n);
void selectionSort(int *A, int n);
void swap(int *, int*);

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) 
        scanf("%d", &A[i]);
    
    printf("Array: ");
    display(A, n);
    
    //bubbleSort(A, n);
    //selectionSort(A, n);
    insertionSort(A, n);
    printf("Sorted Array : ");
    display(A, n);
    return 0;
}

void display(int *A, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *A, int n) {
    int i = 0, flag = 1;
    while(i < n && flag == 1) {
        flag = 0;
        for(int j = 0; j < n-i; j++) {
            if(A[j] > A[j+1]) {
                flag = 1;
                swap(&A[j], &A[j+1]);
            }
        }i++;
    }
}

void selectionSort(int *A, int n) {
    for(int i = 0; i < n; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(A[j] < A[min]) min = j;
        }
        if(min != i) swap(&A[min], &A[i]);
    }
}

void insertionSort(int *A, int n) {
    for(int i = 0; i < n; i++) {
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
            A[j+1] = key;
        }
    }
}