#include<iostream>
using namespace std;
int partition(int a[], int low, int high){
    int pivot = a[high]; 
    int i= (low- 1); 
  
    for (int j = low; j < high ; j++) {
        if((int)a[j]>(int)pivot){
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
    int a[m][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[j][i];
        }
    }
    for(int i=0;i<m;i++){
        quickSort(a[i],0,n-1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }

}