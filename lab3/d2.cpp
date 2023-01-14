#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int forR(int x, int l, int r){
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]>x){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<r<<" ";
    return r;
}
int forL(int x, int l, int r){
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]<x){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<l<<" ";
    return l;
}
int main(){
    int n,q;
    cin>>n>>q;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<q;i++){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int cnt1=0;
        int cnt2=0;
        int l=0;
        int r=n-1;
        cnt1=forR(r1,l,r)-forL(l1,l,r)+1;
        cnt2=forR(r2,l,r)-forL(l2,l,r)+1;
        cout<<cnt1+cnt2<<endl;
    }
}