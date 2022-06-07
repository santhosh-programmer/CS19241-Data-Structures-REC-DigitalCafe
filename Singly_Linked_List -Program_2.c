// In a goods train, all the wagons attached to the train have a sheet of paper pasted that tells how much is the total weight of the goods in each wagon. The first wagon is attached to the engine, the second wagon is attached to the first wagon and so on and the last one is guard van. Given the weights of goods in the wagon  as input, print the weights in the reverse order.

// Example

// If the weights of the wagons starting from wagon 1 are as follows-   100->200->300->NULL then print the weights in the following order  300->200->100->NULL

// Input Format

// The first line contains an integer n, the number of elements in the linked list.
// Each of the next n, lines contains an integer, the data values of the elements in the linked list.

// Constraints

// 1 <=n <= 1000

// 1 <= list[i] <= 1000, where list[i] is the ith element in the list.

// Sample Input

// 5
// 1
// 2
// 3
// 4
// 5
// Sample Output

// 5 4 3 2 1 
// Explanation

// The initial linked list is: 1->2->3->4->5

// The reversed linked list is: 5->4->3->2->1

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int element;
    struct node *next;
    struct node *prev;
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
        newnode->prev=list;
        newnode->next=NULL;
        position=newnode;
    }
    else
    {
        newnode->next=NULL;
        position->next=newnode;
        newnode->prev=position;
        position=newnode;
    }
}
void display(node *list)
{
    if(list->next!=NULL)
    {
        node *pos=position;
        while(pos->prev!=NULL)
        {
            printf("%d\n",pos->element);
            pos=pos->prev;
        }
    }
}
int main()
{
    int n,m;
    node *list=malloc(sizeof(node));
    list->next=NULL;
    list->prev=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        insert(list,m);
    }
    display(list);
    return 0;
}
