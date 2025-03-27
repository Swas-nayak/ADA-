#include<stdio.h>
void readgraph(int n,int a[10][10])
{
int i,j;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
}
}
void find_in(int n,int a[10][10],int indegree[])
{
int i,j,sum;
for(j=0;j<n;j++)
{
sum=0;
for(i=0;i<n;i++)
sum+=a[i][j];
indegree[j]=sum;
}
}
void topo(int n, int a[10][10])
{
int k=0;
int i,u,v,top,t[10],indegre[10],s[10];
find_in(n,a,indegre);
top=-1;
for(i=0;i<n;i++)
{
if(indegre[i]==0)
s[++top]=i;
}
while(top!=-1)
{
u=s[top--];
t[k++]=u;
for(v=0;v<n;v++)
{
if(a[u][v]==1)
{
indegre[v]--;
if(indegre[v]==0)
{
s[++top]=v;
}
}
}
}
printf("The topo order: ");
for(i=0;i<n;i++)
printf("%d",t[i]);
}
void main()
{
int n,a[10][10];
printf("\n Enter number of values");
scanf("%d",&n);
printf("\n Enter adjacency matrix");
readgraph(n,a);
topo(n,a);
}

