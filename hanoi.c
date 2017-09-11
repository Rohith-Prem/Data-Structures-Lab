#include<stdio.h>


void Hanoi(int n, char from_rod, char to_rod, char int_rod){
    if (n == 1){
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    Hanoi(n-1, from_rod, int_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    Hanoi(n-1, int_rod, to_rod, from_rod);
}

void main(){
 Hanoi(6,'A','C','B');
}
