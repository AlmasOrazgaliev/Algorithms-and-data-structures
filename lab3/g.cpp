#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int check(int mid,int n){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=ceil((double)a[i]/mid);
    }
    return cnt;
}
int main(){
    int n,f;
    cin>>n>>f;
    int x;
    int max=0;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
        if(max<x){
            max=x;
        }
    }
    int l=1;
    int r=max;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid,n)>f){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
}