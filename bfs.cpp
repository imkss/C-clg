#include<stdio.h>
int q[20],f=-1,r=-1;
typedef struct{
    int col;
    int d;
    int pi;
}node;
int isEmpty()
{
    if(f==-1&&r==-1)
        return 1;
    else
        return 0;
}
void Enqueue(int k)
{
    if(f==-1&&r==-1)
    {
        f=r=0;
        q[f]=k;
    }
    else{
        r=(r+1)%10;
        q[r]=k;
    }
}
int Dequeue(){
    int ret;
    if(f==r){
        ret=q[f];
        f=r=-1;
    }
    else{
        ret=q[f];
        f=(f+1)%10;
    }
    return ret;
}
void bfs(int g[][30],int n,node *v,int start)
{
    for(int i=0;i<n;i++)
    {
        if(i!=start)
        {
            v[i].col=0;
            v[i].d=35555;
            v[i].pi=-1;
        }
    }
    v[start].col=1;
    v[start].d=0;
    v[start].pi=-1;
    Enqueue(start);
    while(!isEmpty())
    {
        int u=Dequeue();
        for(int i=0;i<n;i++)
        {
            if(i!=u)
            {
                if(g[u][i]==1&&v[i].col==0)
                {
                    v[i].col=1;
                    v[i].d=v[u].d+1;
                    v[i].pi=u;
                    Enqueue(i);
                }
            }
        }
        v[u].col=2;
    }
}
int main()
{
    int n,startnode;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    int g[30][30]={0};
    node v[n];
    printf("Enter the start node:\n");
    scanf("%d",&startnode);
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    bfs(g,n,v,startnode);
    printf("\nNode\t\tDistance from source: %d\t\t Parent\n",startnode);
    for(int i=0;i<n;i++)
    {
        printf("Node:\n%d\t\t\t%d\t\t%d\t\t\t\t\n",i,v[i].d,v[i].pi);
    }
}
