#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 80
float eval(char expr[]);
float oper(char symb,float op1, float op2);
void push(float items[], int *top, float e);
float pop(float items[],int *top);
void main()
{
	char expr[MAX];
	printf("Enter the postfix expression \n");
	fgets(expr,80,stdin);
	printf("The orginal postfix expression = %s \n",expr);
	printf("%6.2f \n",eval(expr));
}
float eval(char expr[])
{
	char c;
	int pos;
	float res,op1,op2,r,s[MAX];
	int top = -1;
	for(pos = 0;(c = expr[pos])!='\0';pos++)
	{
		if(isdigit(c))
			push(s,&top,(float)(c - '0'));
		else
		{
			op2 = pop(s,&top);
			op1 = pop(s,&top);
			r = oper(c,op1,op2);
			push(s,&top,r);
		}
	}
	res = pop(s,&top);
	return res;
}
float oper(char symb,float op1, float op2)
{
	switch(symb)
	{
		case '+':return (op1+op2);
		case '-':return (op1-op2);
		case '*':return (op1*op2);
		case '/':return (op1/op2);
		case '^':
		case '$':return (float)pow(op1,op2);
		case '%':return (float)((int)op1 % (int)op2);
		default: printf("%s illegal operator \n",symb);
			exit(1);
	}
}
void push(float items[], int *top, float e)
{
	items[++(*top)] = e;
}
float pop(float items[],int *top)
{
	return items[(*top)--];
}

