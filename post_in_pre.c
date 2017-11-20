#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//Evaluating Post-Fix,in-fix,pre-fix expressions
typedef struct  node
{
	char op;
	struct node *next;
	struct node *prev;
	
	
}node;
char stack[20],stack_string[20][20];
node *head,*tail;

int top=-1,top2=-1;
void push_string(char op[20]){	//store strings to stack
	top2++;
	if(top2==20)
		{
			printf("\noverflow");
			top2--;}
	else{
			strcpy(stack_string[top2],op);

	}
}
void pop_string(char r[20]){		//pop strings from stack
	if(top2==-1)
		printf("\n underflow");
	else{
		strcpy(r,stack_string[top2]);
		top2--;
	}
}

void append(char op){		//append to list
	node *temp;
	temp=(node*)malloc(sizeof(node));
	if(temp){

		temp->op=op;
		if(head){
			tail->next=temp;
			temp->prev=tail;
			tail=temp;
		}
		else
			tail=head=temp;
		tail->next=NULL;
	}
	else
		{	printf("\noverflow");
			exit(0);
		}
}
void display(){			//display list
	node *curr;
	curr=head;
	while(curr){
		printf("%c",curr->op );
		curr=curr->next;
	}
	printf("\n");
}




void push(char oper){		//push to stack
	top++;
	if(top==20){
			top--;
			printf("\n overflow");
		}
	else{
			stack[top]=oper;
	}
}
char pop(){			//pop from stack
	char x;
	if(top==-1){
			printf("\n overflow");
			return '\0';
		}
	else{
		x=stack[top];
		top--;
		return x;
		
	}
}

void freeall(){			//free nodes in list
	node *curr,*temp;
	curr=head;
	while(curr){
		temp=curr;
		curr=curr->next;
		free(temp);

	}
	head=NULL;
	tail=NULL;
}

void strrev(char rev[20],char expr[20]){	//to reverse string
	int i,j;
	for(i=0,j=strlen(expr)-1;j>=0;i++,j--)
			rev[i]=expr[j];
	rev[i]='\0';
}

/******postfix to infix*****/
void post_in(char expr[20]){
	int i;char pp[2];
	char r1[20],r2[20];
	for(i=0;i<strlen(expr);i++){
		pp[0]=expr[i];
			pp[1]='\0';
		if(isalpha(expr[i])){
			push_string(pp);
		}
		else{
			pop_string(r1);pop_string(r2);
			strcat(r2,pp);
			strcat(r2,r1);
			push_string(r2);

		}
	}
	
}

/*******infix to postfix****/
void in_post(char expr[20]){
	int i;
	char r;
	for(i=0;i<strlen(expr);i++){

		if(!isalpha(expr[i])){

			if(expr[i]=='('){
				push(expr[i]);

			}
			if(expr[i]==')'){
				while(stack[top]!='('){
					r=pop();
					append(r);

				}
				r=pop();
			}
			if(expr[i]=='-'){
				if(top!=-1&&(stack[top]=='-'||stack[top]=='+'||stack[top]=='*'||stack[top]=='/')){
					r=pop();
					append(r);
					
				}
				push(expr[i]);

			}
			if(expr[i]=='+'){
				
				if(top!=-1&&(stack[top]=='+'||stack[top]=='*'||stack[top]=='/')){
					r=pop();
					append(r);
				}
				push(expr[i]);
			}
			if(expr[i]=='*'){
				if(top!=-1&&(stack[top]=='*'||stack[top]=='/')){
					r=pop();
					append(r);

				}
				push(expr[i]);
			}
			
			if(expr[i]=='/'){
				if(top!=-1&&(stack[top]=='/')){
					r=pop();
					append(r);
				}
				push(expr[i]);
			}


		}
		else
			append(expr[i]);
				
			
	}
	
	while(top!=-1){
			r=pop();
			append(r);
	 }
	
	
	printf("\n");
}

/******infix to prefix******/
void in_pre(char expr[20]){
	char rev[20],temp;
	int i;
	strrev(rev,expr);
	
	for(i=0;i<strlen(rev);i++){
		if(rev[i]=='(')
			rev[i]=')';
		else if(rev[i]==')')
			rev[i]='(';
	}
	in_post(rev);
	node *curr1,*curr2;
	
	curr1=head;
	curr2=tail;
	
	
	while(curr1!=curr2){
		temp=curr1->op;
		curr1->op=curr2->op;
		curr2->op=temp;
		curr2=curr2->prev;
		curr1=curr1->next;
	}

	curr1=head;
}

/*******PREFIX TO INFIX******/
void pre_in(char expr[20]){
	char rev[20];
	strrev(rev,expr);
	post_in(rev);
	strrev(rev,stack_string[top2]);
	printf("%s",rev);
	
}

void main(){
	char expr[20];
	int ch;
	
	do{
		printf("\n1.infix to postfix\n2.postfix to infix\n3.infix to prefix\n4.prefix to infix\n5.exit\nenter your choice:");
		scanf("%d",&ch);
		
		if(ch==1){
			printf("\nenter an expression:");
			scanf("%s",expr);
			in_post(expr);
			printf("\npostfix expression: ");
			display();
			freeall();
			top=-1;
			
		}
		else if(ch==2){
			printf("\nenter an expression:");
			scanf("%s",expr);
			post_in(expr);
			printf("\ninfix expression:%s",stack_string[top2]);
			top2=-1;
		}
		else if(ch==3){
			printf("\nenter an expression:");
			scanf("%s",expr);
			in_pre(expr);
			printf("\nprefix expression: ");
			display();
			freeall();
			
			
		}
		else if(ch==4){
			printf("\nenter an expression:");
			scanf("%s",expr);
			printf("\ninfix expression: ");
			pre_in(expr);
			top2=-1;
		}
		else
			;
	}while(ch!=5);
}
