#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s) \
	if(!(p=malloc(s))){\
	fprintf(stderr,"Insufficient memory \n");\
	exit(0); \
	}
#define REALLOC(p,n,type)\
	if(!(p = (type *)realloc(p,n))) { \
		printf("Insufficient memory \n");\
		exit(0);\
		}
int ssize = 1;
void push(char *,int,int);
char pop(char *,int,int);
void main()
{
	int choice,done=0,top=-1;
	char *a,pe,e;
	MALLOC(a,sizeof(int));
	while(!done)
	{
	printf("\n Stack operations: \n 1.Push \n 2.Pop \n 3.Display 4.Exit \n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("Enter elements \n");
			scanf("%d",&e);
			push(*a,&top,e);
			break;
			
		case 2: pe = pop(*a,&top);
			if(pe == -1)
				printf("Stack Underflow \n");
			else
				printf("Popped element is %d \n",pc);
			break;
				
		case 3: if(top == -1)
				printf("Empty stack \n");
			else
			{
			for(i=top;i>=0;i--)
				printf("%d \n",*(a+i));
			}
			break;
		case 4: done = 1;
			break;
				
		default: printf("Enter a valid number \n");
			break;
		}
	}
}
char pop(char *s,int *top)
{
	(*top)--;
	return *(s+*top);
}
void push(char *sa,int *top,int s)
{
	if(*top == (ssize-1))
	{
		printf("Stack is full \n");
		printf("Increasing stack size \n");
		ssize++;
		REALLOC(*s,ssize,int);
	}
	*top = *top++;
	(*s)[*top]=s;
}
