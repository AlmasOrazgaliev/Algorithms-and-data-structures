#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n);
    vector<bool> used;
    used.resize(n, 0);
    vector<int> cnt;
    cnt.resize(n,0);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;
        y--;
        a[x].push_back(y);
        //used[y]=1;
        cnt[y]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(cnt[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        for(int i=0;i<a[q.front()].size();i++){
            cnt[a[q.front()][i]]--;
            if(cnt[a[q.front()][i]]==0){
                q.push(a[q.front()][i]);
            }
        }
        //cout<<q.front()<<" ";
        ans.push_back(q.front()+1);
        q.pop();
    }
    if(ans.size()==n){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible";
        return 0;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    
}