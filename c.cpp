#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<char> dq;
    vector<char> bq;
    string s,c;
    cin>>s>>c;
    for(int i=0;i<s.size();i++){
        if(s[i]!='#'){
            dq.push_back(s[i]);
        }else{
            dq.pop_back();
        }
    }
    for(int i=0;i<c.size();i++){
        if(c[i]!='#'){
            bq.push_back(c[i]);
        }else{
            bq.pop_back();
        }
    }
    s="";
    c="";
    for(int i=0;i<dq.size();i++){
        s+=dq[i];
    }
    for(int i=0;i<bq.size();i++){
        c+=bq[i];
    }
    if(c==s){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}