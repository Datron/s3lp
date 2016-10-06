#include<stdio.h>
#define MAX 30
int stringmatch(char [],char [],char [],char []);
void main()
{

	char str[MAX],pat[MAX],rep[MAX],final[MAX];
	int found;
	printf("Enter the string \n");
	fgets(str,80,stdin);
	printf("Enter the replacement string \n");
	fgets(rep,80,stdin);
	printf("Enter the pattern string \n");
	fgets(pat,80,stdin);
	found=stringmatch(str,pat,rep,final);
	if(found == 1)
	{
		printf("pattern found \n");
		puts(final);
	}
	else printf("pattern not found\n");
}
int stringmatch(char str[],char pat[],char rep[],char final[])
{
	int i=0,j=0,k=0,m=0,t=0,found=0;
	while(str[i]!='\0')
	{
		if(str[m++] == pat[j++])
		{
			if(pat[j]=='\0')
			{
				for(k=0;rep[k]!='\0';k++,t++)
				{
				final[k]=rep[t];
				}
			j=0;
			i=m;
			found=1;
		}
	}
	else {
		final[t++]=str[i++];
		m=i;
		j=0;
	}
	}
	final[t]='\0';
	return found;
}



