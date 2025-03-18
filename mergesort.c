#include<stdio.h>
#include<time.h>
int a[300];
int n;
void simple_merge(int a[],int low,int mid,int high);
void merge_sort(int a[],int low,int high){
if(low<high){
int mid=(low+high)/2;
merge_sort(a,low,mid);
merge_sort(a,mid+1,high);
simple_merge(a,low,mid,high);

}}
void simple_merge(int a[],int low,int mid,int high){
int i=low;int k=low;int j=mid+1;
int c[high+1
];
while(i<=mid && j<=high){
if(a[i]<a[j]){
c[k++]=a[i];
i++;}
else{
c[k++]=a[j];
j++;
}
}
while(i<=mid){
c[k++]=a[i];
i++;}
while(j<=high){
c[k++]=a[j];
j++;}
for(i=low;i<high;i++){
a[i]=c[i];}
}
int main(){
int i;
clock_t start,end;
double time_taken;
printf("enter the no of elements");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("enter array elements");
scanf("%d",&a[i]);}
start=clock();
merge_sort(a,0,n-1);
end=clock();
time_taken=(double)(end-start)/CLOCKS_PER_SEC;
printf("sorted array");
for(i=0;i<n;i++){
printf("%d",a[i]);}
printf("time taken is %d",time_taken);}
