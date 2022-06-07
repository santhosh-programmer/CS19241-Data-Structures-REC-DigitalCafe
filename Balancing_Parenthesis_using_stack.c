// To evaluate the expression, the parenthesis need to be balanced which means all open parenthesis should have a closed parenthesis. Write a program using stack data structure to check whether the given parenthesis string is balanced or not.

// Input: String with parenthesis

// Output: String is “Balanced” or “Not Balanced”

#include<stdio.h>
#include<string.h>
int top=-1;
char s[100];
void push(char e)
{
    top++;
    s[top]=e;
}
int main()
{
    char ch[100];
    int flag;
    scanf("%s",ch);
    for(int i=3;i<strlen(ch)-3;i++)
    push(ch[i]);
    for(int i=0,j=top;i<=top;i++,j--)
    {
        if(ch[i]==ch[j])
        {
            flag=1;
            printf("Not Balanced");
            break;
        }
    }
    if(flag!=1)
    printf("Balanced");
}
