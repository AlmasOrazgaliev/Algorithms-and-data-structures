#include<iostream> 
using namespace std; 
void heapify(long long arr[], int n, int i)  
{  
    int largest = i;  
    int l = 2 * i + 1;  
    int r = 2 * i + 2;  
  
    if (l < n && arr[l] > arr[largest])  
        largest = l;  
   
    if (r < n && arr[r] > arr[largest])  
        largest = r;  
   
    if (largest != i) {  
        swap(arr[i], arr[largest]);  
        heapify(arr, n, largest);  
    }  
}  
void heapify2(long long arr[], int n, int i)  
{  
    int min = i;  
    int l = 2 * i + 1;  
    int r = 2 * i + 2;  
  
    if (l < n && arr[l] < arr[min])  
        min = l;  
   
    if (r < n && arr[r] < arr[min])  
        min = r;  
   
    if (min != i) {  
        swap(arr[i], arr[min]);  
        heapify2(arr, n, min);  
    }  
}  
void heapSort(long long arr[], int n)  
{  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(arr, n, i);  
   
    for (int i = n - 1; i >= 0; i--) {  
        swap(arr[0], arr[i]);  
        heapify(arr, i, 0);  
    }  
}  
int main(){ 
    long long n; 
    cin>>n; 
    long long a[n]; 
    int x; 
    cin>>x; 
    for(int i=0;i<n;i++){ 
        cin>>a[i]; 
    } 
    heapSort(a,n); 
    if(a[0]==0){ 
        cout<<-1; 
        return 0; 
    } 
    int cnt=0; 
    //print(a,n);
    int size=n; 
    for(int i=0;i<n-1;i++){ 
        if(a[0]>=x){ 
            break; 
        } 
         int sum=0;
        sum=2*a[0]; 
        //a[i-1]=a[i]*2+a[i-1]; 
        a[0]=0; 
        size--; 
        swap(a[0],a[size]); 
        heapify2(a,size,0); 
          
        a[0]+=sum; 
        //size--;
        heapify2(a,size,0); 
        cnt++; 
        //print(a,i); 
    } 
    if(a[0]<x){ 
        cout<<-1; 
        return 0; 
    } 
    cout<<cnt; 
}