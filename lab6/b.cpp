#include<bits/stdc++.h>
using namespace std;
void heapify(int a[], int i, int n){
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;
    if(left<n && a[largest]<a[left]){
        largest=left;
    }
    if(right<n && a[largest]<a[right]){
        largest=right;
    }
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,largest,n);
    }
}
void heap_sort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    int *b= new int[m];
    int size=1;
    int *arr= new int[size];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    heap_sort(a,n);
    heap_sort(b,m);
    int start=0;
    for(int i=0;i<n;i++){
        int l=start;
        int r=m-1;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(b[mid]<a[i]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        if(b[l]==a[i]){
            arr[size-1]=a[i];
            start=mid+1;
            size++;
        }
    }
    for(int i=0;i<size-1;i++){
        cout<<arr[i]<<" ";
    }
    delete [] arr;
}