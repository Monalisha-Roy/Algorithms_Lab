#include<stdio.h>

void BinaryS(int *arr, int n, int key);
void LinearS(int *arr, int n, int key);

void main() {
    int A[100], n, i, a,key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements: ",n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &A[i]);
    }
    
    printf("Enter the value you want to search: ");
    scanf("%d", &key);
    printf("Use 1. Binary Search or 2. Linear SEarch: ");
    scanf("%d", &a);
    
    if(a == 1)  BinaryS(A, n, key);
    else LinearS(A, n, key);
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

void LinearS(int *arr, int n, int key) {
    int i, flag = 0;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) 
        {
            printf("Element found in array in %d steps\n", i);
            flag = 1;
            break;
        }
    }if(flag == 0) printf("Element not found in array after %d steps\n", n);
}