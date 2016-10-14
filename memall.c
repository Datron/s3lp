#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,n)\
	if( (p=malloc(n)) == NULL){ \
		printf("Insufficient Memory \n"); \
		exit(0); \
		}

void main()
{
	int *ptr,n,i,j;
	printf("Enter the number of elements \n");
	scanf("%d",&n);
	MALLOC(ptr,n*sizeof(int));
	printf("Enter the elements \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&*(ptr+i));
	}
	printf("Entered elements are \n");
	for(i=0;i<n;i++)
	{
		printf("%d \n",*(ptr+i));
	}
}
