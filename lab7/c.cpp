#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int n,int low,int high,int mid){
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
void merge_sort(int a[],int n,int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(a,n,low,mid);
        merge_sort(a,n,mid+1,high);
        merge(a,n,low,high,mid);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    merge_sort(a,n,0,n-1);
    merge_sort(b,m,0,m-1);
    int last=0;
    for(int i=0;i<n;i++){
        int l=last;
        int r=m-1;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(b[mid]>=a[i]){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(b[l]==a[i]){
            cout<<a[i]<<" ";
            last=l+1;
        }
    }
}