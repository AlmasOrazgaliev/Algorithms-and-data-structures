#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<int> g;
int dsuGet(int v) {
	if (v == g[v]) {
		return v;
	}
	return g[v] = dsuGet(g[v]);
}

bool dsuUnite(int a, int b) {
	a = dsuGet(a);
	b = dsuGet(b);
	if (a != b) {
        g[a] = b;
        return true;
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n);
    a.resize(n);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        g[i]=i;
    }
    unordered_set<int> s;
    vector<int> res;
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        res.push_back(cnt);
        cnt++;
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]>i && dsuUnite(i,a[i][j])){
                cnt--;
            }
        }
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}