#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<-1<<" ";
    for(int i=1;i<n;i++){
        int cnt=0;
        for(int j=i-1;j>=0;j--){
            if(a[i]>=a[j]){
                cout<<a[j]<<" ";
                break;
            }
            cnt++;
        }
        if(cnt==i){
            cout<<-1<<" ";
        }
    }
}