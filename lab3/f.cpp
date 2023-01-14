#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int p;
    cin>>p;
    for(int i=0;i<p;i++){
        int m;
        cin>>m;
        int cnt=0;
        int sum=0;
        for(int j=0;j<n;j++){
            if(m>=a[j]){
                cnt++;
                sum+=a[j];
            }
        }
        cout<<cnt<<" "<<sum<<endl;
    }
}