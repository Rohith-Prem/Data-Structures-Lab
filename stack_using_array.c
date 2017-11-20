/***********Stack using array and linked list to implement linkpush and linkpop***********/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int key;
	struct node* next;
	}node;
node *TOP;

int stack[100];
int top=-1;
void displaylist(){
	node *curr;
	curr=TOP;
	printf("\n list stack:");
	while(curr){
		printf("\n %d",curr->key);
		curr=curr->next;
	}
}

void displaystack(){
	int curr=top;
	printf("\n array stack:");
	while(curr!=-1){
		printf("\n %d",stack[curr]);
		curr--;
	}
}

void PUSH_STACK(int a[],int value){
	top++;
	if(top>=100){	
		printf("\n Overflow");top--;
	}
	else{
		a[top]=value;
	}
	displaystack();
}

void POP_STACK(int a[]){
	if(top==-1)
		printf("\n Underflow"); 
	else{	
		printf("\npoped: %d",a[top]);
		top--;
	}
	displaystack();
}

void PUSH_LIST(int key){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	if(temp){
		temp->key=key;
		if(TOP){
			temp->next=TOP;
			TOP=temp;
		}
		else
			TOP=temp;
	}
	else
		printf("\n Overflow");
	displaylist();
}

void  POP_LIST(){
	node *temp;
	if(TOP){
		temp=TOP;
		TOP=TOP->next;
		printf("\npoped: %d",temp->key);
		free(temp);
     	}
	else{
		printf("\n Underflow");
	}
	displaylist();		
		
}

void LINKPUSH(int k){
	node *temp;
	int i;
	for(i=0;i<k;i++){
		temp=(node *)malloc(sizeof(node));
		if(temp){
			if(top!=-1){
				temp->key=stack[top];
				top--;
				if(TOP){
					temp->next=TOP;
					TOP=temp;
				}	
				else
					TOP=temp;

			}
			else
				printf("\nunderflow");
		}
		else
			printf("\noverflow");
	}
	displaylist();
	displaystack();
}
void LINKPOP(int k){
	node *temp;
	int i;
	for(i=0;i<k;i++){
		if(TOP){
			temp=TOP;
			top++;
			if(top>=100){
				printf("\noverflow");
				top--;
			}
			else{
				stack[top]=TOP->key;
				TOP=TOP->next;
				free(temp);
			}
		}
		else
			printf("\nUnderflow");
	}
	displaylist();
	displaystack();
}
			
	
		
void main(){
	int ch,value;
	do{
		printf("\n1.Push to linked Stack\n2.Push to Array Stack\n3.Linkpush\n4.Linkpop\n5.Exit\nEnter choice:");
		scanf("%d",&ch);
		if(ch==1){
			printf("\nEnter element:");
			scanf("%d",&value);
			PUSH_LIST(value);
		}
		else if(ch==2){
			printf("\nEnter element:");
			scanf("%d",&value);
			PUSH_STACK(stack,value);
		}
		else if(ch==3){
			POP_LIST();
		}
		else if(ch==4)
			POP_STACK(stack);
		else if(ch==5){
			printf("\nEnter no of elements to linkpush:");
			scanf("%d",&value);
			LINKPUSH(value);
		}
		else if(ch==6){
			printf("\nEnter no of elements to linkpop:");
			scanf("%d",&value);
			LINKPOP(value);
		}
		else;
	}while(ch!=7);
}
	



	

