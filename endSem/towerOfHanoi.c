#include<stdio.h>
int count=0;
void toH(char a, char b, char c, int n);

void main() {
    printf("Enter the number of disks: ");
    int n;
    scanf("%d", &n);

    toH('S', 'A', 'D', n);
    printf("Number of steps: %d\n", count);
}

void toH(char s, char a, char d, int n) {
    count++;
    if(n == 1) printf("Move one disk from %c to %c\n", s, d);
    else{
        toH(s, d, a, n-1);
        printf("Move one disk from %c to %c\n", s, d);
        toH(a, s, d, n-1);
    }
}