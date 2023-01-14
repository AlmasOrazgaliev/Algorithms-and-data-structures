#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int check(int mid,int n){
    int time=0;
    for(int i=0;i<n;i++){
        time+=ceil((double)a[i]/mid);
    }
    return time;
}
int main(){
    int n;
    cin>>n;
    int h;
    cin>>h;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    int l,r,mid;
    l=1;
    r=*max_element(a.begin(),a.end());
    while(l<=r){
        mid=(l+r)/2;
        int steal_time=check(mid,n);
        if(steal_time>h){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
}