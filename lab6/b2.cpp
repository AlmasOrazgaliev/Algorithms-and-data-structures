#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high){
    int pivot = a[high]; 
    int i= (low- 1); 
  
    for (int j = low; j < high ; j++) {
        if((int)a[j]<(int)pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
} 

void quickSort(int a[], int low, int high){
    if (low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
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
    quickSort(a,0,n-1);
    quickSort(b,0,m-1);
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