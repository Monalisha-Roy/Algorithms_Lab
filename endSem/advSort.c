#include<stdio.h>

void mergeSort(int *A, int lb, int ub);
void merge2SortedList(int*A, int lb, int ub, int mid);
void display(int *A, int n);
void quickSort(int *A, int lb, int ub);
int partition(int *A, int lb, int ub);
void swap(int *, int *);
void heapSort(int *A, int n);
void buildMaxheap(int *A, int n);
void heapify(int *A, int i, int n);

int main() {
    int n;
    printf("ENter size of array: ");
    scanf("%d", &n);

    int A[n];
    printf("ENter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Array: ");
    display(A,n);

    //mergeSort(A, 0, n);
    //quickSort(A, 0, n);
    heapSort(A, n);
    printf("Sorted Array: ");
    display(A, n);
    return 0;
    
}

void mergeSort(int *A, int lb, int ub) {
    int mid;
    if(lb<ub) {
        mid = (lb+ub)/2;
        mergeSort(A, lb, mid);
        mergeSort(A, mid+1, ub);
        merge2SortedList(A, lb, ub, mid);
    }
}

void merge2SortedList(int *A, int lb, int ub, int mid) {
    int i = lb, j = mid+1, k = lb, B[ub];

    while(i <= mid && j <= ub) {
        B[k++] = (A[i] < A[j]) ? A[i++] : A[j++];
    }

    if(i > mid) {
        while(j <= ub) {
            B[k++] = A[j++];
        }
    }

    if(j > ub) {
        while(i <= mid) {
            B[k++] = A[i++];
        }
    }

    for(i = lb; i <= ub; i++) {
        A[i] = B[i];
    }
}

void display(int *A, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }printf("\n");
}

int partition(int *A, int lb, int ub) {
    int i = lb-1, j = lb, x = A[ub];

    while(j < ub) {
        if(A[j] < x) {
            i++;
            swap(&A[i], &A[j]);
        }
        j++;
    }
    swap(&A[i+1], &A[j]);
    return i+1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *A, int lb, int ub) {
    int p;
    if(lb< ub) {
        p = partition(A, lb, ub);
        quickSort(A, lb, p-1);
        quickSort(A, p+1, ub);
    }
}

void heapSort(int *A, int n) {
    buildMaxheap(A, n);
    for(int i = n-1; i >= 0; i--) {
        swap(&A[0], &A[i]);
        heapify(A, 0, i);
    }
}

void buildMaxheap(int *A, int n) {
    for(int i = n/2-1; i>=0; i--) {
        heapify(A, i, n);
    }
}

void heapify(int *A, int i, int n) {
    int l = 2*i+1, r = l+1, max;

    if(l < n && A[l] > A[i]) max = l;
    else max = i;

    if(r < n && A[r] > A[max]) max = r;
    
    if(max != i) {
        swap(&A[max], &A[i]);
        heapify(A, max, n);
    }
}