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
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int n;
    cin>>n;
    string t;
    map<int,string> mp;
    vector<pair<int,string>> v;
    int max=0;
    while(n--){
        int maxlocal=0;
        cin>>t;
        string copy=t;
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        vector<int> res = prefix(t+'#'+s);
            if(res[res.size()-1]>maxlocal){
                maxlocal=res[res.size()-1];
            }
        if(max<maxlocal){
            max=maxlocal;
        }
        mp[maxlocal]=copy;
        v.push_back({maxlocal,copy});
    }
    if(max==0){
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<v.size();i++){
        if(v[i].first==max){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<v.size();i++){
        if(v[i].first==max){
            cout<<v[i].second<<endl;
        }
    }
}