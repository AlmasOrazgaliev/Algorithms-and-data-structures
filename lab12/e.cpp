#include<bits/stdc++.h>
using namespace std;
struct Edge {
    int a, b, cost;
};

int n, m;
vector<Edge> edges;
const int INF = 1000000000;
vector<int> res;
void solve()
{
    vector<int> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES"<<endl;
        for (int v : cycle)
            res.push_back(v+1);
    }
}
int main(){
    cin>>n;
    int a[n][n];
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]!=100000){
                cnt++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=100000){
                Edge e;
                e.a=i;
                e.b=j;
                e.cost=a[i][j];
                edges.push_back(e);
                cnt++;
            }
        }
    }
    solve();
    if(res.size()!=0){
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
    }
    
}