#include<stdio.h>
#include<stblib.h>


typedef struct node{
	int key;
	struct node *next, *prev;
 }NODE;

NODE *head = NULL;
NODE *temp,*search;

void INSERTAFTER(int it,NODE *ptr){
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new -> key = it;
	if (head ==NULL){
		head = new;
		new -> next = NULL;
		new -> prev = NULL;
	}
	else{
		new -> next = ptr->next;	
		ptr -> next = new;
		new -> prev = ptr;
	}
 }

void INSERTBEFORE(int it, NODE *ptr){
	NODE *new = (NODE *)malloc(sizeof(NODE));
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


void DELKEY(int key){






	
		
