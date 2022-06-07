// Find the differentiation of the polynomial equation using Singly Linked List.

// Input Format :

// First line contains the highest degree of the polynomial

// Second line contains the Coefficient of polynomial

// Sample Input :

// 5

// 3 0 -2 0 1 5

// Sample Output:

// 15x^4 - 6x^2 + 1x^0

// Explanation:

// Differentiation (3x^5 + 0x^4 - 2x^3 + 0x^2 + 1x^1 + 5x^0) = 15x^4 - 6x^2 + 1x^0

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int pow;
    int co;
    struct node *next;
};
typedef struct node node;
node *position;
void diff(node *ans,int c,int p)
{
    node *newnode=malloc(sizeof(node));
    newnode->next=NULL;
    if(p>0)
    {
        newnode->pow=p-1;
        newnode->co=p*c;
        if(ans->next==NULL)
        {  
            ans->next=newnode;
            position=newnode;
        }
        else
        {
            position->next=newnode;
            position=newnode;
        }
    }
}
void display(node *ans)
{
    node *position=ans->next;
    while(position!=NULL)
    {
        if(position->co!=0)
        {
            printf("%dx^%d ",position->co,position->pow);
            if(position->pow!=0 && position->co>0)
            printf("+ ");
        }
        position=position->next;
    }
}
int main()
{
    int n,m;
    node *ans=malloc(sizeof(node));
    ans->next=NULL;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        scanf("%d ",&m);
        diff(ans,m,n-i);
    }
    display(ans);
    return 0;
}
