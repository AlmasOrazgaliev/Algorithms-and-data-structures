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
    unordered_map<int,int> mp;
    unordered_map<int,bool> used;
    used[a]=1;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        if(!used[q.front()-1] && q.front()-1<20000){
            mp[q.front()-1] = q.front();
            q.push(q.front()-1);
            used[q.front()-1]=1;
            if(q.front()-1==b) break;
        }
        if(!used[q.front()*2] && q.front()*2<20000){
            mp[q.front()*2] = q.front();
            q.push(q.front()*2);
            used[q.front()*2]=1;
            if(q.front()*2==b) break;
        }
        //cout<<" suck here "<<q.front()<<endl;
        q.pop();
    }
    int cnt=0;
    stack<int> s;
    while(a!=b){
        s.push(b);
        b = mp[b];
    }
    cout<<s.size()<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}