#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int low,int mid,int high)
{
int c[1000000];
int i=low,j=mid+1,k=low;
while(i<=mid&&j<=high)
{
if(a[i]<a[j])
{
c[k]=a[i];
i++;
}
else{
c[k]=a[j];
j++;
}
k++;
}
while(i<=mid)
c[k++]=a[i++];
while(j<=high)
c[k++]=a[j++];
for(i=low;i<=high;i++)
a[i]=c[i];
}
void mergesort(int a[],int low,int high)
{
if(low<high)
{
int mid=(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,mid,high);
}
}

void main()
{
int n,i;
printf("Enter the number of elements\n");
scanf("%d",&n);
int a[n];
int low=0,high=n-1;
srand(time(NULL));
for(i=0;i<n;i++)
a[i]=rand()%25000;
clock_t start =clock();
mergesort(a ,low,high);
clock_t end=clock();
printf("sorted elements:\n");
for(i=0;i<10;i++)
printf("%d ",a[i]);

double time=((double)(end-start))/CLOCKS_PER_SEC;
printf("the time taken is %f",time);
}
