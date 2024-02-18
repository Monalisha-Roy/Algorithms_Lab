#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) swap(&arr[i], &arr[j]);
        }
    }
}

int main() {
    int A[10], i , n, mid, low, high;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d values: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    sort(A, n);

    printf("The values are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }printf("\n");

    printf("Enter the value you want to search for: ");
    int key;
    scanf("%d", &key);
    
    int flag = 0;
    low = 0;
    high = n-1;
    while(low<=high) {
        mid = (low+high)/2;
        if(A[mid] == key) {
            flag = 1;
            break;
        }
        else if(A[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    if(flag == 1) printf("Element found\n");
    else printf("Element not found\n");
}