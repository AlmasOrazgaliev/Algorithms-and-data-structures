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
    long long  n;
    cin >> n ;
    int array [n] ;
    Graph graph (n) ;
    for( int i = 0 ; i < n ; i++) {
        cin >> array [i] ;
    }
    for( int i = 0 ; i < n - 1 ; i++ ){
        for( int j = i + 1 ; j < n ; j++ ){
            graph.addEdge( i , j , array [i] +array[j] );
        }
    }
    graph.kruskals_mst();
}