#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30
#define MALLOC(p,s,t)\
	if(!(p=(t*)malloc(s))) {\
		fprintf(stderr,"Insufficient memory \n");\
		exit(0);\
		}
struct list
{
	char USN[MAX];
	char name[MAX];
	char branch[MAX];
	int sem;
	char phno[MAX];
	struct list *link;
};
typedef struct list *NODE;
NODE create(NODE,int);
NODE insfront(NODE);
NODE insrear(NODE);
NODE delfront(NODE);
NODE delrear(NODE);
void display(NODE);
void readdata();
char usn[MAX];
char sname[MAX];
char branc[MAX];
int se;
char phone[MAX];

void main()
{
	int choice,done=0;
	NODE fi;
	fi=NULL;
	int n;
	while(!done)
	{
		printf("\n 1.Create \t 2.Insert front \t 3. Insert rear \t 4.Delete front \t 5.delete rear \t 6.display \t 7.Exit \n");
		printf("Enter choice \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter no. of students \n");
			scanf("%d",&n);
			fi=create(fi,n);
			break;

			case 2:
			readdata();
			fi=insfront(fi);
			break;
			
			case 3:
			readdata();
			fi=insrear(fi);
			break;
			
			case 4:
			fi=delfront(fi);
			break;
			
			case 5:
			fi=delrear(fi);
			break;
			
			case 6:
			display(fi);
			break;
			
			case 7:
			done=1;
			break;
			
			default:
			printf("Illegal entry \n");
			break;
		}
	}
}

void readdata()
{
	printf("Enter student USN: ");
	scanf("%s",usn);
	printf("Enter student name: ");
	scanf("%s", sname);
	printf("Enter branch: ");
	scanf("%s",branc);
	printf("Enter semester: ");
	scanf("%d",&se);
	printf("Enter phone number: ");
	scanf("%s",phone);
}
NODE create(NODE first,int n)
{
	int i;
	if(first==NULL)
	{
		for(i=1;i<=n;i++)
		{
			printf("Enter student data %d \n",i);
			readdata();
			first=insfront(first);
		}
		return first;
	}
	else printf("List already has some student data \n");
}

NODE insfront(NODE first)
{
	NODE q;
	MALLOC(q,sizeof(NODE),struct list);
	strcpy(q->USN,usn);
	strcpy(q->name,sname);
	strcpy(q->branch,branc);
	strcpy(q->phno,phone);
	q->sem=se;
	q->link=first;
	first=q;
	return first;
}
NODE insrear(NODE first)
{
	NODE q,t=first;
	MALLOC(q,sizeof(NODE),struct list);
	strcpy(q->USN,usn);
	strcpy(q->name,sname);
	strcpy(q->branch,branc);
	strcpy(q->phno,phone);
	q->sem=se;
	q->link=NULL;
	if(!first)
		return q;
	else
	{
		while(t->link)
			t=t->link;
		t->link=q;
	}
}

NODE delfront(NODE first)
{
	NODE te;
	if(first == NULL)
		printf("Can't delete,list is empty \n");
	else
	{
		te=first;
		first=first->link;
		free(te);
	}	
	return first;
}

NODE delrear(NODE first)
{
	NODE cur,pred;
	if(first == NULL)
	{
		printf("Can't delete,list is empty \n");
		return first;
	}
	if(first->link==NULL)
		return first=NULL;
	cur=first;
	while(cur->link!=NULL)
	{
	pred=cur;
	cur=cur->link;
	}
	free(cur);
	pred->link=NULL;
	return first;
}

void display(NODE first)
{
	int count =0;
	while(first)
	{
		printf("%s\t%s\t%s\t%d\t%s\n",first->USN,first->name,first->branch,first->sem,first->phno);
		first=first->link;
		count++;
	}
	printf("count of nodes = %d \n",count);
}	
