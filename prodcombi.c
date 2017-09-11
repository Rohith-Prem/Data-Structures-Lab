/*function to store all combination of size r*/
#include <stdio.h>
void combinationUtil(int arr[], int data[], int start, int end, 
                     int index, int r,int val);
 
/*The main function that prints all combinations of size r
void printCombination(int arr[], int p, int r, int val)
{
	int data[r];
    	combinationUtil(arr, data, 0, p-1, 0, r, val);
}*/

int k=0; 
void combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r, int val)
{
    	if (index == r)
    	{	int a=1;
        	for (int j=0; j<r; j++)
            	a*=data[j];
		if(a==val)
		k=k+1;
	        return ;
	}
 
    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    	for (int i=start; i<=end && end-i+1 >= r-index; i++)
    	{
        	data[index] = arr[i];
	        combinationUtil(arr, data, i+1, end, index+1, r, val);
    	}
}

 
int main()
{
	int i,p,n,arr[10000],r;
	printf("Enter a Number and number of elementsin subset : ");
	scanf("%d%d",&n,&r);
	p=0;	
	for(i=1;i<=n;i++)
	if(n%i==0)
	arr[p++]=i;	
		
    	printCombination(arr, p, r, n);
	printf("Number of ways : %d",k);
	printf("\n");
	return 0;
}
