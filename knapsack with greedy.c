#include<stdio.h>
#define MAX_ITEMS 100
double computeMaxValue(double w, double wt[],double val[],double ratio[],int n);
int get(double wt[],double val[],double ratio[],int n);
int main(){
int n,i;
double w,wt[MAX_ITEMS],val[MAX_ITEMS],ratio[MAX_ITEMS];
printf("Enter the number of items");
scanf("%d",&n);
printf("Enter the weights of the item");

for(i=0;i<n;i++){
scanf("%lf",&wt[i]);}
printf("Enter the value of the item");
for(i=0;i<n;i++)
scanf("%lf",&val[i]);
for(i=0;i<n;i++)
ratio[i]=val[i]/wt[i];
printf("Enter the capacity ");
scanf("%lf",&w);

printf("The maximum value in knapsack of capacity %.2f is: %.2f\n",w,computeMaxValue(w,wt,val,ratio,n));
return 0;
}
double computeMaxValue(double w, double wt[],double val[],double ratio[],int n){
 double cw=0,cv=0;
printf("\n Items are:");
while(cw<w){
int item =get(wt,val,ratio,n);
if(item==-1)
break;
printf("%d ",item+1);
if(cw+wt[item]<=w){
cw+= wt[item];
cv+=val[item];
ratio[item]=0;
}
else{
cv+=(ratio[item]*(w-cw));
cw+=(w-cw);
break;
}
}
return cv;
}
int get(double wt[],double val[],double ratio[],int n)
{
int i;
double highest=0;
int index=-1;
for( i=0;i<n;i++){
if(ratio[i]>highest){
highest=ratio[i];
index=i;
}
}
return index;
}
