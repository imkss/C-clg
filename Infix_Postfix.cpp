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
void initStack(STACK *);
int isFull(STACK *);
int isEmpty(STACK *);
void push(STACK *,TYPE);
TYPE pop(STACK *);
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
/************************* PUSH Function **************************/
void push(STACK *s,TYPE item)
{
if(isFull(s))
printf("\nStack Overflow\n");
else
s->arr[++s->top]=item;
return;
}
/*************************** POP Function *************************/
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
/************** checking for a valid operator or not **************/
int Operator(char ch)
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
/************* assigning precedence to the operators **************/
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
/********************Main Function********************/
int main()
{
STACK s;
char infix[SIZE],postfix[SIZE],ch;
int i,j=0,par_count=0;
initStack(&s);
printf("\nEnter the infix expression:");
gets(infix);
for(i=0;infix[i];i++)
{
ch=infix[i];
if(isalnum(ch))
postfix[j++]=ch;
else if(ch=='(')
{
par_count++;
push(&s,ch);
}
else if(ch==')')
{
if(par_count<=0)
{
printf("\n\aERROR:Parenthesis Mismatch.\n");
exit(0);
}
while((ch=pop(&s))!='(')
{
postfix[j++]=ch;
}
par_count--;
}
else if(Operator(ch))
{
if(precedence(s.arr[s.top])>=precedence(ch))
{
while(precedence(s.arr[s.top])>=precedence(ch))
postfix[j++]=pop(&s);
}
push(&s,ch);
}
else
{
printf("\n\aERROR:Invalid Operator.\n");
exit(0);
}
}
while(s.top!=-1)
postfix[j++]=pop(&s);
postfix[j]='\0';
if(par_count!=0)
{
printf("\n\aERROR:Parenthesis Mismatch.\n");
exit(0);
}
else
{
printf("\nPostfix expression is:");
puts(postfix);
}
system("PAUSE");
return 0;
}
