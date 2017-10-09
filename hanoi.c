#include<stdio.h>

typedef struct stack{
	int ar[3];
	int top = 0;
}STACK;


void Hanoi(int n, int from_rod, int to_rod, int int_rod){
    if (n == 1){
        //printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
	PUSH(1,from_rod,to_rod,2);
	DISPLAY();
        return;
    }
    Hanoi(n-1, from_rod, int_rod, to_rod);
    //printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    PUSH(n,from_rod,to_rod,2);
    Hanoi(n-1, int_rod, to_rod, from_rod);
}

STACK A,B,C;
int i,j,k;

void PUSH(int disk,int from,int to){
	if(from == 1)
		A.top++;
	else if(from == 2)
 		B.top++;
	else if(from == 3)
		C.top++;
	switch(to){
		case 1:{--A.top;
			A.ar[(A.top)] = disk;break;}
		case 2:{--B.top;
			B.ar[B.top] = disk;break;}
		case 3:{--C.top;
			C.ar[C.top] = disk;break;}
		
}

void DISPLAY(){
	int p;
	printf("Rod A\n");
	for(p=A.top;p<3;p++)
		printf("%d\n",A.ar[p]);
	printf("Rod B\n");
	for(p=B.top;p<3;p++)
		printf("%d\n",B.ar[p]);
	printf("Rod C\n");
	for(p=C.top;p<3;p++)
		printf("%d\n",C.ar[p]);
}
	
void main(){
 Hanoi(3,'A','C','B');
}







