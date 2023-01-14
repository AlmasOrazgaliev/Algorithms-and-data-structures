#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<char> q;
    for(int i=0;i<s.size();i++){ 
        if(!q.empty()){
            if(q.top()==s[i]){
                q.pop();
            }
            else{
                q.push(s[i]);
            }
        }else{
            q.push(s[i]);
        }
        
    }
    if(q.size()>0){
        cout<<"NO";
    }else{
        cout<<"YES";
    }
}