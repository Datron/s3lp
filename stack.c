#include<stdio.h>
#include<string.h>
#define MAX 30
void push(int [],int *,int);
int pop(int [],int *);
int palindrome(int [],int *,char []);
void main()
{
	int n,choice,done=0,e,pe,top=-1,flag,i;
	int item[MAX];
	char palin[MAX];
	while(!done)
	{
		printf("Stack operations \n 1.Push \t 2.Pop \t 3.display \t 4.Palindrome \t 5.Exit \n");
		printf("Enter your choice \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the element \n");
				scanf("%d",&e);
				push(item,&top,e);
				break;

			case 2:pe=pop(item,&top);
				if(pe==-1)
					printf("Stack Underflow \n");
				else
					printf("Popped element is %d\n",pe);
				break;

			case 3:if(top == -1)
					printf("Stack is empty\n");
					else
					{
					for(i=0;i<=top;i++)
						printf("%d\t",item[i]);
					}
					printf("\n");
				break;

			case 4:printf("Enter palindrome string \n");
					scanf("%s",palin);
					top=-1;
					flag=palindrome(item,&top,palin);
					if(flag==-1)
						printf("String is not a palindrome\n");

					else printf("String is a palindrome \n");
				break;

			case 5: done=1;
				break;

			default:printf("Invalid option \n");
				break;
		}
	}
}
int palindrome(int items[],int *top,char pal[])
{
	int i;
	for(i=0;i<strlen(pal);i++)
		push(items,top,pal[i]);
	for(i=0;i<strlen(pal);i++)
	{
		if(pal[i]!=pop(items,top))
			return -1;
	}
	return 1;
}
void push(int item[],int *top,int e)
{
	if(*top==MAX-1)
		printf("Stack overflow \n");
	else
	{
		item[++(*top)]=e;
	}
}
int pop(int item[],int *top)
{
	int temp;
	if(*top==-1)
	printf("Stack underflow \n");
	else
	{
	temp=item[(*top)--];
	}
	return temp;
}
