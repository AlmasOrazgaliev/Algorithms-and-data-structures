#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> a;
    a.resize(n);
    vector<bool> red;
    red.resize(n, 0);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0;i<q;i++){
        cin>>x>>y;
        if(x==1){
            red[y-1]=1;
        }else{
            int path[n];
            vector<bool> used;
            used.resize(n, 0);
            queue<int> q;
            q.push(y-1);
            used[y-1]=1;
            path[y-1]=0;
            bool ok=false;
            if(red[y-1]==1){
                    cout<<0<<endl;
                    //ans.push_back(0);
                    //ok=true;
                    //break;
            }
            else{
                while(!q.empty()){
                    ok=false;
                    for(int j=0;j<a[q.front()].size();j++){
                        int k = a[q.front()][j];
                        //cout<<k<<" ";
                        if(used[k]!=1){
                            q.push(k);
                            //cout<<k<<" ";
                            used[k]=1;
                            path[k]=path[q.front()]+1;
                            if(red[k]==1){
                            //ans.push_back(path[k]);
                                cout<<path[k]<<endl;
                                ok=true;
                                break;
                            }
                        }
                    }
                    //cout<<endl;
                    q.pop();
                    if(ok){
                        break;
                    }
                }
                if(!ok){
                    //ans.push_back(-1);
                    cout<<-1<<endl;
                }
            }
        }
    }
    
}