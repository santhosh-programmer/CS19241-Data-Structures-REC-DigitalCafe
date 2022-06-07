// ABC international is checking the company names of its client for palindrome. A string is said to be palindrome if both the input string and the reversed output string are one and the same. So ABC international needs to reverse the names of the companies they have. Write a program to reverse a string using stack implementation. Remember as stack uses LIFO concept the string pushed can be popped out in a reverse order.

// Constraint: String can be of size 10.

// Input: Input string S

// Output: Reverse of a string given as input or overflow if string is above size 10.

// Test Case 1:

// Input:

// madam

// Output

// madam

#include<stdio.h>
#include<string.h>
char s[100];
int top=-1;
void push(char e)
{
    top++;
    s[top]=e;
}
void display()
{
    while(top>=0)
    {
        printf("%c",s[top]);
        top--;
    }
}
int main()
{
    char ch[100];
    scanf("%s",ch);
    for(int i=0;i<strlen(ch);i++)
    push(ch[i]);
    if(strlen(ch)>10)
    printf("Overflow");
    else
    display();
}
