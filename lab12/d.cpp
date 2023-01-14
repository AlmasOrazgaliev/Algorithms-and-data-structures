#include<bits/stdc++.h>
using namespace std;
vector<bool> used;
vector<pair<int,int>> coor;
vector<vector<int>> g;
priority_queue <int, vector<int>, greater<int> > pq;
void dfs (int v, int max,int n) {
    if(v==n-1){
        pq.push(max);
    }
	for (int i=0; i<g[v].size(); ++i){
            //cout<<g[v][i]<<" "<<coor[g[v][i]].first<<" "<<coor[g[v][i]].second<<" "<<coor[v].first<<" "<<coor[v].second<<endl;
            if((abs(coor[g[v][i]].first-coor[v].first)+abs(coor[g[v][i]].second-coor[v].second))>max){
                max = (abs(coor[g[v][i]].first-coor[v].first)+abs(coor[g[v][i]].second-coor[v].second));
            }
			dfs (g[v][i],max,n);
    }
}
int main(){
    int n;
    cin>>n;
    g.resize(4);
    used.resize(4,false);
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        coor.push_back({x,y});
        for(int j=i+1;j<n;j++){
            g[i].push_back(j);
        }
    }
    
    dfs(0,0,n);
    cout<<pq.top();
}