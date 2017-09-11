#include<stdio.h>
#include<stdlib.h>

void reverse(int *a,int n) 
 {
	int i=0,j=n-1,temp;
	while(j>=n/2)
		{
			temp = *(a+j);
			*(a+j) = *(a+i);
			*(a+i) = temp;
			i++;j--;		
		}
	 display(a,n);
 }

void display(int *a,int n)
 {
	int i=0;
	printf("\nThe array after reversal:\n");
	while(i<n)
	 {
		printf("%d\n",*(a+i));
		i++;
	 }
 }

void main()
 {
	int n, *a,i;
	printf("Enter the Array Size");
	scanf("%d",&n);
	a = (int *)malloc(n*sizeof(int));
	printf("\nEnter The Array Elements");
	for(i=0;i<n;i++)
	 scanf("%d",&a[i]);
	reverse(a,n);
 }
	
