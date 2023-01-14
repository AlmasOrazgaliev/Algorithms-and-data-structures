#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][3];
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i][0];
        a[i][1]=cnt+1;
        cnt++;
        cnt+=a[i][0]-1;
        a[i][2]=cnt;
    }
    int x;
    for(int i=0;i<m;i++){
        cin>>x;
        // for(int j=0;j<n;j++){
        //     if(a[j][1]<=x && x<=a[j][2]){
        //         cout<<j+1<<endl;
        //         break;
        //     }
        // }
        int l=0;
        int r=n-1;
        int mid;
        while(l<=r){
            mid = (l+r)/2;
            if(a[mid][1]<=x && x<=a[mid][2]){
                cout<<mid+1<<endl;
                break;
            }
            if(a[mid][1]>x){
                r=mid-1;
            }
            else if(a[mid][2]<x){
                l=mid+1;
            }
        }
    }
}