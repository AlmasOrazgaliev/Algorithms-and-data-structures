#include<bits/stdc++.h>
using namespace std;
void royal(int n){
    deque<int> dq;
    int cop=0; //213->4213
    for(int i=n;i>=1;i--){
        dq.push_front(i);
        for(int j=0;j<i;j++){
            cop=dq.back();
            dq.pop_back();
            dq.push_front(cop);
        }
    }
    for(auto &it:dq){
        cout<<it<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        royal(a[i]);
    }
}