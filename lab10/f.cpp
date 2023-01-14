#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
    vector<long long> a[n];
	//long long a[n][n];
    long long used[n];
	long long x,y;
    for(long long i=0;i<m;i++){
        cin>>x>>y;
        a[x-1].push_back(y-1);
        a[y-1].push_back(x-1);
    }
    long long s,f;
    cin>>s>>f;
    queue<long long> q;
    q.push(s-1);
    used[s-1]=1;
    while(!q.empty()){
        for(long long i=0;i<a[q.front()].size();i++){
            int k = a[q.front()][i];
            if(used[k]!=1){
                q.push(k);
                used[k]=1;
                if(k==f-1){
                    cout<<"YES";
                    return 0;
                }
                //cout<<i+1<<" ";
            }
        }
        //cout<<endl;
        q.pop();
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<a[i].size();j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(used[f-1]==1){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}