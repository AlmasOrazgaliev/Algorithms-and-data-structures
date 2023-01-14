#include<iostream>
using namespace std;
void heapify(int a[],int n,int i){
    int min=i;
    int l=i*2+1;
    int r=i*2+2;
    if(l<n && a[l]<a[min]){
        min=l;
    }
    if(r<n && a[r]<a[min]){
        min=r;
    }
    if(min!=i){
        swap(a[i],a[min]);
        heapify(a,n,min);
    }
}
void heapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,n,0);
    }
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    string s;
    int a[k]{0};
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="insert"){
            int x;
            cin>>x;
            if(x>a[0]){
                a[0]=x;
            }
            heapify(a,k,0);
        }else{
            long long sum=0;
            for(int i=0;i<k;i++){
                sum+=a[i];
            }
            cout<<sum<<endl;
        }
    }
}