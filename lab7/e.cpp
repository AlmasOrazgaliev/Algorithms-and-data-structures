#include<bits/stdc++.h>
using namespace std;
int heapify2(int **&a,int largest, int child, int n , int m){
    for(int i=0;i<m;i++){
        if(a[largest][i]<a[child][i]){
            return child;
        }
        if(a[largest][i]>a[child][i]){
            return largest;
        }
    }
}
void merge(int **&a, int b[],int n,int m, int low, int high, int mid){
    int i,j,k;
    int c[n];
    int **h = new int*[n];
    i=low;
    k=low;
    j=mid+1;
    while(i<=mid && j<=high){
        if(b[i]>b[j]){
            c[k]=b[i];
            h[i]=a[i];
            k++;i++;
        }
        else if(b[i]==b[j]){
            if(heapify2(a,i,j,n,m)==i){
                c[k]=b[j];
                h[k]=a[j];
                k++;j++;
            }else{
                c[k]=b[i];
                h[k]=a[i];
                k++;i++;
            }
        }else{
            c[k]=b[j];
            h[k]=a[j];
            k++;j++;
        }
    }
    while(i<=mid){
        c[k]=b[i];
        h[k]=a[i];
        k++;i++;
    }
    while(j<=high){
        c[k]=b[j];
        h[k]=a[j];
        k++;j++;
    }
    for(i=low;i<k;i++){
        b[i]=c[i];
        a[i]=h[i];
    }
}
void merge_sort(int **&a, int b[],int n,int m,int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(a,b,n,m,low,mid);
        merge_sort(a,b,n,m,mid+1,high);
        merge(a,b,n,m,low,high,mid);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int **a = new int*[n];
    int sum[n];
    for(int i=0;i<n;i++){
        a[i] = new int[m];
        int s=0;
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            s+=a[i][j];
        }
        sum[i]=s;
    }
    merge_sort(a,sum,n,m,0,n-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
        delete[] a[i];
    }
    delete[] a;
}