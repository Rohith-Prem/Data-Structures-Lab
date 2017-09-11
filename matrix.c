#include<stdio.h>
#include<stdlib.h>

void INPUT(int mat[100][100],int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		  scanf("%d",&mat[i][j]);
		 }
	 }
	DISPLAY(mat,m,n); 
}

void EXCHANGE(int mat[100][100],int m,int n){
	int i,j,temp;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		  if(i==j){
			temp = mat[i][j];
			mat[i][j] = mat[i][m-i-1];
			mat[i][m-i-1] = temp;
		    }
		 }
	 }
	DISPLAY(mat,m,n);
}
	

void SWAP(int mat[100][100],int n,int r_a,int r_b){
	int i,temp;
	for(int i=0;i<n;i++){
		int temp = mat[r_a][i];
		mat[r_a][i] = mat[r_b][i];
		mat[r_b][i] = temp;
	 }
 }

void DISPLAY(int mat[100][100],int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		  printf("%d\t",mat[i][j]);
		 }
		printf("\n");
	 }
 }
	

int RANK(int mat[100][100],int m,int n){
	int rank,r,c,i;bool f;
	rank = n;
	for(r=0;r<rank;r++){
		if(mat[r][r]){
		  for(c=0;c<m;c++){
			if(c!=r){
			  float t = (float) (mat[c][r]/mat[r][r]);
			  for(i=0;i<rank;i++)		
				mat[c][i] -= t * mat[r][i];
			}
		  }
		} 
		else{
	          bool f =true;
		  for (i=r+1;i<m;i++){
                	   if (mat[i][r]){
                    		SWAP(mat,r,i,rank);
                    		f=false ;
                    		break ;
               		   }
           	  }
		}
		
            if (f){
                rank--;
                for (i=0; i<m;i++){
                    mat[i][r] = mat[i][rank];}
            }
	r--;
	}
	return rank;
 }



void main(){

int mat[100][100],m,n;
int ch,c=1;
printf("Enter number of rows");
scanf("%d",&m);
printf("enter the number of columns");
scanf("%d",&n);
if(m!=n){
	printf("Invalid Matrix..Operations not Possible...exiting...");
	exit(0);
 }
printf("Enter The Matrix Elements");
INPUT(mat,m,n);
while(c==1){
	printf("1.Swap Diagonals 2.Determinant 3.Rank");
	printf("\nEnter your Choice(1-3)");
	scanf("%d",&ch);
	switch(ch){
		case 1: {EXCHANGE(mat,m,n);break;}
		case 2: {break;}
		case 3: {printf("\nRank of The matrix is:%d",RANK(mat,m,n));break;}
		default: {printf("\nInvalid Choice");}
 	 }
	printf("\nDo you wish to continue(1/0)");
	scanf("%d",&c);
 }
}

















