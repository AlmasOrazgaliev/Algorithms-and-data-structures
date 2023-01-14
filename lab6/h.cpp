#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char c[n];
    char x;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    cin>>x;
    int l=0;
    int r=n-1;
    int mid;
    if((int)x>=(int)c[n-1]){
        cout<<c[0];
        return 0;
    }
    while(l<=r){
        mid=(l+r)/2;
        if((int)c[mid]>(int)x){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<c[l];
}