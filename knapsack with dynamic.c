#include<stdio.h>
#define MAX_ITEMS 10
int knapSack(int w,int wt[],int val[],int n);
int max(int a,int b);
int main(){
int i,n,w,wt[MAX_ITEMS],val[MAX_ITEMS];
printf("Enter the number of items");
scanf("%d",&n);
printf("Enter the weights of the item");
for(i=1;i<=n;i++){
scanf("%d",&wt[i]);}
printf("Enter the value of the item");
for(i=1;i<=n;i++)
scanf("%d",&val[i]);
printf("Enter the capacity ");
scanf("%d",&w);

printf("The maximum value in knapsack of capacity %d is: %d\n",w,knapSack(w,wt,val,n));
return 0;
}
int knapSack(int w,int wt[],int val[],int n){
int i,j;
int v[MAX_ITEMS+1][w+1];
for(i=0;i<=n;i++){
for(j=0;j<=w;j++){
if(i==0||j==0)
v[i][j]=0;
else if(j-wt[i]<0)
v[i][j] =v[i-1][j];
else
v[i][j]=max(v[i-1][j],val[i]+v[i-1][j-wt[i]]);
}
}

return v[n][w];
}
int max(int a,int b){
return (a>b)?a:b;
}
