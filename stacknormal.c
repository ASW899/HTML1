#include<stdio.h>
int main()
{
int stack[50];
int top=-1;
int ele,size,i;
printf("enter the size of the stack");
scanf("%d",&size);
printf("Enter the elements of the stack");
for(i=0;i<=size;i++)
{
scanf("%d",&stack[i]);
top++;
}
printf("the elements of the stack");
for(i=top;i>=0;i--)
{
printf("%d",stack[i]);
}

printf("enter the element to be pushed into the stack");
scanf("%d",&ele);
if(top==size-1)
printf("overflow");
else
{

stack[top]=ele;
top++;
}

printf("enter the element to be popped");
if(top==-1)
printf("underflow");
else{
top--;
}
}
