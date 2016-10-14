#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
void push(char[],int *,char);
char pop(char[],int *);
int ICP(char);
int ISP(char);
void infixpostfix(char[],char[]);
void main()
{
	char infix[MAX],postfix[MAX];
	printf("Enter infix expression \n");
	scanf("%s",infix);
	printf("Entered expression : %s \n",infix);
	infixpostfix(infix,postfix);
	printf("The postfix string is %s \n",postfix);
}	
void infixpostfix(char infix[],char postfix[])
{
	int len,i,k,top;
	char x,s[MAX];
	len = strlen(infix);
	infix[len] = ')';
	top = i = k = 0;
	s[top] = '(';
	while(i<=len)
	{
		x = infix[i];
		if(ICP(x) == 8)
			x='#';
		switch(x)
		{
		case '#': postfix[k++] = infix[i];
			 break;
		case ')': while(s[top]!='(')
			  
				postfix[k++] = pop(s,&top);
				pop(s,&top);
				if(top == -1)
				{
					postfix[k]='\0';
					return;
				}
			
			break;
		default : while(ICP(x) < ISP(s[top]))
				postfix[k++] = pop(s,&top);
			push(s,&top,x);
			
		}
		i++;
	}
}
int ICP(char c)
{
	if((c >= 'A') && (c <= 'Z') || (c >= '0' && c <= '9') || (c >= 'a') && (c<= 'z'))
		c = '#';
	switch(c)
	{
		case '+':
		case '-': return(1);
		case '*':
		case '/':
		case '%': return(3);
		case '$':
		case '^': return(6);
		case '#': return(8);
		case '(': return(9);
		case ')': return(0);
		default: printf("Error \n");
			return (-1);
	}
}
int ISP(char c)
{
	switch(c)
	{
		case '+':
		case '-': return(1);
		case '*':
		case '/':
		case '%': return(4);
		case '$': return(5);
		case '(': return(0);
		default: printf("error \n");
			return(-1);
	}
}
void push(char items[],int *top,char e)
{
	items[++(*top)] = e;
}
char pop(char items[], int *top)
{
	return items[(*top)--];
}

