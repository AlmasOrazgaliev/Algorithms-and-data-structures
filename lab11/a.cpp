#include <bits/stdc++.h>
using namespace std;
 
class DSU {
    long long* parent;
    long long* rank;
 
public:
    DSU(long long n)
    {
        parent = new long long[n];
        rank = new long long[n];
 
        for (long long i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
 
    long long find(long long i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }
 
    void unite(long long x, long long y)
    {
        long long s1 = find(x);
        long long s2 = find(y);
 
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};
 
class Graph {
    vector<vector<long long> > edgelist;
    long long V;
 
public:
    Graph(long long V) { this->V = V; }
 
    void addEdge(long long x, long long y, long long w)
    {
        edgelist.push_back({ w, x, y });
    }
 
    void kruskals_mst()
    {
        sort(edgelist.begin(), edgelist.end());
 
        DSU s(V);
        long long ans = 0;
        for (auto edge : edgelist) {
            long long w = edge[0];
            long long x = edge[1];
            long long y = edge[2];
 
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
 
        cout << ans;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> g;
    int cnt = 2;
    int x,y,w;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        g.push_back({w,{x,y}});
    }
    long long sum = 0;
    sort(g.begin(),g.end());
    while(cnt<=n){
        for(int i=0;i<g.size();i++){
            int x = g[i].second.first;
            int y = g[i].second.second;
            int w = g[i].first;
            if(x < cnt && cnt <= y){
                sum += w;
                cnt++;
                break;
            }
        }
    }
    cout << sum;
    return 0;
}
