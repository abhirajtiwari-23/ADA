#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 50000

void merge_sort(a,low,high){
if (low<high){
    mid=(low+high)/2;
    merge_sort(a,mid+1,high);
    merge_sort(a,low,mid);
    merge(a,low,mid.high);
}

}
void merge(a,low,mid,high){
    i=low,j=mid+1,k=low;
    int b[];
    while(i<=mid && j<=high){
        if (a[i]<=a[j])
        b[k+1]=a[i+1];
        else
            b[k+1]=a[j+1];
    }
    while(i<=mid){
        b[k+1]=a[k+1];
    }
    while(j<=high){
        b[k+1]=a[j+1];
    }
    for(int i=low;i<high;i++)
        a[i]=b[i];
}
int main(){
int n,k;
clock_t start,end;
double time_taken;
srand
}
