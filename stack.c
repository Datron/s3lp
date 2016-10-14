#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
void push (int [],int *,int);
int pop(int [],int *);
int palindrome(int [],int *,char []);
void main()
{
	int items[MAX];
	char palster[MAX+1];
	int i,top,choice,done;
	int flag;
	int e,pc;
	top=-1;
	done=0;
	while(!done)
	{
		printf("\n Stack operations: \n 1.Push \n 2.Pop \n 3.Display \n 4.Palindrome \n 5.Exit \n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter elements \n");
				scanf("%d",&e);
				push(items,&top,e);
				break;
			
			case 2: pc = pop(items,&top);
				if(pc == -1)
					printf("Stack Underflow \n");
				else
					printf("Popped element is %d \n",pc);
				break;
				
			case 3: if(top == -1)
					printf("Empty stack \n");
				else
				{
					for(i=top;i>=0;i--)
						printf("%d \n",items[i]);
				}
				break;
				
			case 4: printf("enter palindrome string \n");
				scanf("%s",palster);
				top=-1;
				flag = palindrome(items,&top,palster);
				if(flag == -1)
					printf("Not a palindrome\n");
				else
					printf("Palindrome \n");
				top=-1;
				break;
				
			case 5: done = 1;
				break;
				
			default: printf("Enter a valid number \n");
				break;
		}
	}
}
int palindrome(int items[],int *top,char pal[])
{
	int i;
	for(i=0;i<strlen(pal);i++)
	{
		push(items,top,pal[i]);
	}
	for(i=0;i<strlen(pal);i++)
	{
		if(pal[i]!=pop(items,top))
			return -1;
	}
	return 1;
}

void push(int items[],int *top,int e)
{
	if(*top == MAX-1)
		printf("Stack Overflow \n");
	else
	{
		++(*top);
		items[*top]=e;
	}
}

int pop(int items[],int *top)
{
	int temp;
	if(*top == -1)
		return -1;
	else
	{
		temp = items[*top];
		(*top)--;
	}
	return temp;
}
