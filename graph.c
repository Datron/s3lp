#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int visited[MAX];
int a[MAX][MAX];
int n;
void readadjmatrix();
void dfs(int);
void main()
{
	int start;
	readadjmatrix();
	printf("Enter the starting vertex: ");
	scanf("%d",&start);
	dfs(start);
}

void readadjmatrix()
{
	int i,j;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	printf("Enter adjacency matrix:");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
}

void dfs(int v)
{
	int w;
	visited[v]=1;
	for(w=2;w<=n;w++)
	{
		if(visited[w]==0 && a[v][w]==1)
		{
			printf("%d ->",w);
			dfs(w);
		}
	}
	printf("\n");
}


