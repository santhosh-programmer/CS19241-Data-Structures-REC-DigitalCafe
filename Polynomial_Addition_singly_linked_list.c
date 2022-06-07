// Find the sum of two polynomial numbers. Represent the polynomial using single linked list.

// Input Format :

// First line contains the Degree of the 1st polynomial

// Second line contains the Coefficient of 1st polynomial

// Third line contains the degree of the 2nd polynomial

// Fourth line contains the Coefficient of 2nd polynomial

// Sample Input :

// 3

// 5 2 0 1

// 2

// 4 3 1

// Sample Output:

// 5x^3 + 6x^2 + 3x^1 + 2

// Explanation:

// 5x^3 + 2x^2 + 1   +   4x^2 + 3x^1 + 1 =  5x^3 + 6x^2 + 3x^1 + 2

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
void insert(node *p,int c,int po)
{
    node *newnode=malloc(sizeof(node));
    newnode->next=NULL;
    newnode->pow=po;
    newnode->co=c;
    if(p->next==NULL)
    {
        p->next=newnode;
        position=newnode;
    }
    else
    {
        position->next=newnode;
        position=newnode;
    }
}
void display(node *ans)
{
    node *position=ans->next;
    while(position!=NULL)
    {
        if(position->co!=0)
        {
            printf("%d",position->co);
            if(position->pow!=0)
            {
                printf("x^%d",position->pow);
                printf("+");    
            }
        }
        position=position->next;
    }
}
void add(node *poly1,node *poly2)
{
    node *ans=malloc(sizeof(node));
    ans->next=NULL;
    position=ans;
    node *p1=poly1->next;
    node *p2=poly2->next;
    while(p1!=NULL && p2!=NULL)
    {
        node *newnode=malloc(sizeof(node));
        newnode->next=NULL;
        if((p1->pow==p2->pow))
        {
            newnode->co=p1->co + p2->co;
            newnode->pow=p1->pow;
            p1=p1->next;
            p2=p2->next;
        }
        else if ((p1->pow > p2->pow))
        {
            newnode->co=p1->co;
            newnode->pow=p1->pow;
            p1=p1->next;
        }
        else if((p1->pow < p2->pow))
        {
            newnode->co=p2->co;
            newnode->pow=p2->pow;
            p2=p2->next;
        }
        position->next=newnode;
        position=newnode;
    }
    while(p1!=NULL || p2!=NULL)
    {
        if(p1==NULL && p2==NULL)
        break;
        else{
        node *newnode=malloc(sizeof(node));
        newnode->next=NULL;
        /*if(p1==NULL && p2==NULL)
        {
            newnode->co=p1->co + p2->co;
            newnode->pow=p1->pow;
            position->next=newnode;
            position=newnode;
            break;
        }*/
        {
            if(p1!=NULL)
            {
                newnode->co=p1->co;
                newnode->pow=p1->pow;
                p1=p1->next;
            }
            if(p2!=NULL)
            {
                newnode->co=p2->co;
                newnode->pow=p2->pow;
                p2=p2->next;
            }
            position->next=newnode;
            position=newnode;
        }
    }
    }
    display(ans);
}

int main()
{
    int n,m;
    node *poly1=malloc(sizeof(node));
    node *poly2=malloc(sizeof(node));
    poly1->next=NULL;
    poly2->next=NULL;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&m);
        insert(poly1,m,n-i);
    }
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&m);
        insert(poly2,m,n-i);
    }
    add(poly1,poly2);
    return 0;
}
