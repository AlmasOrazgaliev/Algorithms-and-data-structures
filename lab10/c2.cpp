#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    cin>>a>>b;
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
    else{
        queue<long long> q;
        q.push(a);
        //vector<long long> v[100000];
        //bool used[100000];
        long long path[100000];
        bool used[1000][1000];
        path[a] = 0;
        //used[a] = 1;
        long long k=0;
        while(!q.empty()){
            if(q.front()-1==b){
                //used[q.front()-1]=1;
                q.push(q.front()-1);
                path[q.front()-1]=path[q.front()]+1;
                used[path[q.front()-1]][q.front()-1] = 1; 
                k = q.front()-1;
                break;
            }
            if(q.front()*2==b){
                //used[q.front()*2]=1;
                q.push(q.front()*2);
                path[q.front()*2]=path[q.front()]+1;
                used[path[q.front()*2]][q.front()*2] = 1; 
                k = q.front()*2;
                break;
            }else{
                q.push(q.front()-1);
                q.push(q.front()*2);
                used[path[q.front()-1]][q.front()-1] = 1; 
                used[path[q.front()*2]][q.front()*2] = 1; 
                //used[q.front()-1] = 1;
                //used[q.front()*2] = 1;
                path[q.front()-1]=path[q.front()]+1;
                path[q.front()*2]=path[q.front()]+1;
            }
            //cout<<"first while";
            q.pop();
        }
        cout<<path[k]<<endl;
        int cnt = path[k];
        return 0;
        deque<long long> d;
        while(k!=a){
            d.push_back(k);
            cout<<k<<" ";
            if(k%2==1){
                k=k+1;
                cnt--;
            }else{
                if(used[cnt][k/2]==1){
                    k=k/2;
                    cnt--;
                }
                else if(used[cnt][k+1]==1){
                    k=k+1;
                    cnt--;
                }
            }
           // cout<<"second while";
        }
        while(d.size()!=0){
            cout<<d.back()<<" ";
            d.pop_back();
        }
    }
}