#include <bits/stdc++.h> 
#include <vector> 
#include <queue> 
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
vector<int>g_roadways[410]; 
vector<int>g_airlanes[410]; 
int ar[405][405]; 

int main(){ 
    int n,m; 
    cin >> n >> m; 
    for(int i=0;i<m;i++){ 
     int a,b; 
     cin >> a >> b; 
     a--; 
     b--; 
     g_roadways[a].push_back(b); 
     g_roadways[b].push_back(a); 
     ar[a][b] = 1; 
     ar[b][a] = 1; 
    } 
    for (int i = 0; i < n; i ++){ 
     for (int j = 0; j < n; j ++){ 
        if (ar[i][j] == 0 && i != j){ 
    g_airlanes[i].push_back(j); 
        } 
     } 
    } 
    queue<int>q1; 
    vector<int>d1(n+1); 
    vector<bool>used1(n+1); 
    q1.push(0); 
    used1[0] = true; 
    while(!q1.empty()){ 
     int v = q1.front(); 
     q1.pop(); 
     for(int i=0;i<g_roadways[v].size();i++){ 
        int to = g_roadways[v][i]; 
        if(!used1[to]){ 
    used1[to] = true; 
    q1.push(to); 
    d1[to] = d1[v]+1; 
        } 
     } 
    } 
    queue<int>q2; 
    vector<int>d2(n+1); 
    vector<bool>used2(n+1); 
    q2.push(0); 
    used2[0] = true; 
    while(!q2.empty()){ 
     int v = q2.front(); 
     q2.pop(); 
     for(int i=0;i<g_airlanes[v].size();i++){ 
        int to = g_airlanes[v][i]; 
        if(!used2[to]){ 
    used2[to] = true; 
    q2.push(to); 
    d2[to] = d2[v]+1; 
        } 
     } 
    } 
    if (!used1[n-1] || !used2[n-1]){ 
     cout << -1; 
    } 
    else { 
     cout << max(d1[n-1], d2[n-1]); 
    } 
}
