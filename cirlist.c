
#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int key;
	struct node *next, *prev;
 }NODE;

NODE *head = NULL;
NODE *temp = NULL;
NODE *test = NULL;

void INSERTAFTER(NODE *ptr){
	int it;
	printf("\nEnter the  number:");
	scanf("%d",&it);
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new -> key = it;
	new -> next = head;
	if (head == NULL){
		head = new;
		new -> prev = NULL;
		new -> next = head;
	}
	else{
		new -> next = ptr->next;	
		ptr -> next = new;
		new -> prev = ptr;
	}
 }

void INSERTBEFORE(NODE *ptr){
	int it;
	printf("Enter the Number: ");
	scanf("%d",&it);
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new -> prev = NULL;
	new -> key = it;
	new -> prev = ptr -> prev;
	ptr -> prev = new;
	new -> next = ptr;
 }

void DELPTR(NODE *ptr){
	(ptr->next) -> prev = ptr -> prev;
	(ptr->prev) -> next = ptr -> next;
	free(ptr);
 
}


void DELKEY(){
	int skey;
	printf("Enter Key to be deleted");
	scanf("%d",&skey);
	temp = head;
	while(temp->next != head){
		if(temp->key = skey){
			(temp->next) -> prev = temp -> prev;
			(temp->prev) -> next = temp -> next;
			free(temp);
		}
	temp = temp->next;
	}
	if(temp->key = skey){
			(temp->next) -> prev = temp -> prev;
			(temp->prev) -> next = temp -> next;
			free(temp);
	}
 }


void DISPLAY(){
	temp = head;
	while(temp->next != head){
		printf("%d",temp->key);
		temp = temp->next;}
	printf("\n%d\n",temp->key);
 }

void main(){ 
	int ch,opt;
	while(ch!=0){
		printf("1.InsertAfter 2.InsertBefore 3.DeleteByPtr 4.DeleteByKey 5.Display: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:{INSERTAFTER(head);break;}
			case 2:{test = (head->next)->next;INSERTBEFORE(test);break;}
			case 3:{DELPTR(head);break;}
			case 4:{DELKEY();break;}
			case 5:{DISPLAY();break;}
		}
	printf("Press 0 to exit 1 to continue");
	scanf("%d",&ch);
 	}		

 }

