// The printer Queue uses the queue concept to store the list of files they get to print in the printer. Write a program to print the  first file in the printer Queue. If the number of print files is more than the print queue size, it should say “overflow” otherwise print the name of the first file.

// Input: 

// Queue size n , no of inputs m and input file names

// Output: 

// names of the first file in the queue to be printed or overflow

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char data[10];
    struct node *next;
}*f=NULL,*r=NULL;
typedef struct node node;
void enqueue()
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
    int n,m;
    scanf("%d\n%d",&n,&m);
    if(m>n)
    printf("Overflow");
    else
    {
        for(int i=0;i<m;i++)
        enqueue();
        printf("%s",f->data);
    }
    return 0;
}
