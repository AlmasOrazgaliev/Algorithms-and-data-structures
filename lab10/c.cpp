#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    vector<vector<int>> v(max(a,b));
    if(a==b){
        cout<<0;
        return 0;
    }
    if(a>b){
        cout<<a-b<<endl;
        while(a>b){
            a--;
            cout<<a<<" ";
        }
        return 0;
    }
    int i=0;
    queue<int> q;
    q.push(a);
    long long path[100000];
    path[a] = 0;
    v[i].push_back(q.front());
    i++;
    int k=0;
    while(!q.empty()){
        if(q.front()==b){
            k = path[q.front()];
            break;
        }
        q.push(q.front()-1);
        v[path[q.front()]+1].push_back(q.front()-1);
        q.push(q.front()*2);
        v[path[q.front()]+1].push_back(q.front()*2);
        path[q.front()-1]=path[q.front()]+1;
        path[q.front()*2]=path[q.front()]+1;
        i++; 
        q.pop();
    }
    int n = i;
    cout<<k<<endl;
    vector<int> ans;
    ans.push_back(b);
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]%2==1 && v[i][j]==b+1){
                ans.push_back(b+1);
                b++;
            }
            if(v[i][j]==b+1){
                ans.push_back(b+1);
                b++;
            }
            else if(v[i][j]==b/2){
                ans.push_back(b/2);
                b=b/2;
            }
        }
        cout<<endl;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}