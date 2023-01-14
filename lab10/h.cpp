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
    bool used[n][m];
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            a[i][j]=(s[j]-'0');
            used[i][j]=0;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1 && used[i][j]==0){
                used[i][j]=1;
                q.push({i,j});
                while(!q.empty()){
                    int f = q.front().first;
                    int sec = q.front().second;
                    if(up(q.front()).first>-1){
                        if(a[f-1][sec]==1 && used[f-1][sec]==0){
                            q.push({f-1,sec});
                            used[f-1][sec]=1;
                            
                        }
                    }
                    if(down(q.front()).first<n){
                        if(a[f+1][sec]==1 && used[f+1][sec]==0){
                            q.push({f+1,sec});
                            used[f+1][sec]=1;
                            
                        }
                    }
                    if(right(q.front()).second<m){
                        if(a[f][sec+1]==1 && used[f][sec+1]==0){
                            q.push({f,sec+1});
                            used[f][sec+1]=1;
                        }   
                    }
                    if(left(q.front()).second>-1){
                        if(a[f][sec-1]==1 && used[f][sec-1]==0){
                            q.push({f,sec-1});
                            used[f][sec-1]=1;
                        }
                    }
                    q.pop();
                }
                cnt++;
            }
        }
    }
    cout<<cnt;
}