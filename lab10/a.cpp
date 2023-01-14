#include<iostream>
#include<queue>
#include<utility>
using namespace std;
pair<int,int> left(pair<int,int> p){
    return {p.first,p.second-1};
}
pair<int,int> up(pair<int,int> p){
    return {p.first-1,p.second};
}
pair<int,int> down(pair<int,int> p){
    return {p.first+1,p.second};
}
pair<int,int> right(pair<int,int> p){
    return {p.first,p.second+1};
}
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int used[n][m];
    int path[n][m];
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            used[i][j]=0;
            if(a[i][j]==2){
                q.push({i,j});
                used[i][j]=1;
                path[i][j]=0;
            }
        }
    }
    int cnt=0;
    bool flag=false;
    while(!q.empty()){
        flag=false;
        int to = q.front().first;
        int to2 = q.front().second;
        if(up(q.front()).first>-1){
            if(a[to-1][to2]==1 && used[to-1][to2]==0){
                a[to-1][to2]=2;
                q.push({to-1,to2});
                used[to-1][to2]=1;
                path[to-1][to2]=path[to][to2]+1;
                flag=true;
            }
        }
        if(down(q.front()).first<n){
            if(a[to+1][to2]==1 && used[to+1][to2]==0){
                a[to+1][to2]=2;
                q.push({to+1,to2});
                used[to+1][to2]=1;
                path[to+1][to2]=path[to][to2]+1;
                flag=true;
            }
        }
        if(right(q.front()).second<m){
            if(a[to][to2+1]==1 && used[to][to2+1]==0){
                a[to][to2+1]=2;
                q.push({to,to2+1});
                used[to][to2+1]=1;
                path[to][to2+1]=path[to][to2]+1;
                flag=true;
            }
        }
        if(left(q.front()).second>-1){
            if(a[to][to2-1]==1 && used[to][to2-1]==0){
                a[to][to2-1]=2;
                q.push({to,to2-1});
                used[to][to2-1]=1;
                path[to][to2-1]=path[to][to2]+1;
                flag=true;
            }
        }
        if(flag){
            cnt = path[to][to2]+1;
        }
        q.pop();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<cnt;
}