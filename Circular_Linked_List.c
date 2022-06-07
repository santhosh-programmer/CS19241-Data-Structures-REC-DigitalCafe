// Write a Program to implement Circular Linked List which performs the following operations based on the users input.

// 1 -> Insertion

// 2 -> Deletion

// 3 -> Display

// 4 -> Find the Number of Elements 

// 5 -> EXIT

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
    if(list->next==list)
    {
        list->next=newnode;
        newnode->next=list;
        position=newnode;
    }
    else
    {
        newnode->next=list;
        position->next=newnode;
        position=newnode;
    }
}
void del(node *list,int e)
{
    node *position=list,*tempnode;
    while(position->next->element!=e &&position->next->next!=list)
    position=position->next;
    tempnode=position->next;
    position->next=tempnode->next;
    free(tempnode);
}
void display(node *list)
{
    if(list->next!=list)
    {
        node *position=list->next;
        while(position!=list)
        {
            printf("%d ",position->element);
            position=position->next;
        }
    }
}
void count(node *list)
{
    if(list->next!=list)
    {
        int count=1;
        node *position=list->next;
        while(position->next!=list)
        {
            count++;
            position=position->next;
        }
        printf("\n%d",count);
    }
}
int main()
{
    int n,e;
    node *list=malloc(sizeof(node));
    list->next=list;
    do
    {
        scanf("%d ",&n);
        switch(n)
        {
            case 1: scanf("%d ",&e);
                    insert(list,e);
                    break;
            case 2: scanf("%d",&e);
                    del(list,e);
                    break;
            case 3: display(list);
                    break;
            case 4: count(list);
                    break;
            case 5: break;
        }
    }while(n!=5);
}
