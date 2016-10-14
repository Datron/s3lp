#include<stdio.h>
#define MAX 30
void create(int a[],int n)
{
	int i;
	printf("Enter the elements \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}

void insert(int a[],int *n,int pos,int elem)
{
	int i;
	if(*n==0)
	{
		printf("Array is empty.Can not insert \n");
		return;
	}
	if(pos<0 || pos>*n-1)
	{
		printf("Invalid position \n");
		return;
	}
	for(i=*n-1;i>=pos;i--)
	{
		a[i+1]=a[i];
		a[pos]=elem;
		(*n)++;
	}
}
void del(int a[],int *n,int pos)
{
	int i;
	if(n==0)
	{
		printf("Array is empty \n");
		return;
	}
	if(pos < 0 || pos > *n-1)
	{
		printf("Invalid position \n");
		return;
	}
	for(i=pos;i < *n;i++)
	{
		a[i]=a[i+1];
		(*n)--;
	}	
}
void display(int a[],int n)
{
	int i;
	if(n==0)
	{
		printf("Array is empty \n");
		return;
	}
	printf("Array elements \n");
	for(i=0;i<n;i++)
	{
		printf("%d \n",a[i]);
	}
	printf("\n");
}
void main()
{
	int n=0,pos,e,choice,done,i;
	int a[MAX];
	done=0;
	while(!done)
	{
		printf("Array  operations: \n 1.Create \n 2.Insert \n 3.Delete \n 4.Display \n 5.Exit \n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the number of data elements \n");
				scanf("%d",&n);
				create(a,n);
				break;
			
			case 2: printf("Enter the position \n");
				scanf("%d",&pos);
				printf("Enter the data elements to be inserted \n");
				scanf("%d",&e);
				insert(a,&n,pos,e);
				break;
				
			case 3:printf("Enter the position for deletion \n");
				scanf("%d",&pos);
				del(a,&n,pos);
				break;
				
			case 4: display(a,n);
				break;
				
			case 5: done = 1;
				break;
				
			default: printf("Invalid choice \n");
				break;
		}
	}
}
