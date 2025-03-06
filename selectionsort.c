#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionSort(int arr[],int n){
int i,j,minIndex;
for( i=0;i<n-1;++i)
{
int minIndex=i;
for( j=i+1;j<n;++j)
{
if(arr[j]<arr[minIndex])
minIndex=j;
}

if( minIndex!=i)
{
int temp=arr[i];
arr[i]=arr[minIndex];
arr[minIndex]=temp;
}
}
}
int main()
{
int i;
int n;
printf("Enter the number of elemnts");
scanf("%d",&n);
int arr[n];
srand(time(NULL));
for( i=0;i<n;++i)
arr[i]=rand()%10000;
clock_t start=clock();
selectionSort(arr,n);
printf("\n the sorted elments are :");
for( i=0;i<10;i++)
printf("%d ",arr[i]);
clock_t end =clock();
double time_taken= ((double)(end-start))/CLOCKS_PER_SEC;
printf("Time taken for sorting :%f seconds\n",time_taken);
return 0;
}
