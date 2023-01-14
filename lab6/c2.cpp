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
    int n;
    cin>>n;
    int size=1;
    int a[n];
    int b[n-1][2];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quickSort(a,0,n-1);
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