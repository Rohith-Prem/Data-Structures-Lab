#include<stdio.h>
#include<string.h>
void split(char a[], char b[])				//function when strings are equal
 {
	int n,i=0,j;	
	n = strlen(a);
	j = n-1;
	char c[n/2];
	while(i<(2*n))
	 {
		if(i==n/2)
		 {
			strcat(c,b);
			i=i+n;
		 }
		else
		 {
			c[i]=a[j];
			i++;j--;
		 }
	 }
	c[i]='\0';
	printf("%s\n",c);
 }

void add(char a[], char b[])			//when strings are not equal
 {
	int n,m;
	n = strlen(a);
	m = strlen(b);
	if(n>m)
	 {
		strcat(b,a);
		printf("\n%s\n",b);
	 }
	else if(m>n)
	 {
		strcat(a,b);
		printf("\n%s\n",a);
	 }
	else
	 {
		strcat(a,b);		
		printf("%s\n",a);
	 }	

 }

void main()
 {
	char a[20],b[20];
	printf("Enter first string");
	scanf("%s",a);
	printf("Enter second string");
	scanf("%s",b);
	if(strcmp(a,b))					//check if strings are equal
		add(a,b);
	else
		split(a,b);
 }
