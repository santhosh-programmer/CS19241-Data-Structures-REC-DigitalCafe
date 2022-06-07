// Develop a menu driven program to insert a node in the linked list and display the same. Based on the options given in the input, the corresponding subroutine should be executed. The options are as follows-

// option 1 - to insert a node in the beginning of the linked list 

// option 2 - to insert a node in the end of the linked list.

// Input Format

// no. of nodes n

// next n lines denotes the values of the nodes

// option 

// value of the node to insert

// Sample Input

// 4

// 55

// 33

// 44

// 22

// 1

// 88

// Sample Output

// 88

// 55

// 33

// 44

// 22

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int element;
    struct node *next;
};
typedef struct node node;
node *position;
void insertlast(node *list,int e)
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
void insertbeg(node *list,int e)
{
    node *newnode=malloc(sizeof(node));
    newnode->element=e;
    if(list->next==NULL)
    {
        list->next=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=list->next;
        list->next=newnode;
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
    int n,m,x;
    node *list=malloc(sizeof(node));
    list->next=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        insertlast(list,m);
    }
    scanf("%d\n%d",&x,&m);
    if(x==1)
    insertbeg(list,m);
    else
    insertlast(list,m);
    display(list);
    return 0;
}
