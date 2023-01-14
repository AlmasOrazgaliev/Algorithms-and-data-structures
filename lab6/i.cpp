#include<bits/stdc++.h>
using namespace std;
void heapify(string & s,int i,int n){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && (int)s[largest]<(int)s[l]){
        largest=l;
    }
    if(r<n && (int)s[largest]<(int)s[r]){
        largest=r;
    }
    if(largest!=i){
        swap(s[i],s[largest]);
        heapify(s,largest,n);
    }
}
void heap_sort(string & s,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(s,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(s[0],s[i]);
        heapify(s,0,i);
    }
}
int main(){
    string s;
    cin>>s;
    heap_sort(s,s.size());
    cout<<s;
}