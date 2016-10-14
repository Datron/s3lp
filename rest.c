#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char *str;
	str = (char *)calloc(10,sizeof(char));
	if( str == NULL)
		printf("Insufficient memory \n");
	strcpy(str,"computer");
	str = (char *)realloc(str,40);
	strcpy(str,"computer science and engineering \n");
	printf("%s \n",str);
	free(str);
}
