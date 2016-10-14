#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s)\
	if(!(p=malloc(s))) { \
		printf("Insufficient memory \n");\
		exit(0);\
		}
#define REALLOC(p,s,type) \
	if(!(p=(type *)realloc(p,s))) {\
		printf("Insufficient memory \n");\
		exit(0); \
		}
int ssize=10;
void push(char **, int *, char);
char pop(char **,int *);
void main()
{
	char *s,e,pe;
	int top = -1,done=0,choice,i;
	MALLOC(s,ssize*sizeof(int));
	while(!done)
	{
		printf("Stack Operations \n 1.Push \n 2.Pop \n 3.Display \n 4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the element \n");
				scanf("%c",&e);
				push(*s,&top,e);
				break;
			case 2: pe = pop(*s,&top);
				if(pe == -1)
					printf("NULL\n");
				else 
					printf("%c \n",pe);
				break;
			case 3: if(top == -1)
					printf("Underflow \n");
				else {
					for(i=top;i>0;i--)
						printf("%d \n",*(s+i));
					}
				break;
			case 4: done =1;
				break;
		}
	}
}

void push(char **s,int *top, char e)
{
	if(*top == (ssize-1))
	{
		printf("Stack is full \n");
		printf("increasing stack size \n");
		ssize++;
		REALLOC(**s,ssize*sizeof(int),int);
	}
	(*top)++;
	*(s+*top)= e;
}
char pop(char **s, int *top)
{
	return *(s+*top);
	(*top)--;
}
