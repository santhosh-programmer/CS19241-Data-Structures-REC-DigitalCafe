// Computer handles multiuser, multiprogramming environment and time-sharing environment. In this environment a system (computer) handles several jobs at a time; to handle these jobs the concept of a queue is used. Write a program to pick up the last job in the queue of a multi-tasking environment.

// Input: queue size n and list of jobs

// Output: name of the last job


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char data[100];
    struct node *next;
}*f=NULL,*r=NULL;
typedef struct node node;
void insert()
{
    node *newnode=malloc(sizeof(node));
    scanf("%s",newnode->data);
    if(r==NULL)
    f=r=newnode;
    else
    {
        r->next=newnode;
        r=newnode;
    }
    r->next=NULL;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    insert();
    printf("%s",r->data);
    return 0;
}
