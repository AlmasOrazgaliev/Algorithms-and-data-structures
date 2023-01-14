#include<iostream>
using namespace std;
void heapify2(long long arr[],long long n,long long i){
    long long largest=i;
    long long l=2*i+1;
    long long r=2*i+2;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify2(arr,n,largest);
    }
}
void heapify(long long arr[],long long n,long long i){
    long long largest=i;
    long long l=2*i+1;
    long long r=2*i+2;
    if(l<n && arr[l]<arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]<arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void hearSort(long long arr[],long long n){
    for(long long i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(long long i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void printArr(long long arr[],long n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    long long n;
    cin>>n;
    long long a[n];
    long long x;
    cin>>x;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    hearSort(a,n);
    long long sum=0;
   // printArr(a,n);
    //cout<<endl;
    while(x!=0){
        sum+=a[0];
        a[0]--;
        x--;
        heapify2(a,n,0);
        //printArr(a,n);
        //cout<<endl;
    }
    cout<<sum;
}