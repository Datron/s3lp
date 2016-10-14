#include<stdio.h>
int gcd(int m, int n);
void main()
{
	int m,n,res;
	printf("Enter values of m and n\n");
	scanf("%d%d",&m,&n);
	res = gcd(m,n);
	printf("GCD = %d \n",res);
}
int gcd(int m, int n)
{
	if(n == 0)
		return m;
	else if(m > n)
		 return gcd(n,m%n);
	else 
		 return gcd(m,m%n);
}

