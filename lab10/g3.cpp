#include<bits/stdc++.h>
using namespace std;
vector < vector<int> > a;
int n; 
vector<bool> used;
vector<int> ans;
bool ok = false;
int excep = 0;
bool dfs (int v) {
    if(a[v].size()!=0){
        used[v] = true;
        ans.push_back(v);
    }else{
        return false;
    }
	for (int i=0; i<a[v].size(); ++i){
		if (!used[a[v][i]]){
            return dfs(a[v][i]);
        }else{
            return true;
        }
    }
    return false;
}
bool dfs_2(int v){
    if(a[v].size()!=0){
        used[v] = true;
    }else{
        return false;
    }
	for (int i=0; i<a[v].size(); ++i){
		if (!used[a[v][i]]){
            return dfs(a[v][i]);
        }else{
            return true;
        }
    }
    return false;
}
int del;
int del2;
// ищу есть ли цикл
bool check(){
    used.clear();
    used.resize(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i].size();j++){
            if(dfs_2(a[i][j])){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int m;
    cin>>n>>m;
    a.resize(n);
    used.resize(n,0);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);
    }
    vector<vector<int>> res;
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i].size();j++){
            ans.push_back(i);
            if(dfs(a[i][j])){
                for(int k=0;k<ans.size();k++){
                    cout<<ans[k]<<" "; // просто что бы чекнутб что есть
                }
                for(int k=0;k<ans.size()-1;k++){
                    del = ans[k];
                    del2 = ans[k+1]; // удаляю ребро
                    for(int l=0;l<a[del].size();l++){
                        if(a[del][l]==del2){
                            a[del].erase(a[del].begin()+l);
                        }
                    }
                    if(!check()){
                        cout<<"YES";
                        return 0;
                    }
                    a[del].push_back(del2);
                }
                cout<<"NO";
                return 0;
                used.clear();
                res.push_back(ans);
                used.resize(n,0);
                ans.clear();
            }else{
                used.clear();
                used.resize(n,0);
                ans.clear();
            }
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<res.size()<<endl;
    cout<<"NO";
}