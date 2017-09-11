#include<stdio.h>

struct cars
 {
	char model[20];
	char manufact[30];
	int year;
	int dim[3];
 }c[3];							//global array of type cars

int v[3];						//global variable array for  volume

void compare(struct cars *p){				//function for comparison
	int i,pos,t=0,big=0;
	for(i=0;i<3;i++)				//find volume
	 {
		t  = ((*(p+i)).dim[0])*((*(p+i)).dim[1])*((*(p+i)).dim[2]);
		v[i]=t;					//store volume in array
	 }
	for(i=0;i<3;i++)
	 {
		if(v[i]>big)				//find largest volume
		 {
			big = v[i];
			pos = i;
		 }
	}
	display(pos);					//call display
 }

void display(int i){					//display details
	printf("Details of car with largest volume");
	printf("\nModel:%s",c[i].model);
	printf("\nYear:%d",c[i].year);
	printf("\nManufacturer:%s",c[i].manufact);
	printf("\nVolume:%d\n",v[i]);
 }

void main(){
	int i,j;
	for(i=0;i<3;i++)
	 {
		printf("Enter Details of car %d\n",(i+1));
		printf("Model:");scanf("%s",&c[i].model);
		printf("Year:");scanf("%d",&c[i].year);
		printf("Manufacturer:");scanf("%s",&c[i].manufact);
		printf("Dimensions:");
		for(j=0;j<3;j++)
		 scanf("%d",&c[i].dim[j]);
			
	 }
	compare(&c);					//function call			
 }







