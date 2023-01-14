#include<iostream>
using namespace std;
void heapify(int a[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[largest]>a[l]){
        largest=l;
    }
    if(r<n && a[largest]>a[r]){
        largest=r;
    }
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
void heap_sort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[i],a[0]);
        heapify(a,i,0);
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
        heap_sort(a[i],n);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }

}