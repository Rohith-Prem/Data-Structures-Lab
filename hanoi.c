#include<stdio.h>

typedef struct stack{
	int ar[3];
	int top;
}STACK;



void Hanoi(int n, int from_rod, int to_rod, int int_rod){
    if (n == 1){
        //printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
	PUSH(from_rod,to_rod,2);
	DISPLAY();
        return;
    }
    Hanoi(n-1, from_rod, int_rod, to_rod);
    //printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    DISPLAY();
    PUSH(from_rod,to_rod,2);
    Hanoi(n-1, from_rod, int_rod, to_rod);
    Hanoi(n-1, int_rod, to_rod, from_rod);
    DISPLAY();
}

STACK A,B,C;
int i,j,k;

void PUSH(int from,int to){
	int disk;
	if(from == 1){
		disk = A.ar[A.top];
		A.top--;}
	else if(from == 2){
		disk = B.ar[B.top];
 		B.top--;}
	else if(from == 3){
		disk = C.ar[C.top];
		C.top--;}
	switch(to){
		case 1:{++A.top;
			A.ar[(A.top)] = disk;break;}
		case 2:{++B.top;
			B.ar[B.top] = disk;break;}
		case 3:{++C.top;
			C.ar[C.top] = disk;break;}
	}
		
}

void DISPLAY(){
	int p;
	printf("Rod A\n");
	for(p=A.top;p>=0;p--)
		printf("%d\n",A.ar[p]);
	printf("Rod B\n");
	for(p=B.top;p>=0;p--)
		printf("%d\n",B.ar[p]);
	printf("Rod C\n");
	for(p=C.top;p>=0;p--)
		printf("%d\n",C.ar[p]);
}
	
void main(){
 A.top = 2;
 B.top = 0;
 C.top = 0;
 A.ar[0] = 3;
 A.ar[1] = 2;
 A.ar[2] = 1;
 DISPLAY();
 Hanoi(3,1,3,2);
}







