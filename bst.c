#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30
struct tree
{
	int info;
	struct tree *left,*right;
};
typedef struct tree *NODE;
#define MALLOC(p,s,t)\
	if(!(p=(t)malloc(s))){\
		fprintf(stderr,"Insufficient memory \n");\
		exit(0);\
		}
NODE create(NODE,int);
NODE createTree(NODE,int);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
int search(NODE,int);
int n;
void main()
{
	NODE p;
	p=NULL;
	int done=0,choice,flag,key;
	while(!done)
	{
		printf("1.Create \t 2.Inorder \t 3.Postorder \t 4.Preorder \t 5.Search \t 6.Exit \n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("Enter no. of data elements \n");
		scanf("%d",&n);
		p=create(p,n);
		break;

		case 2:inorder(p);
		break;

		case 3:postorder(p);
		break;

		case 4:preorder(p);
		break;

		case 5:printf("Enter the key \n");
		scanf("%d",&key);
		flag=search(p,key);
		if(flag==1)
			printf("Key found \n");
		else
			printf("Key not found \n");
		break;

		case 6:done=1;
		break;

		default:printf("Illegal Entry \n");
		break;
	}
}
}
NODE create(NODE root,int n)
{
	int i,e;
	NODE q;
	if(root==NULL)
	{
		for(i=1;i<=n;i++)
		{
			printf("Enter data element \n");
			scanf("%d",&e);
			root=createTree(root,e);
		}	
		return root;
	}
	else
		printf("Tree already exists \n");
}

NODE createTree(NODE p,int e)
{
	if(p==NULL)
	{
		MALLOC(p,sizeof(struct tree),NODE);
		p->info=e;
		p->left = p->right = NULL;
	}
	else if(e == p->info)
		printf("Duplicate Entry \n");
	else if(e < p->info)
		p->left=createTree(p->left,e);
	else if(e > p->info)
		p->right=createTree(p->right,e);
	return p;
}

int search(NODE p,int key)
{
	if(p==NULL)
		return 0;
	else if(key == p->info)
		return 1;
	else if(key < p->info)
		return search(p->left,key);
	else
		return search(p->right,key);
}

void postorder(NODE root)
{
	if(root!=NULL)
	{
	postorder(root->left);
	postorder(root->right);
	printf("%d\n",root->info);
	}
}

void inorder(NODE root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->info);
		inorder(root->right);
	}
}

void preorder(NODE root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->info);
		preorder(root->left);
		preorder(root->right);
	}
}
		
