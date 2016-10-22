#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30
struct list
{
	int SSN;
	char name[MAX];
	char dept[MAX];
	char designation[MAX];
	float sal;
	char phno[MAX];
	struct list *prev;
	struct list *next;
};
#define MALLOC(p,s,t)\
	if(!(p=(t)malloc(s))){\
		fprintf(stderr,"Insufficient Memory \n");\
		exit(0);\
		}
typedef struct list *NODE;
NODE create(NODE,int);
NODE insfront(NODE);
NODE insrear(NODE);
NODE delfront(NODE);
NODE delrear(NODE);
void display(NODE);
void readdata();
int ssn;
char sname[MAX];
char Dept[MAX];
char desig[MAX];
float salary;
char phone[MAX];
/*main function starts here*/
void main()
{
	int choice,done=0,n;
	NODE fi=NULL;
	while(!done)
	{
		printf("1.Create \t 2.Insert front \t 3.Insert Rear \t 4.Delete front \t 5.Delete rear \t 6.Display \t 7.Exit \n");
		printf("Enter choice: \t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter no. of employees \n");
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
	printf("Enter Employee SSN: ");
	scanf("%d",&ssn);
	printf("Enter employee name: ");
	scanf("%s",sname);
	printf("Enter department: ");
	scanf("%s",Dept);
	printf("Enter designation: ");
	scanf("%s",desig);
	printf("Enter salary: ");
	scanf("%f",&salary);
	printf("Enter phone: ");
	scanf("%s",phone);
}
NODE create(NODE first,int n)
{
	int i;
	/*NODE q;*/
	if(first==NULL)
	{
		for(i=1;i<=n;i++)
		{
			printf("Enter employee data %d \n",i);
			readdata();
			first=insfront(first);
		}
		return first;
	}
	else printf("List already has some employee data \n");
}

NODE insfront(NODE first)
{
	NODE q;
	MALLOC(q,sizeof(struct list),NODE);
	q->SSN=ssn;
	strcpy(q->name,sname);
	strcpy(q->dept,Dept);
	strcpy(q->designation,desig);
	q->sal=salary;
	strcpy(q->phno,phone);
	q->prev=NULL;
	q->next=first;
	if(first != NULL)
		first->prev=q;
	return q;
}
NODE insrear(NODE first)
{
	NODE q,cur=first;
	MALLOC(q,sizeof(struct list),NODE);
	while(cur->next != NULL)
		cur=cur->next;
	q->SSN=ssn;
	strcpy(q->name,sname);
	strcpy(q->dept,Dept);
	strcpy(q->phno,phone);
	q->sal=salary;
	q->next=NULL;
	cur->next=q;
	q->prev=cur;
	return first;
}
NODE delfront(NODE first)
{
	NODE te;
	if(first == NULL)
	{
		printf("Can't delete,list is empty \n");
		return first;
	}
	else
	{
		te=first;
		first=first->next;
		first->prev=NULL;
		free(te);
	}	
	return first;
}

NODE delrear(NODE first)
{
	NODE cur;
	if(first == NULL)
	{
		printf("Can't delete,list is empty \n");
		return first;
	}
	if(first->next==NULL)
		return first=NULL;
	cur=first;
	while(cur->next!=NULL)
		cur=cur->next;
	cur->prev->next=NULL;
	free(cur);
	return first;
}

void display(NODE first)
{
	int count =0;
	while(first)
	{
		printf("%d\t%s\t%s\t%s\t%f\t%s\n",first->SSN,first->name,first->dept,first->designation,first->sal,first->phno);
		first=first->next;
		count++;
	}
	printf("count of nodes = %d \n",count);
}	
