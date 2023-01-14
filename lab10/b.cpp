#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n][n];
    int path[n][2];
    queue<int> q;
    int used[n];
    for(int i=0;i<n;i++){
        used[i]=0;
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int x,y;
    cin>>x>>y;
    q.push(x);
    int cnt=1;
    used[x-1]=1;
    while(!q.empty()){
        for(int i=0;i<n;i++){
            if(a[q.front()-1][i]==1){
                if(used[i]==0){
                    q.push(i+1);
                    path[i][1] = cnt;
                    used[i]=1;
                }
            }
            if(i==y-1){
                break;
            }
        }
        cnt++;
        q.pop();
    }
    if(used[y-1]==0){
        cout<<-1;
    }else{
        cout<<path[y-1][1];
    }
    // for(int i=0;i<n;i++){
    //     cout<<i+1<<" "<<path[i][1]<<endl;
    // }
}
