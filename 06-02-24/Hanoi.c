#include<stdio.h>
int c = 0;
void ToHanoi(int n, char s, char a, char d);

void main() {
    int n;
    printf("Enter the no. of disks: ");
    scanf("%d", &n);
    
    ToHanoi(n, 'S', 'A', 'D'); 

    printf("Total number of moves: %d\n", c);
}

void ToHanoi(int n, char s, char a, char d) {
    c++;
    if (n==1) {
        printf("Move one disk from %c to %c\n", s, d);
        
    }
    else {
        ToHanoi(n-1, s, d, a);
        printf("Move one disk from %c to %c\n", s, d);
        ToHanoi(n-1, a, s, d);
    }
}