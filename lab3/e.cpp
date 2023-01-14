#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,pair<long long,pair<long long,long long>>>> a;
long long n;
long long sheeps(long long mid){
    long long cnt=0;
    for(long long i=0;i<n;i++){
        if(a[i].first<=mid && a[i].second.first<=mid && a[i].second.second.first<=mid && a[i].second.second.second<=mid){
            cnt++;
        }
    }
    //cout<<cnt<<endl;
    return cnt;
}
int main(){
    cin>>n;
    long long k;
    cin>>k;
    long long x,y,x2,y2;
    for(long long i=0;i<n;i++){
        cin>>x>>y>>x2>>y2;
        a.push_back(make_pair(x,make_pair(y,make_pair(x2,y2))));
        //cout<<a[i].first<<" "<<a[i].second.first<<" "<<a[i].second.second.first<<" "<<a[i].second.second.second<<" "<<endl;
    }
    long long l=0;
    long long r=1e11;
    long long mid;
    while(l<=r){
        mid=(l+r)/2;
        if(sheeps(mid)<k){
            l=mid+1;
        }else{
            r=mid-1;
        }
        //cout<<l<<" "<<r<<" "<<mid<<endl;
    }
    cout<<l;
}