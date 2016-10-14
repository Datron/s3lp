#include<stdio.h>
void main()
{
	int a,b,temp=0;
	printf("Enter 2 numbers \n");
	scanf("%d %d",&a,&b);
	temp=a;
	a=b;
	b=temp;
	printf("the swapped numbers are: %d %d \n",a,b);
}
