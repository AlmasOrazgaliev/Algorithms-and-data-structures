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
    vector<int> res = prefix(s);
    vector<int> v;
    for(int i=0;i<s.size();i++){
        if(res[i]==t.size()){
            v.push_back(i-2*t.size());
        }
    }
    return v;
}
string shift(string s, int ind){
    string c="";
    c=c+s[s.size()-ind];
    c=c+s;
    //cout<<c<<endl;
    return c;
}
int main(){
    string s,t;
    cin>>s>>t;
    int cnt=0;
    string c=s;
    int size=s.size();
    vector<int> res;
    res=kmp(s,t);
    if(res.size()==0){
        s=s+s;
    }
    res=kmp(s,t);
    if(res.size()==0){
        cout<<-1;
    }else{
        cout<<c.size()-res[0];
    }
}