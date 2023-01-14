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
int main(){
    string s;
    cin>>s;
    vector<int> res = prefix(s);
    int cnt=0;
    
    for(int i=1;i<s.size();i++){
        int len=i-res[i-1];
        if(res[i-1]==0){
            continue;
        }
        if((i/len)%2==0 && i%len==0){
            cnt++;
        }
    }
    cout<<cnt;
}