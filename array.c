#include<stdio.h>
#define MAX 30
void create(int [],int);
void insert(int [],int *,int,int);
void del(int [],int *,int);
void display(int [],int);
void main()
{
	int n,choice,done=0,e,pos;
	int a[MAX];
	while(!done)
	{
		printf("Array operations \n 1.Create \t 2.Insert \t 3.Delete \t 4.Display \t 5.Exit \n");
		printf("Enter your choice \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the number of elements \n");
				scanf("%d",&n);
				create(a,n);
				break;

			case 2:printf("Enter the position \n");
				scanf("%d",&pos);
				printf("Enter the element  \n");
				scanf("%d",&e);
				insert(a, &n, pos, e);
				break;

			case 3:printf("Enter the position \n");
				scanf("%d",&pos);
				del(a,&n,pos);
				break;

			case 4:display(a,n);
				break;

			case 5: done=1;
				break;

			default:printf("Invalid option \n");
				break;
		}
	}
}
void create(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the element \n");
		scanf("%d", &a[i]);
	}
}
void insert(int a[],int *n,int pos,int e)
{
	int i;
	if(*n==0)
	{
		printf("Array has not been created \n");
		return;
	}
	 if(pos < 0 || pos > *n-1)
		{
		printf("Insertion at this position not possible\n");
		return;
		}
		for(i=*n-1;i>=pos;i--)
		{
			a[i+1]=a[i];
		}
		 	a[pos]=e;
			(*n)++;
}
void del(int a[],int *n,int pos)
{
	int i;
	if(*n==0)
	{
		printf("Array is empty \n");
		return;
	}
	 if(pos<0 || pos > *n-1)
	{
	printf("Invalid position \n");
	return;
	}
	for(i=pos;i<*n;i++)
		{
		a[i]=a[i+1];
		}
		(*n)--;
	}
void display(int a[],int n)
{
	int i;
	if(n==0)
	{
		printf("Array empty \n");
	}
	else {
	printf("Array elements \n");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
	printf("\n");
	}
}
