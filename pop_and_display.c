// read size of the stack

// pop the last element of a stack and display the stack as well as print the index of top element

// after pop if stack is empty display as "underflow"

#include<stdio.h>
int top=-1,s[100],n;
void push(int e)
{
    top++;
    s[top]=e;
}
void pop()
{
    top--;
}
void display()
{
    if(top==-1)
    printf("underflow\n%d",top);
    else
    {
        for(int i=0;i<=top;i++)
        printf("%d ",s[i]);
        printf("\n%d",top);
    }
}
int main()
{
    int e;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&e);
        push(e);
    }
    pop();
    display();
    return 0;
}
