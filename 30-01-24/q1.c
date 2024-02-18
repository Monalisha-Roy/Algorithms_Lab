#include<stdio.h>

void main() {
    int ans, lb=1, ub=100, mid, key, flag, count = 0;
    printf("Guess a number!\n");
    
    while(lb <= ub) {
        mid = (lb + ub)/2;
        count++;
        printf("%d, (1. Too low; 2. Too High; 3. Correct): ", mid);
        scanf("%d", &flag);
        if(flag == 1) lb = mid+1;
        else if(flag == 2) ub = mid -1 ;
        else {printf("Congratulations!, number found in %d steps", count); break;};
    }
}