#include<stdio.h>

int gcd(int a,int b)		
 {
	if (b==0)
	 return a;
	else
	 return gcd(b,a%b);
 }

void main()
 {
	int a,b,hcf;
	printf("Entert two Numbers");
	scanf("%d %d",&a,&b);
	hcf=gcd(a,b);	
	printf("GCD of %d and %d = %d\n",a,b,hcf);
 }
