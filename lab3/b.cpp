#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
long long ghoul(long long mid,long long n){
    long long sum=0;
    long long cnt=0;
    for(long long i=0;i<n;i++){
        sum+=a[i];
        if(sum>mid){
            cnt++;
            sum=a[i];
        }
        else if(sum==mid){
            cnt++;
            sum=0;
        }
    }
    return cnt;
}
int main(){
    long long n,k;
    cin>>n>>k;
    long long x;
    for(long long i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    long long l=1;
    long long r=1e11;
    long mid;
    long long cnt=0;
    while(l<=r){
        mid=(l+r)/2;
        //cout<<l<<" "<<r<<" "<<mid<<endl;
        if(ghoul(mid,n)>k-1){
            r=mid-1;
        }else{
            l=mid+1;
        }
        cout<<l<<" "<<r<<" "<<mid<<endl;
    }
    cout<<l;
}