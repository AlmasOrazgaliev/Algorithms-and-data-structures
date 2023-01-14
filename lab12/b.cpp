#include <iostream>
using namespace std;
#include <limits.h>
 
 

int minDistance(int dist[], bool sptSet[],int n)
{
 
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
void printSolution(int dist[],int n)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
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
    //printSolution(dist,n);
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
    int res[4];
    for(int i=0;i<4;i++){
        cin>>res[i];
        res[i]--;
    }
    int ans = dijkstra(a, 0,n,res[3]);
    if(ans==INT_MAX){
        cout<<-1;
    }else{
        cout<<ans;
    }
 
    return 0;
}