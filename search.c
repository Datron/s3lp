#include<stdio.h>
#include<string.h>
void sort(char a[20][20],int n)
{
	char temp[20];
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(strcmp(a[j],a[j+1])>0)
			{
				strcpy(temp,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],temp);
			}
		}
	}
	printf("Sorted: \n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",a[i]);
	}
}
void main()
{
	char a[20][20],key[20];
	int n,i,low,mid,high,found=0;
	printf("Enter the no. of elements \n");
	scanf("%d",&n);
	printf("Enter the elements \n");
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	sort(a,n);
	low=0;
	high=n-1;
	printf("Enter the key search term\n");
	scanf("%s",key);
	while(low < high && !found)
	{
		mid=(low+high)/2;
		if(strcmp(a[mid],key) > 0) 
			high=mid-1;
		else if(strcmp(a[mid],key) == 0)
			found=1;
		else
			low=mid+1;
	}
	if(found==1)
		printf("found at %d\n",mid+1);
	else
		printf("not found \n");
}
