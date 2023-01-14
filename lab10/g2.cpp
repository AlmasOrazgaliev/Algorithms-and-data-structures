#include <bits/stdc++.h>
using namespace std;
vector<int> a[505];
int used[505];
stack<int> s;
vector<int> ans;
bool dfs(int v,int x,int y) {
    used[v]=1;
    for (int i=0;i<a[v].size();i++) {
        if(v==x && y==a[v][i]) continue;
        if(!used[a[v][i]]){
            if (dfs(a[v][i],x,y)) return true;
        }
        else if(used[a[v][i]]==1){
            return true;
        }
    }
    used[v] = 2;
    return false;
}
bool dfs2(int v) {
    used[v]=1;
    s.push(v);
    for (int i=0;i<a[v].size();i++) {
        if(!used[a[v][i]]){
            if (dfs2(a[v][i])) return true;
        }
        else if(used[a[v][i]]==1) {
            while(s.top()!=a[v][i]){
                ans.push_back(s.top());
                s.pop();
            }
            ans.push_back(a[v][i]);
            ans.push_back(v);
            reverse(ans.begin(), ans.end());
            return true;
        }
    }
    used[v] = 2;
    if (!s.empty()) s.pop();
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y; 
        cin>>x>>y;
        a[x].push_back(y);
    }
    bool ok = false;
    for(int i=1; i<=n;i++){
        if (!used[i]) {
            ok=dfs2(i);
            if (ok) break;
        }
    }
    if(!ok){
        cout<<"YES"<<endl;
        return 0;
    }
    for(int i=0;i<ans.size()-1;i++) {
        int x=ans[i];
        int y=ans[i+1];
        for(int j=1;j<=n;j++){
            used[j]=0;
        }
        ok=0;
        for(int j=1;j<=n;j++){
            if(!used[j]){
                ok |= dfs(j,x,y);
            }
        }
        if(!ok){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}