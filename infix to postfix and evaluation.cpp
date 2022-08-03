#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 10
typedef char TYPE;
typedef struct
{
TYPE arr[SIZE];
int top;
}STACK;
void initStack(STACK *);
int isFull(STACK *);
int isEmpty(STACK *);
void push(STACK *,TYPE);
TYPE pop(STACK *);
void peep(STACK *);
/********************Initialization of stack********************/
void initStack(STACK *s)
{
s->top=-1;
return;
}
/********************Stack full or not********************/
int isFull(STACK *s)
{
if(s->top==SIZE-1)
return 1;
else
return 0;
}
/********************Stack empty or not********************/
int isEmpty(STACK *s)
{
if(s->top==-1)
return 1;
else
return 0;
}
/********************Pushing an element into stack********************/
void push(STACK *s,TYPE item)
{
if(isFull(s))
printf("\nStack Overflow\n");
else
s->arr[++s->top]=item;
return;
}
/********************Popping an element from stack********************/
TYPE pop(STACK *s)
{
TYPE item;
if(isEmpty(s))
{
printf("\nStack Underflow\n");
item='~';
}
else
item=s->arr[s->top--];
return item;
}
/********************Traversing the stack********************/
void peep(STACK *s)
{
int i;
if(isEmpty(s))
printf("\nStack is Empty.\n");
else
for(i=s->top;i>=0;i--)
printf("%c\n",s->arr[i]);
return;
}
/********************Checking operator or not********************/
int isOperator(char ch)
{
switch(ch)
{
case '^':
case '/':
case '*':
case '%':
case '-':
case '+':return 1;
default: return 0;
}
}
/********************Finding precedence of
operators********************/
int precedence(char ch)
{
switch(ch)
{
case '^':return 3;
case '/':
case '*':
case '%':return 2;
case '-':
case '+':return 1;
default: return 0;
}
}
/****************Conversion from infix to postfix*********************/
void infix2postfix(char infix[],char postfix[])
{
int i,j=0;
char ch;
STACK s;
initStack(&s);
for(i=0;infix[i];i++)
{
ch=infix[i];
if(isalnum(ch))
postfix[j++]=ch;
else if(ch=='(')
push(&s,ch);
else if(ch==')')
{
while((ch=pop(&s))!='(')
{
postfix[j++]=ch;
}
}
else if(isOperator(ch))
{
if(!isEmpty(&s))
{
while(precedence(s.arr[s.top])>=precedence(ch))
postfix[j++]=pop(&s);
}
push(&s,ch);
}
}
while(!isEmpty(&s))
postfix[j++]=pop(&s);
postfix[j]='\0';
}
/********************Evaluation of postfix*************************/
int eval_postfix(char postfix[])
{
int i,op1,op2,val;
char ch;
STACK s;
initStack(&s);
for(i=0;postfix[i];i++)
{
ch=postfix[i];
if(!isOperator(ch))
{
if(isalpha(ch))
{
printf("\nEnter value for %c:",ch);
scanf("%d",&val);
push(&s,val);
}
else
push(&s,ch-48);
}
else
{
op2=pop(&s);
op1=pop(&s);
switch(ch)
{
case '^':val=(int)pow(op1,op2);break;
case '/':val=op1/op2;break;
case '*':val=op1*op2;break;
case '%':val=op1%op2;break;
case '-':val=op1-op2;break;
case '+':val=op1+op2;break;
}
push(&s,val);
}
}
val=pop(&s);
return val;
}
/********************Main Function********************/
int main()
{
char infix[SIZE],postfix[SIZE];
int result;
printf("Enter the infix expression:");
gets(infix);
infix2postfix(infix,postfix);
printf("\nPostfix expression is:");
puts(postfix);
result=eval_postfix(postfix);
printf("\nThe evaluated value=%d\n",result);
system("PAUSE");
return 0;
}
