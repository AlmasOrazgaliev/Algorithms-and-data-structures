#include<bits/stdc++.h>
using namespace std;
vector<int> prefix(string s){
    vector<int> res (s.size());
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
int main(){
    string s;
    cin>>s;
    vector<int> v = prefix(s);
    cout<<v.size()-v[v.size()-1];
}