// Write a C Program to Merge two Singly Linked List and Display the elements of Merged List.

// Input:

// Number of Elements in List1 - m

// m Elements in List1

// Number of Elements in List2 - n

// n Elements in List2

// Output:

// m+n Elements from List1 and List2

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
void merge(node *list1,node *list2)
{
    node *position=list1;
    while(position->next!=NULL)
    position=position->next;
    position->next=list2->next;
}
void display(node *list1)
{
    if(list1->next!=NULL)
    {
        node *position=list1->next;
        while(position!=NULL)
        {
            printf("%d\n",position->element);
            position=position->next;
        }
    }
}
int main()
{
    int n,e,m;
    node *list1=malloc(sizeof(node));
    list1->next=NULL;
    node *list2=malloc(sizeof(node));
    list2->next=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&e);
        insert(list1,e);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&e);
        insert(list2,e);
    }
    merge(list1,list2);
    display(list1);
    return 0;
}
