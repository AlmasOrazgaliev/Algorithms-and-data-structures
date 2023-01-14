#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int n, int low, int high, int mid){
    int i,j,k;
    int b[n];
    i=low;
    k=low;
    j=mid+1;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            k++;i++;
        }else{
            b[k]=a[j];
            k++;j++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        k++;i++;
    }
    while(j<=high){
        b[k]=a[j];
        k++;j++;
    }
    for(i=low;i<k;i++){
        a[i]=b[i];
    }
}
void merge_sort(int a[],int n,int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(a,n,low,mid);
        merge_sort(a,n,mid+1,high);
        merge(a,n,low,high,mid);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int c[n+m];
    for(int i=0;i<n;i++){
        c[i]=a[i];
    }
    for(int i=n;i<m+n;i++){
        c[i]=b[i-n];
    }
    merge_sort(c,n+m,0,n+m-1);
    for(int i=0;i<n+m;i++){
        cout<<c[i]<<" ";
    }
}