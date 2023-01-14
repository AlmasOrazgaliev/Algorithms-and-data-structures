#include <bits/stdc++.h> 
#include <vector> 
#include <set> 
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
int INF = 1000000000; 
vector<pair<int,int>> g[200005]; 
vector<int> d(200005, INF); 
int n,m; 

int deikstra(int s, int end){ 
    d.clear(); 
    for(int i=0;i<200005;i++){ 
        d[i] = INF; 
    } 
    d[s] = 0; 
    set< pair<int,int> > q; 
    q.insert(make_pair(d[s],s)); 
    while(!q.empty()){ 
        int v = q.begin()->second; 
        q.erase(q.begin()); 
        for(int j = 0;j<g[v].size();j++){ 
            int to = g[v][j].first; 
            int len = g[v][j].second; 
            if(d[v] + len < d[to]){ 
         q.erase(make_pair(d[to], to)); 
         d[to] = d[v] + len; 
         q.insert(make_pair(d[to], to)); 
            } 
        } 
    } 
    return d[end]; 
} 



int main(){ 
    cin >> n >> m; 
    for (int i = 0; i < m; i++){ 
        int a,b,c; 
        cin >> a >> b >> c; 
        g[a].push_back({b,c}); 
        g[b].push_back({a,c}); 
    } 
    int q,w,e,r; 
    cin >> q >> w >> e >> r; 
    int a,b; 
    a = deikstra(q,w) + deikstra(w,e) + deikstra(e,r); 
    b = deikstra(q,e) + deikstra(e,w) + deikstra(w,r) ; 
    if(min(a,b) <= INF){ 
        cout << min(a,b); 
    }else{ 
        cout << -1; 
    } 
    return 0; 
}
