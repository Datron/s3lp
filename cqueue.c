#include<stdio.h>
#define MAX 4
void enqueue(char[],int *,int *,char);
char dequeue(char[],int *,int *);
void display(char[],int,int);
void main()
{
	char q[MAX];
	char e,temp;
	int choice, done,i;
	int f,r;
	f=r=0;
	done=0;
	while(!done)
	{
		printf("1.Insert 2.Delete 3.Display 4.Exit \n");
		printf("Enter choice \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter elements \n");
			scanf(" %c",&e);
			enqueue(q,&f,&r,e);
			break;

			case 2:
			temp=dequeue(q,&f,&r);
			if(temp == '#')
				printf("Queue underflow \n");
			else
				printf("Queue elements deleted are %c \n",temp);
			break;

			case 3:
			display(q,f,r);
			break;
			case 4:
			done = 1;
			break;
			default:
			printf("Illegal operation \n");
			break;
		}
	}
}
void enqueue(char q[],int *f,int *r,char e)
{
	if(*f ==((*r+1)%MAX))
		printf("Queue Overflow \n");
	else {
	*r = (*r+1)%MAX;
	q[*r]=e;
	}
}
char dequeue(char q[],int *f,int *r)
{
	char x;
	if(*f == *r)
		return '#';
	else {
	*f = (*f+1)%MAX;
	x = q[*f];
	}
	return x;
}
void display(char q[],int f,int r)
{
	int i=f;
	if(f==r)
		printf("Queue Overflow \n");
	else {
	while(i!=r)
	{
		i = (i+1)%MAX;
		printf("%c \t",q[i]);
	}
	printf("\n");
}
}
