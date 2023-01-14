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
long long ghoul2(long long mid,long long n){
    long long sum=0;
    long long cnt=0;
    long long maxSum=0;
    for(long long i=0;i<n;i++){
        sum+=a[i];
        if(sum>mid){
            cnt++;
            if(maxSum<sum-a[i]){
                maxSum=sum-a[i];
            }
            sum=a[i];
        }
        else if(sum==mid){
            cnt++;
            if(maxSum<sum){
                maxSum=sum;
            }
            sum=0;
        }
    }
    if(maxSum==0){
        maxSum=sum;
    }
    return maxSum;
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
        if(ghoul(mid,n)>k-1){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ghoul2(l,n);
}