#include <bits/stdc++.h>
using namespace std;
void heapify(long long arr[], long long n, long long i)
{
    long long largest = i;
    long long l = 2 * i + 1;
    long long r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapify2(long long arr[], long long n, long long i)
{
    long long min = i;
    long long l = 2 * i + 1;
    long long r = 2 * i + 2;

    if (l < n && arr[l] < arr[min])
        min = l;
 
    if (r < n && arr[r] < arr[min])
        min = r;
 
    if (min != i) {
        swap(arr[i], arr[min]);
        heapify2(arr, n, min);
    }
}
void heapSort(long long arr[], long long n)
{
    for (long long i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (long long i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
 
void printArray(long long arr[], long long n)
{
    for (long long i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
int main()
{
    long long n;
    cin>>n;
    long long a[n];
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    heapSort(a,n);
    //prlong longArray(a,n);
    long long size=n;
    long long temp=0;
    for(long long i=0;i<n-1;i++){
        long long temp=0;
        temp=a[0];
        a[0]=0;
        size--;
        swap(a[0],a[size]);
        heapify2(a,size,0);
        //prlong longArray(a,n);
        a[0]+=temp;
        //size--;
        heapify2(a,size,0);
        //prlong longArray(a,n);
    }
    cout<<a[0];
}