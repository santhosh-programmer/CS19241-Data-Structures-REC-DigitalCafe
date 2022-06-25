// Write a C Program to copy the elements of one List to another List using Linked List Concept.

// Input:

// m - Elements in List1

// m Elements of List1

// Output:

// m Elements of List2 copied from List1

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int element;
    struct node *next;
};
typedef struct node node;
node *position;
void insert(node *list,int e)
{
    node *newnode=malloc(sizeof(node));
    newnode->element=e;
    if(list->next==NULL)
    {
        list->next=newnode;
        newnode->next=NULL;
        position=newnode;
    }
    else
    {
        newnode->next=NULL;
        position->next=newnode;
        position=newnode;
    }
}
void copy(node *list1,node *list2)
{
    node *position=list1->next;
    node *pos;
    while(position!=NULL)
    {
        node *newnode=malloc(sizeof(node));
        newnode->element=position->element;
        newnode->next=NULL;
        if(list2->next==NULL)
        {
            list2->next=newnode;
            pos=newnode;
        }
        else
        {
            pos->next=newnode;
            pos=newnode;
        }
        position=position->next;
    }
}
void display(node *list)
{
    if(list->next!=NULL)
    {
        node *position=list->next;
        while(position!=NULL)
        {
            printf("%d\n",position->element);
            position=position->next;
        }
    }
}
int main()
{
    int n,m;
    node *list1=malloc(sizeof(node));
    list1->next=NULL;
    node *list2=malloc(sizeof(node));
    list2->next=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        insert(list1,m);
    }
    copy(list1,list2);
    display(list2);
    return 0;
}
