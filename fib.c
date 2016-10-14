#include<stdio.h>
void fib(int n)
{
	int a=0,b=1,c=0,i;
	printf("%d \t %d \t",a,b);
	for(i=1;i<n;i++)
	{
		c=a+b;
		printf("%d \t",c);
		a=b;
		b=c;
	}
	printf("\n");
}
void main()
{
	int n;
	printf("Enter the number of fibanocci numbers required \n");
	scanf("%d",&n);
	fib(n);
}
