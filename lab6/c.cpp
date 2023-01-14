#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int i,int n){
    int largest=i;
    int l=i*2+1;
    int r=2*i+2;
    if(l<n && a[largest]<a[l]){
        largest=l;
    }
    if(r<n && a[largest]<a[r]){
        largest=r;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,largest,n);
    }
}
void heap_sort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[i],a[0]);
        heapify(a,0,i);
    }
}
int main(){
    int n;
    cin>>n;
    int size=1;
    int a[n];
    int b[n-1][2];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    heap_sort(a,n);
    int min=pow(10,9);
    for(int i=0;i<n-1;i++){
        b[i][0]=a[i];
        b[i][1]=a[i+1];
        if(min>abs(a[i]-a[i+1])){
            min=abs(a[i]-a[i+1]);
        }
    }
    for(int i=0;i<n-1;i++){
        if(abs(b[i][0]-b[i][1])==min){
            cout<<b[i][0]<<" "<<b[i][1]<<" ";
        }
    }
}