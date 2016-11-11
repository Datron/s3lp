#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int create(int);
void linearProb(int [],int,int);
void display(int[]);
void main()
{
	int a[MAX],num,key,i;
	int ans=1;
	printf("Collision handling linear probing \n");
	for(i=0;i<MAX;i++)
		a[i]=-1;
	do
	{
		printf("Enter the data \n");
		scanf("%d",&num);
		key=create(num);
		linearProb(a,key,num);
		printf("Do you want to continue? (1/0)\n");
		scanf("%d",&ans);
	}
	while(ans);
	display(a);
}

int create(int num)
{
	int key=num%MAX;
	return key;
}

void linearProb(int a[MAX],int key,int num)
{
	int flag,i,count=0;
	flag=0;
	if(a[key]==-1)
		a[key]=num;
	else
	{
		printf("Collision Detected.....\n");
		for(i=0;i<MAX;i++)
			if(a[i]!=-1)
				count++;
		printf("Collision avoided successfully\n");
		if(count == MAX)
		{
			printf("Hash table is full \n");
			display(0);
			exit(1);
		}
		for(i=key+1;i<MAX;i++)
			if(a[i]!=-1)
			{
				a[i]=num;
				flag=1;
				break;
			}
		for(i=0;i<key && flag==0;i++)
		{
			if(a[i]==-1)
			{
				a[i]=num;
				flag=1;
				break;
			}
		}
	}
}

void display(int a[MAX])
{
	int i,choice;
	printf("\n1.Display ALL \n2.Filtered Display \n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("the HASH TABLE is \n");
		for(i=0;i<MAX;i++)
			printf("\n%d %d \n",i,a[i]);
	}
	else {
	printf("\n HASH TABLE is \n");
	for(i=0;i<MAX;i++)
		if(a[i]!=-1)
		{
			printf("\n%d %d",i,a[i]);
			continue;
		}
	}
}
