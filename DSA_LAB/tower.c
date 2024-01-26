#include<stdio.h>
static int count;
void towerofhanoi(int n, char source, char destination, char inter) {
    if (n == 0) {
        printf("invalid \n");
        return;
    }
    if (n == 1) {
        printf("move disk %d from %c to %c\n ", n, source, destination);
        count++;
    } else {
        towerofhanoi(n - 1, source, inter, destination);
        printf("move disk %d from %c to %c \n ", n, source, destination);
        count++;
        towerofhanoi(n - 1, inter, destination, source);
    }
}
int main() {
    int n;
    printf("enter the number of disks: ");
    scanf("%d", &n);
    count = 0;            // Reset count for each call to towerofhanoi
    towerofhanoi(n, 'A', 'C', 'B');
    printf("no of counts %d\n", count);
    return 0;
}
