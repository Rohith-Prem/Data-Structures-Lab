/***********Find longest increasing or decreasing array*********/
#include<stdio.h>

void DISPLAY(int a[],int n){
	int i;
	printf("\nLongest increasing or decreasing sequence is:");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void FIND_SEQ(int a[][10],int m,int n){
	int i,j,t,k=0,no,arr[100],inc=0,incr[20],incr1[20],dec=0,decr[20],decr1[20];
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			arr[k]=a[i][j];
			k++;
		}
	
	no=k+1;
	//for increasing
	for(j=0;j<no-1;j++){
		k=0;i=j;
		while(arr[i]<arr[i+1]&&i<m*n){
			incr[k]=arr[i];
			i++;
			k++;
		}	
		incr[k]=arr[i];
		if(k+1>inc){
			for(t=0;t<k+2;t++)
				incr1[t]=incr[t];
			inc=k+1;
		
		}
	}

	//for decreasing
	for(j=0;j<no-1;j++){
		k=0;i=j;
		while(arr[i]>arr[i+1]&&i<m*n){
			decr[k]=arr[i];
			i++;
			k++;
		}
		decr[k]=arr[i];
		
		if(k+1>dec){
			for(t=0;t<k+2;t++)
				decr1[t]=decr[t];
			dec=k+1;
		}
	}

	if(inc>dec)	
		DISPLAY(incr1,inc);
	else
		DISPLAY(decr1,dec);
}

	

	
void main(){
	int set[10][10],i,m,j,n;
	printf("\nEnter order of matrix:");
	scanf("%d%d",&m,&n);
	printf("\nEnter elements:");
	for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
	   scanf("%d",&set[i][j]);
	FIND_SEQ(set,m,n);
}

