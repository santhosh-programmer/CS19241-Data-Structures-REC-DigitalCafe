// Read size of a stack No and insert n elements into the stack. print stack print the top element of the stack

#include<stdio.h>
int top=-1,s[100],n;
void push(int e)
{
    top++;
    s[top]=e;
}
void display()
{
    while(top>=0)
    {
        printf("%d ",s[top]);
        top--;
    }
    printf("\n%d",s[n-1]);
}
int main()
{
    int e;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&e);
        push(e);
    }
    display();
}
