#include <stdio.h>
#include <stdlib.h>
typedef struct bst
{
int info;
struct bst *left,*right;
}BST;
BST* insert_BST(BST *,int);
BST* delet_BST(BST *,int);
void search_BST(BST *, int);
void inorder(BST *);
void swap(int *, int * );
/*******insert a node into BST*******/
BST* insert_BST(BST *root,int x)
{
BST *p, *nw;
nw=(BST*)malloc(sizeof(BST));
nw->info=x;
nw->left=nw->right=NULL;
if(root==NULL)
root=nw;
else
{
p=root;
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
/*******Inorder Traversal of a BST*******/
void inorder(BST *root)
{
BST *p=root;
if(p!=NULL)
{
inorder(p->left);
printf("%d\t",p->info);
inorder(p->right);
}}
/*******Main Function*******/
int main()
{
BST *root=NULL;
int ele,ch;
do
{
printf("\t\n*****MENU*****\n");
printf("1. Insertion\n");
printf("2. Inorder Traversal\n");
printf("3. Exit\n");
printf("\n\t Enter your choice :");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n Enter the data to be inserted:");
scanf("%d",&ele);
root=insert_BST(root,ele);
break;
case 2:
inorder(root);
break;
case 3:
exit(0);
default:
printf("\nERROR :- Invalid Option\n");
}
}while(1);
system("PAUSE");
return 0;
}