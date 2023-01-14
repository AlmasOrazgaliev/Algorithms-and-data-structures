#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n);
    int x,y;
    int min=100000;
    vector<bool> used;
    used.resize(n,0);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);
        used[y]=1; 
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(used[i]==0){
            cnt++;
        }
        for(int j=0;j<a[i].size();j++){
            if(a[a[i][j]].size()>a[i].size()){
                cnt++;
            }
        }
    }
    cout<<cnt;
}