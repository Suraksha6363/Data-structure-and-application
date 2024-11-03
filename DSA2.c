#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 5
int s[MAX],top=-1,item;int lsFULL()
 {
if(top>=MAX-1)return 1;
return 0;
}
int lsEmpty()
{
if(top==-1)
{
return 1;
return 0;
}
void push(int item)
{
top++;
s[top]=item;
}
void push(int item)
{
top++;
s[top]=item;
}
void pop()
{
item=s[top];
top--;
}
void display()
{
int i;
printf("\n the elements of the stack are");
for(i=top;i>=0;i--)
printf("\n%d",s[i]);
}


 
