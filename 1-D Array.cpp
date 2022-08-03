#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 20
typedef char TYPE;
typedef struct
{
TYPE arr[SIZE];
int top;
}STACK;
/******************* Initialization of stack **********************/
void initStack(STACK *s)
{
s->top=-1;
return;
}
/*************** checking whether Stack is FULL *******************/
int isFull(STACK *s)
{
if(s->top==SIZE-1)
return 1;
else
return 0;
}
/**************** checking whether Stack is EMPTY ****************/
int isEmpty(STACK *s)
{
if(s->top==-1)
return 1;
else
return 0;
}
/************ inserting an new element into the stack *************/
void push(STACK *s,TYPE item)
{
if(isFull(s))
printf("\nStack Overflow\n");
else
s->arr[++s->top]=item;
return;
}
/*************** deleting an element from stack ******************/
TYPE pop(STACK *s)
{
TYPE item;
if(isEmpty(s))
{
printf("\nStack Underflow\n");
exit(0);
}
else
item=s->arr[s->top--];
return item;
}
/************* Printing the top element of stack ****************/
void peek(STACK *s)
{
int i;
if(isEmpty(s))
printf("\nStack is Empty.\n");
else
printf("\n The Top element of Stack is: %d",s->arr[s->top]);
return;
}
/********************Main Function********************/
int main()
{
STACK s;
int ch,ele;
initStack(&s);
do
{
printf("\n**********MENU**********\n");
printf("1. PUSH\n2. POP\n3. PEEP\n4. EXIT\n");
printf("\t\t\tEnter your choice [1-4]:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter an element:");
scanf("%d",&ele);
push(&s,ele);
break;
case 2:
ele=pop(&s);
if(ele!=-999)
printf("\nThe popped element=%d\n",ele);
break;
case 3:
peek(&s);
break;
case 4:
printf("\nThank You.\n");
exit(0);
default:
printf("\nInvalid Choice\n");
}
}while(1);
system("PAUSE");
return 0;
}