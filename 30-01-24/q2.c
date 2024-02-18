#include<stdio.h>

void main() {
    int A[100], n, i, flag=0, a,key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements: ",n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &A[i]);
    }
    label:
    printf("Enter the value you want to search: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++) {
        if(A[i] == key) {
            flag = 1;
            a = i;
            break;
        }
    }
    if(flag == 1) printf("Yes!, element found at position %d\n", a);
    else printf("No!, element not found in array\n");
    printf("Do you want to search again?(1/0): ");
    int ans;
    scanf("%d", &ans);
    if(ans == 1) goto label;
}