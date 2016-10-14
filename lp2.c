#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stringmatch(char str[], char pat[], char rep[], char final[])
{
	int i,j,k,m,t,found;
	i=j=k=m=t=found=0;
	while(str[i]!='\0')
	{
		if(str[m++] == pat[j++])
		{
			if(pat[j] == '\0')
			{
				for(k=0;rep[k]!='\0';k++,t++)
				{
					final[t]=rep[k];
				}
				j=0;
				i=m;
				found=1;
				
			}
		}
		else
		{
			final[t++]=str[i++];
			m=i;
			j=0;
		}
	}
	final[t]='\0';
	return found;
}
void main()
{
	char str[MAX],pat[MAX],rep[MAX],final[MAX];
	int found=0;
	printf("Enter source string \n");
	fgets(str,50,stdin);
	printf("Enter pattern string \n");
	fgets(pat,50,stdin);
	printf("Enter replacement string \n");
	fgets(rep,50,stdin);
	found = stringmatch(str,pat,rep,final);
	if(found == 1)
	{
		printf("The final string \n");
		puts(final);
	}
	else printf("Search string not found \n");
}
