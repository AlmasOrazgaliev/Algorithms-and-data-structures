#include<bits/stdc++.h>
using namespace std;
vector<int> prefix(string s){
    vector<int> res(s.size());
    res[0]=0;
    for(int i=1;i<s.size();i++){
        int j=res[i-1];
        while(j>0 && s[i]!=s[j]){
            j=res[j-1];
        }
        if(s[i]==s[j]){
            res[i]=j+1;
        }else{
            res[i]=0;
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    string s;
    int x;
    while(n--){
        cin>>s>>x;
        if(s.size()==1){
            cout<<x<<endl;
            continue;
        }
        vector<int> v = prefix(s);
        int k = (v.size()-v[v.size()-1]);
        int sum=s.size();
        for(int i=1;i<x;i++){
            sum=sum+k;
        }
        cout<<sum<<endl;
    }
}