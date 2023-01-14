#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string , int> mp;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<s.size();j++){
            string c="";
            for(int k=j;k<s.size();k++){
                c+=s[k];
                auto it2=mp.find(c);
                if(i==0){
                    mp[c]=0;
                }
                else if(it2!=mp.end() && it2->second==i-1){
                    mp[c]=i;
                }
            }
        }
    }
    int max=0;
    for(auto &it:mp){
        if(max<it.first.size() && it.second==n-1){
            max=it.first.size();
        }
    }
    for(auto &it:mp){
        if(it.first.size()==max && it.second==n-1){
            cout<<it.first;
        }
        
    }
}