#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char *str;
	str = (char *)calloc(10,sizeof(char));
	if( str == NULL)
	{
		printf("Insufficient memory \n");
	}
	strcpy(str,"computer");
	printf("%s \n",str);
	free(str);
}
