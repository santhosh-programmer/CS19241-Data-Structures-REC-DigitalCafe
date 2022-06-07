// A Teacher gave randomly some marbles to students starting from first bench till the last bench but didn't note the count of marbles given to a student. The class representative was told to note down the marbles with students starting from first bench till the last bench. Given a  linked list, print each node's data element, one per line. If the head pointer is null (indicating the list is empty), there is nothing to print.

// Input Format

// The first line of input contains n, the number of elements in the linked list.
// The next n lines contain one element each, the data values for each node.

// Sample Input

// 2
// 16
// 13
// Sample Output

// 16
// 13
// Explanation

// There are two elements in the linked list. They are represented as 16 -> 13 -> NULL. So print 16 and 13 each on a new line.

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
    node *list=malloc(sizeof(node));
    list->next=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        insert(list,m);
    }
    display(list);
    return 0;
}
