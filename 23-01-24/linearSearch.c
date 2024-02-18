#include<stdio.h>

int main() {
    int A[10], i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("The elements are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }printf("\n");

    int key;
    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    int flag = 0;
    for(i = 0; i < n; i++ ) {
        if (A[i] == key) flag = 1;
    }

    if(flag == 1) printf("Element found\n");
    else printf("Element not found\n");
}