#include<stdio.h>
#define COMP(a,b) a==b? printf("Equal \n"): printf("Not equal \n")
void main()
{
	int a,b;
	printf("Enter 2 numbers \n");
	scanf("%d %d",&a,&b);
	COMP(a,b);
}
