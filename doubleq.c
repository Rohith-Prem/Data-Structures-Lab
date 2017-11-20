#include<stdio.h>
#include<stdlib.h>
int q[100];
int f=-1;
int r=-1;

void display(){
	int i;
	printf("Queue: ");
	for (i=f;i<=r;i++)
		printf("%d ",q[i]);
	printf("\n");
}

void insert_r(int x,int n){
 if(f==(r+1)%n)
 {
   printf("\nQueue Overflow");
 }
 else if(r==-1)
 {
   f=0;
   r=0;
   q[r]=x;
 }
 else
 {
    r=(r+1)%n;
    q[r]=x;
 }
display();
}


void insert_f(int x,int n){
  if(f==(r+1)%n)
  {
    printf("\nQueue Overflow");
  }
  else if(r==-1)
  {
     f=0;
     r=0;
     q[r]=x;
  }
  else
  {
     f=(f+n-1)%n;
     q[f]=x;
  }
display();
}


int del_r(int n){
 int x;
  if(f==-1){
	printf("\nQueue Underflow");
	}
  else if(f==r){
	x=q[f];
	f=-1;
	r=-1;
	}
  else{
	x=q[r];
	r=(r+n-1)%n;
	}
  return x;
}

int del_f(int n){
	int x;
 	if(f==-1){
		printf("\nQueue Underflow"); 
	}
	else if(f==r)
	{
		x=q[f];
		f=-1;
		r=-1;
	}
        else
	{
 		x=q[f];
		f=(f+1)%n;
	}
	return x;
}

void main()
{ 	
	int n,x,ch,cont=1;
	printf("\nEnter the size of the array:");
        scanf("%d",&n);
        while(cont==1)
        { 
                printf("1.Insert front\n");
                printf("2.Insert rear\n");
                printf("3.Delete front\n");
                printf("4.Delete rear\n");
                printf("\nEnter your choice:");
                scanf("%d",&ch);
                
                switch(ch)
                {
                        case 1:{printf("\nEnter the element:");
                               scanf("%d",&x);
                               insert_f(x,n);
                               break;}
                        case 2:{printf("\nEnter the element:");
                               scanf("%d",&x);
                               insert_r(x,n);
                               break;}
                        case 3:{printf("\nDeleted %d from front\n",del_f(n));display();
                               break;}
                        case 4:{printf("\nDeleted %d from rear\n",del_r(n));display();
                               break;}
                               
                }    
		printf("Do you wish to continue(1/0)");scanf("%d",&cont);         
        }                                                                  
}      
 
 
 
 
 
 
 
 
 
 
 
 
 
