#include<stdio.h>
struct sname
{
	char name[20],USN[20];
	int marks;
};
void main()
{
	struct sname s1[20];
	int i,n;
	printf("Enter the number of students \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the student name \n");
		scanf("%s",s1[i].name);
		printf("Enter the student USN \n");
		scanf("%s",s1[i].USN);
		printf("Enter the marks \n");
		scanf("%d",&s1[i].marks);
	}
	printf("Name \t USN \t Marks \n");
	for(i=0;i<n;i++)
	{
		printf("%s \t %s \t %d \n",s1[i].name,s1[i].USN,s1[i].marks);
	}
}
