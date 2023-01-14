#include <bits/stdc++.h>
using namespace std;
#include <limits.h>
 
int INF = 1000000000; 
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
int minDistance(int dist[], bool sptSet[],int n)
{
 
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 

int dijkstra(int **&graph, int src,int n, int ans)
{
    int dist[n]; 
 
    bool sptSet[n];
 
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    dist[src] = 0;
 
    for (int count = 0; count < n-1; count++) {
        int u = minDistance(dist, sptSet,n);
 
        sptSet[u] = true;
 

        for (int v = 0; v < n; v++)
 
            
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    
    return dist[ans];
}
 
int main()
{
 
    int n,m;
    cin>>n>>m;
    int **a = new int *[n];
    for(int i=0;i<n;i++){
        a[i] = new int[n];
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    int graph[n][m];
    int x,y,w;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        x--;y--;
        a[x][y]=w;
        a[y][x]=w;
    }
    int q,t,e,r; 
    
    cin >> q >> t >> e >> r;
    q--;t--;e--;r--; 
    int ans1,ans2; 
    ans1 = dijkstra(a,q,n,t) + dijkstra(a,t,n,e) + dijkstra(a,e,n,r); 
    ans2 = dijkstra(a,q,n,e) + dijkstra(a,e,n,t) + dijkstra(a,t,n,r) ; 
    if(min(ans1,ans2) != INT_MAX && min(ans1,ans2) != -2 ){ 
        cout << min(ans1,ans2); 
    }else{ 
        cout << -1; 
    } 
    return 0; 
}
 
