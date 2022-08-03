#include<stdio.h>
#include<stdlib.h>
#define size 5

typedef struct queue
{
	int data[size];
	int front,rear;
}queue;
int isempty(queue *q)
{
	if(q->front==-1 && q->rear==-1)
		return 1;
	else
		return 0;
}
int isfull(queue *q)
{
	if((q->front==0 && q->rear==size-1 )||(q->front==q->rear+1))
		return 1;
	else
		return 0;
}
void insert(queue *q,int x)
{
	if(isfull(q))
	{
		printf("\nqueue overflow");
		return;
	}
	else if(isempty(q))
		q->rear=q->front=0;
	else
		q->rear=(q->rear+1)%size;
	q->data[q->rear]=x;
}
int delet(queue *q)
{
	int x;
	if(isempty(q))
	{
		printf("\nqueue underflow");
		return -1;
	}
	x=q->data[q->front];
	if(q->front==q->rear)
		q->front=q->rear=-1;
	else
		q->front=(q->front+1)%size; 
	return x;
}
void count(queue *q)
{
	int i;
	if(isempty(q))
	{
		printf("\nqueue underflow");
		return;
	}
	if(q->front<=q->rear)
	{
		for(i=q->front;i<=q->rear;i++)
			printf("%d\t",q->data[i]);
		printf("\ntotal elements = %d ",q->rear-q->front+1);	
	}
	
	else
	
	{
		for(i=0;i<=q->rear;i++)
			printf("%d\t",q->data[i]);
	
		for(i=q->front;i<=size-1;i++)
			printf("%d\t",q->data[i]);
		printf("\ntotal elements = %d ",(size-q->front)+q->rear+1);	
	}
}
int main()
{
 queue *q;
 int num,op,item;
 q=(queue*)malloc(sizeof(queue));
 q->front=-1;
 q->rear=-1;
 do
 {
 	printf("\n1.INSERT\n2.DELETE\n3.COUNT\n4.EXIT\n");
 	printf("enter option : ");
 	scanf("%d",&op);
 	switch(op)
 	{
 		case 1:
 			printf("enter item to insert : ");
 			scanf("%d",&item);
 			insert(q,item);
 			break;
 		case 2:
 			num=delet(q);
 			if(num!=-1)
 			{
 				printf("\ndeleted item = %d",num);
 			}
 			break;
 		case 3:
 			printf("\nthe queue elements\n");
 			count(q);
 			break;
 		case 4:break;
 		default:printf("invalid option\n");
 	}
 }while(op!=4);
 return 0;
}
