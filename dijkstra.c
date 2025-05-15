#include<stdio.h>
#include<limits.h>
#define MAX 20
#define INF 999
int dist[MAX];
int visited[MAX];
int path[MAX];
int source;
void dijkstra(int n,int graph[MAX][MAX]);
int minDis(int n);
void printShortest(int n);
void printPath(int path[],int j);
int main(){
int i,j,n;
int graph[MAX][MAX];
printf("Enter the number of nodes:");
scanf("%d",&n);
printf("Enter the weight matrix\n");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
scanf("%d",&graph[i][j]);
}}
printf("Enter the source vertex:");
scanf("%d",&source);
dijkstra(n,graph);
printShortest(n);
return 0;
}
void dijkstra(int n,int graph[MAX][MAX]){
int i,u,v;
for(i=1;i<=n;i++){
visited[i]=0;
}
visited[source]=0;
for(i=1;i<=n;i++)
dist[i]=graph[source][i];
for(i=1;i<=n;i++)
path[i]=source;
path[source]=-1;
for(i=1;i<=n;i++){
u=minDis(n);
visited[u]=1;
for(v=1;v<=n;v++){
if(!visited[v]&&graph[u][v]&&dist[u]!=INF && dist[u] +graph[u][v]<dist[v]){
dist[v]=dist[u]+graph[u][v];
path[v]=u;
}
}
}
}
int minDis(int n){
int min= INF,minIndex=-1,i;
for(i=1;i<=n;i++){
if(visited[i]==0&&dist[i]<=min){
min=dist[i];
minIndex=i;
}
}
return minIndex;
}
void printShortest(int n){
int i;
for(i=1;i<=n;i++){
if(i!=source){
printf("The shortest distance from node %d to %d =%d\n",source,i,dist[i]);
printf("The shortest path fron=m node %d to %d is:",source,i);
printf("%d",source);
printPath(path,i);
printf("\n");
}
}
}
void printPath( int path[], int j){
if(path[j]==-1){
return;
}
printPath(path,path[j]);
printf("---->%d",j);
}
