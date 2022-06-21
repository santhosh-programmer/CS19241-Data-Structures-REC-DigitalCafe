// Consider a Graph G Perform Depth First Traversal on the given graph. Vertices of the graph goes like 1, 2, 3 ...... n.

// Input :

// n - Integer - number of vertices

// nxn - adjacency matrix for the graph G

// m - Integer - starting vertex

// Output:

// List of n vertices - DFS Order.

// For example:

// Input	    Result
// 4           2
// 0 1 0 1     1
// 1 0 1 0     4
// 0 1 0 0     3
// 1 0 0 0
// 2


#include<stdio.h>
int stack[10],top=-1,temp=-1;
void pop();
int find(int e)
{
    if(top==-1)
    return 0;
    else
    {
        int flag=0;
        for(int i=0;i<=top;i++)
        {
            if(stack[i]==e)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        return 1;
        else
        return 0;
    }
}
int push(int e)
{
    if(find(e)==0)
    {
        top++;
        temp=top;
        stack[top]=e;
        printf("%d\n",e);
        return 1;
    }
    else
    return 0;
}
void compute(int s,int n,int a[][n])
{
    push(s);
    int flag=0;
    for(int j=0;j<n;j++)
    {
        if(a[s-1][j]==1)
        {
            if(push(j+1)==1)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    pop(n,a,temp);
    else
    compute(stack[top],n,a);
}
void pop(int n,int a[][n])
{
    temp--;
    if(temp>=0)
    compute(stack[temp],n,a);
}
int main()
{
    int n,s;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    scanf("%d",&s);
    compute(s,n,a);
}
