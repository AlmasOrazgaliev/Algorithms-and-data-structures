#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    for(int i=0;i<q;i++){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int cnt=0;
        for(int j=0;j<n;j++){
            if(l1<=a[j] && a[j]<=r1){
                cnt++;
                continue;
            }
            if(l2<=a[j] && a[j]<=r2){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}