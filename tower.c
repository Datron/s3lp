#include<stdio.h>
void towerOfHanoi(int n, char s, char t, char d, int *m)
{
	if(n==1)
	{
		printf("Move Disk %d from peg %c to peg %c \n",n,s,d);
		(*m)++;
		return;
	}
	else {
	towerOfHanoi(n-1,s,d,t,m);
	printf("Move Disk %d from peg %c to peg %c \n",n,s,d);
	(*m)++;
	towerOfHanoi(n-1,t,s,d,m);
	}
}
void main()
{
	int n;
	int m=0;
	char s= 'A', t = 'B',d = 'C';
	printf("Enter the number of disks \n");
	scanf("%d",&n);
	towerOfHanoi(n,s,t,d,&m);
	printf("Number of moves = %d \n",m);
} 
