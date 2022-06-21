// Consider a Graph G Perform Breadth First Traversal on the given graph. Vertices of the graph goes like 1, 2, 3 ...... n.

// Input :

// n - Integer - number of vertices

// nxn - adjacency matrix for the graph G

// m - Integer - starting vertex

// Output:

// List of n vertices - BFS Order.

// For example:

// Input	     Result
// 4            2
// 0 1 0 1      1
// 1 0 1 0      3
// 0 1 0 0      4
// 1 0 0 0
// 2


#include<stdio.h>
int q[20],f=-1,r=-1;
int find(int e)
{
    if(r==-1)
    return 0;
    else
    {
        int flag=0;
        for(int i=0;i<=r;i++)
        {
            if(q[i]==e)
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
void enqueue(int e)
{
    if(find(e)==0)
    {   
        r++;
        q[r]=e;
        if(f==-1)
        f=0;
    }
}
void dequeue()
{
    printf("%d\n",q[f]);
    f++;
}
void compute(int s,int n,int a[][n])
{
    enqueue(s);
    for(int j=0;j<n;j++)
    {
        if(a[s-1][j]==1)
        enqueue(j+1);
    }
    dequeue();
    if(f<=r)
    compute(q[f],n,a);
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
