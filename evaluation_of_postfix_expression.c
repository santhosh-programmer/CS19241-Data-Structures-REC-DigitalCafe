
//Give an input Postfix Expression, write the program to evaluate the given postfix expression using Stack Operations.

//Input : Postfix Expression and List of values of the variables

//Output : Result of the expression

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int s[20],top=-1;
void push(int e)
{
    top++;
    s[top]=e;
}
int pop()
{
    int temp=top;
    top--;
    return s[temp];
}
int main()
{
    char str[20];
    int a,n,b,c;
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            scanf("%d",&n);
            push(n);
        }
        else
        {
            switch(str[i])
            {
                case '+':  a=pop()+pop();
                           push(a);
                           break;
                case '-':  b=pop();
                           c=pop();
                           a=c-b;
                           push(a);
                           break;
                case '*':  a=pop()*pop();
                           push(a);
                           break;
                case '/':  b=pop();
                           c=pop();
                           a=c/b;
                           push(a);
                           break;
            }
        }
    }
    printf("%d",pop());
    return 0;
}
