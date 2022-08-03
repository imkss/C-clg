#include<stdio.h>
#include<stdlib.h>
#define max 5

typedef struct queue
{
	char data[max];
	int front,rear;
}queue;

int isempty(queue *q)
{
	if(q->front==-1)
		return 1;
	else
		return 0;
}

int isfull(queue *q)
{
	if((q->front == q->rear + 1) || (q->front == 0 && q->rear == max - 1))
		return 1;
	else
		return 0;
}

void enquecircular(queue *q,char x)
{
	if(isfull(q))
	{
		printf("\nqueue overflow");
		return;
	}
	else 
    {
    	if (q->front == -1) 
    		q->front = 0;
    	q->rear = (q->rear + 1) % max;
    	q->data[q->rear] = x;
   }
}
char dequeuecircular(queue *q)
{
	char x;
	if(isempty(q))
	{
		printf("\nqueue underflow");
		return -1;
	}
	else {
    x = q->data[q->front];
    if (q->front == q->rear) {
      q->front = -1;
      q->rear = -1;
    } 
    else {
      q->front = (q->front + 1) % max;
    }
    return (x);
  }
}
void displaycircular(queue *q)
{
	int i;
  if (isempty(q))
    printf(" \n Empty Queue\n");
  else {
    for (i = q->front; i != q->rear; i = (i + 1) % max) {
      printf("%c ", q->data[i]);
    }
    printf("%c ", q->data[i]);
    
  }
	if(q->front <= q->rear){
//	printf("\nTotal elements = %d ",q->rear-q->front+1);
  }
  else
  {
//    printf("\nTotal elements = %d ",(q->rear)+(max-q->front)+1);
  }
}
    void count(queue *q)
{
   int count=0,i;
   for(i=q->front;i<=q->rear;i++)
   { 
     count++;
   }
  printf("Number of Element in queue is :%d\n",count);
}

int main()
{
 queue *q;
 q=(queue*)malloc(sizeof(queue));
 int op;
 char item,ch;
 q->front=-1;
 q->rear=-1;
 while(1)
 {
 	printf("\n1.INSERT\n2.DELETE\n3.COUNT\n4.DISPLAY\n5.EXIT\n");
 	printf("Enter option : ");
 	scanf("%d",&op);
 	switch(op)
 	{
 		case 1:
 			scanf("%c",&item);
    	printf("Enter item to insert : ");
 			scanf("%c",&item);
 			enquecircular(q,item);
 			break;
 		case 2:
 					 printf("The deleted elements are:-\n"); 

 			
 			ch=dequeuecircular(q);
 			if(ch!=-1)
 			{
 				printf("\nDeleted item = %c",ch);
 			}
 			break;
 		case 3: 
		 		 printf("The number of elements are:-\n"); 

				count(q);
 		    	break;
 		case 4: 
		 printf("The Elements are:-\n"); 
		 displaycircular(q);
 	
 		break;
 		case 5:exit(0);
 		default:printf("Invalid option\n");
 	}
 }
 return 0;
}
