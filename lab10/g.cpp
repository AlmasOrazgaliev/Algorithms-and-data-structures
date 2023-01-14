#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fori(n) for(int i = 0;i < n;i++)
#define fori1(n) for(int i = 1;i <= n;i++)
#define forj(n) for(int j = 0;j < n;j++)
#define forj1(n) for(int j = 1;j <= n;j++)
#define mp make_pair
#define pb push_back
#define MAX 1000
vector<int> a[MAX];
int i,j;
int colour[MAX];
int x,y,n,m;
int p[MAX];
int st,fin;
bool has = false;
bool ok = false;
void dfs(int i){
    colour[i] = 1;
    for(int j = 0;j < a[i].size();j++){
        if(has)
            return;
        if(colour[a[i][j]] == 0){
            p[a[i][j]] = i;
            dfs(a[i][j]);
        }else if(colour[a[i][j]] == 1){
            st = a[i][j];
            fin = i;
            p[st] = fin;
            has = true;
        }
    }
    colour[i] = 2;
}
void dfs1(int i,int ig_1,int ig_2){
    colour[i] = 1;
    for(int j = 0;j < a[i].size();j++){
        if(i == ig_1 and a[i][j] == ig_2){
            continue;
        }
        if(colour[a[i][j]] == 0){
            dfs1(a[i][j],ig_1,ig_2);
        }else if(colour[a[i][j]] == 1){
            ok = true;  
        }
    }
    colour[i] = 2;
}
int main(){
    cin >> n >> m;
    fori(m){
        cin >> x >> y;
        a[x].pb(y);
    }
    fori1(n){
        if(colour[i] == 0){
            dfs(i);
        }
    }
    if(!has){
        cout << "YES";
        return 0;
    }
    int ig_1,ig_2;
    int ch;
    for(int i = 0;i <= n;i++)
            colour[i] = 0;
    for(int v = fin;v != ch;v = p[v]){
        if(v == fin)
            ch = fin;
        for(int i = 0;i <= n;i++)
            colour[i] = 0;
        ig_1 = p[v];
        ig_2 = v;
        fori1(n){
            if(colour[i] == 0){
                dfs1(i,ig_1,ig_2);
            }
        }
        if(!ok){ 
            cout << "YES";
            return 0;
        }
        ok = false;
    }
    cout << "NO";
    return 0;
}