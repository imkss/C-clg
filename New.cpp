#include <stdio.h>
#include <stdlib.h>
typedef struct bst{
	int info;
	struct bst *left,*right;
}bst;

bst *insert(bst *root,int x )
{
	bst * p, *nw;
	nw=(bst*)malloc(sizeof(bst));
	nw->info=x;
	nw->left=nw->right=NULL;
	if(root==NULL)
	{
		root = nw;
	}
	else
	{
		p= root;
		while(p!=NULL)
		{
			if((x<p->info)&&(p->left!=NULL))
			 p=p->left;
			else if((x>p->info)&&(p->right!=NULL))
			 p=p->right;
			else
			 break;
		}
		if(x<p->info)
		  p->left=nw;
		  
		else
		  p->right=nw;
		}
		return root;
	}
bst *delete(bst *root, int x){
BST *p,*q,*u;
p=root;
q=NULL; /* p is the node to be deleted & q is the parent of p*/
while(p!=NULL){ /search routines begins/
if(x<p->info){
q=p;
p=p->left;
} else if(x>p->info){
q=p;
p=p->right;
} else
break;
}/Search Routine Ends/
/case1: The node to be deleted (p) is a leaf node/
if((p->left==NULL)&&(p->right==NULL)){
if(q==NULL){ /subcase1: p is the root node i.e. q is NULL/
free(p);
root=NULL;
} else{ /*subcase2: q
is not NULL*/
if(q->left==p)
q->left=NULL;
else
q->right=NULL;
free(p);
}
} /* End of case1*/
/case2: The node to be deleted (p) has only left child/
else if((p->left!=NULL)&&(p->right==NULL)){
if(q==NULL){ /subcase1: p is the root node i.e. q is NULL/
root=p->left;
p->left=NULL;
free(p);
} else{ /*subcase2: q
is not NULL*/
if(q->left==p)
{
q->left=p->left;
p->left=NULL;
free(p);
}
else
{
q->right=p->left;
p->left=NULL;
free(p);
}
}
} /* End of case2*/
/case3: The node to be deleted (p) has only right child/
else if((p->left==NULL)&&(p->right!=NULL)){
if(q==NULL){ /subcase1: p is the root node i.e. q is NULL/
root=p->right;
p->right=NULL;
free(p);
} else{ /*subcase2: q
is not NULL*/
if(q->right==p)
{
q->right=p-> right;
p-> right=NULL;
free(p);
}
else
{
q->left=p->right;
p-> right =NULL;
free(p);
}
}
} /* End of case3*/
/case4: The node to be deleted (p) has both left and right child/
else
{
q=p;
u=p->right;
while(u->left!=NULL)
{
q=u;
u=u->left;
}
swap(&(p->info), &(u->info));
if(q->left==u)
q->left=u->right;
else
q->right=u->right;
free(u);
}/end of case4/
return root;
}/end of function/
void swap(int *i,int*j)
{
	int t=*i;
	*i=*j;
	*j=t;
}


void searh(bst *root,int x)
{
	bst *p;
	if(root==NULL)
	{
		printf("\n Imposiible\n");
		exit(0);
	}
	else
	{
		p=root;
		while(p!=NULL)
		{
			if(x<p->info)
			{
				p=p->left;
			}
			else if(x>p->info)
			{
				p=p->right;
			}
			else
			printf("\nfound\n");
		}
		if(p==NULL)
		printf("\nfound\n");
	}
}
void inorder(bst * root)
{
	bst *p=root;
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d\t",p->info);
		inorder(p->right);
	}
}
int main()
{
	bst *root=NULL;
	int ele,ch;
	do{
printf("\n*****MENU***\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Search\n");
printf("4. Inorder Traversal\n");
printf("5. EXIT\n");
printf("\t\t\tEnter your choice [1-5]:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the node information to be insert:");
scanf("%d",&ele);
root=insert(root,ele);
break;
case 2:
printf("Enter the node information to be deleted:");
scanf("%d",&ele);
root=delete(root,ele);
break;
case 3:
printf("Enter the node to be search:");
scanf("%d",&ele);
  searh(root,ele);
break;
case 4:
inorder(root);
break;
case 5:
printf("\nThank You.\n");
exit(0);
default:
printf("\nInvalid Choice\n");
}
}while(1);
return 0;
}