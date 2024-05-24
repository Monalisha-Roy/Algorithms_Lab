#include<stdio.h>
int n;

void insertElement(int *A);
void deleteElement(int *A);
void display(int *A);

int main() {
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    display(A);

    int a, b;
    do {
        printf("Insert element? (1/0): ");
        scanf("%d", &a);
        if(a) insertElement(A);
        printf("Delete Element? (1/0): ");
        scanf("%d", &b);
        if(b) deleteElement(A);
    }while(a==1 || b==1);
    return 0;

}

void insertElement(int *A) {
    printf("Enter element you want to insert: ");
    int key, pos;
    scanf("%d", &key);
    printf("At position: ");
    scanf("%d", &pos);
    for(int i = n; i > pos; i--) {
        A[i] = A[i-1];
    }
    A[pos] = key;
    n++;
    display(A);
}

void deleteElement(int *A) {
    printf("ENter element you want to delete: ");
    int key, pos;
    scanf("%d", &key);

    for(int i = n; i >= 0; i--) {
        if(A[i] == key) pos = i;
    }

    for(int j = pos; j < n-1; j++) {
        A[j] = A[j+1];
    }
    n--;
    display(A);
}

void display(int *A) {
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }printf("\n");
}