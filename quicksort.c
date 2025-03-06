#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int arr[],int low,int high){
int pivot =arr[low];
int i=low+1;
int j=high;
int temp;
while(1)
{
while(i<=high && arr[i]<=pivot)
i++;
while(arr[j]>pivot)
j--;
if(i<j)
{
temp=arr[i]; arr[i]=arr[j];arr[j]=temp;
}
else{
temp=arr[low];
arr[low]=arr[j];
arr[j]=temp;
return j;
}}}
int quickSort(int arr[],int low,int high)
{
if(low<high)
{
int pi=partition(arr,low,high);
quickSort(arr,low,pi-1);
quickSort(arr,pi+1,high);
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
a[i]=rand()%80000;
clock_t start =clock();
quickSort(a ,low,high);
clock_t end=clock();
printf("sorted elements:\n");
for(i=0;i<10;i++)
printf("%d ",a[i]);

double time=((double)(end-start))/CLOCKS_PER_SEC;
printf("the time taken is %f\n",time);
}
