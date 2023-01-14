#include<bits/stdc++.h>
using namespace std;
vector<int> prefix(string s){
    vector<int> res(s.size());
    res[0]=0;
    for(int i=1;i<s.size();i++){
        int j=res[i-1];
        while(j>0 && s[j]!=s[i]){
            j=res[j-1];
        }
        if(s[j]==s[i]){
            res[i]=j+1;
        }else{
            res[i]=0;
        }
    }
    return res;
}
vector<int> kmp(string s, string t){
    s=t+'#'+s;
    vector<int> res;
    vector<int> v=prefix(s);
    for(int i=0;i<s.size();i++){
        cout<<v[i]<<" ";
        if(v[i]==t.size()){
            
            res.push_back(i-2*t.size());
        }
    }
    cout<<endl;
    return res;
}
int main(){
    string t;
    cin>>t;
    string s;
    cin>>s;
    vector<int> res=kmp(t,s);
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]+1<<" ";
    }
}