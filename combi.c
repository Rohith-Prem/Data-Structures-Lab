//program to find the number of ways in which a number n can be expressed as the product of k distinct positive integers
/********ROHITH P*******/
#include <stdio.h>
//function to store all combinations in array find the product and check
int c=0;
int numofcomb(int arr[], int comb[], int start, int end,int index, int k, int n){
    	
	if (index == k)					//only when combination of k is obtained
    	 {	
		int pro=1;
        	for (int j=0; j<k; j++)
            	 pro*=comb[j];
		if(pro==n)				//check if product of combination is equal to the number
		 c++;
	 }
 
//all combinations of k numbers each
	int i;    	
	for (i=start; i<=end && end-i+1 >= k-index; i++)
    	 {
        	comb[index] = arr[i];
	        numofcomb(arr, comb, i+1, end, index+1, k, n);
    	 }
	return c;
 }

 
void main(){
	int i,p,n,arr[10000],k,count;
	printf("Enter value of n and k");
	scanf("%d%d",&n,&k);
	p=0;	
	for(i=1;i<=n;i++)			//to find all factors of n and store it in arr[]
	 if(n%i==0)
	  arr[p++]=i;			      
	int comb[k];				//array for factors as combination of k numbers

    	count = numofcomb(arr, comb, 0, p-1, 0, k, n);	//arguments(arr,data,starting index,size of arr,starting index,digits per combination,number)
	printf("f(n,k) = %d\n",count);
 }
