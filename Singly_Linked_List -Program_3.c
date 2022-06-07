// A lady gardener collects roses from garden and puts them into bags. After filling bag1, she takes bag2 and fills with roses and so on. Later she counts the roses in each bag. Given the count of roses in each bag as data part of a linked list, print the total count of roses found in all bags.

// Example

// If the roses in each bags has the following counts-  100->115->105 the print the output as 320

// Input Format

// The first line contains an integer n, the number of bags.
// Each of the next n, lines contains an integer, that represents the count of roses in each bag

// Sample Input

// 3
// 100
// 115
// 105
// Sample Output

// 320

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int element;
    struct node *next;
};
typedef struct node node;
node *position;
int sum=0;
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
int count(node *list)
{
    node *position=list;
    while(position->next!=NULL)
    {
        sum+=position->next->element;
        position=position->next;
    }
    return sum;
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
    printf("%d",count(list));
    return 0;
}
