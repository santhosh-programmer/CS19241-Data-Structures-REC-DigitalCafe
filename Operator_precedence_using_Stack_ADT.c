// Given an arithmetic expression, find the operator with highest priority using stack.

//  (consider only basic arithmetic operators)

#include<stdio.h>
#include<string.h>
char s[20];
int top=-1;
int pri(char c)
{
    switch(c)
    {
        case '+':
        case '-':return 1;
                 break;
        case '*':
        case '/':return 2;
                 break;
        default: return 0;
    }
}
void push(char c)
{
    top++;
    s[top]=c;
}
char pop()
{
    int a=top;
    top--;
    return s[a];
}
int main()
{
    char str[20],temp;
    scanf("%[^\n]s",str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        {
            if(top==-1)
            push(str[i]);
            else
            {
                if(pri(s[top])>=pri(str[i]))
                {
                    temp=pop();
                    push(str[i]);
                    push(temp);
                }
                else
                push(str[i]);
            }
        }
    }
    printf("%c",pop());
    return 0;
}
