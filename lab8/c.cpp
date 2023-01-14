#include<bits/stdc++.h>
using namespace std;
long long my_hash(string s){
    long long h=0;
    for(int i=0;i<s.size();i++){
        h=(h*26+s[i])%int(1e9+7);
    }
    return h;
}
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<pair<string,pair<long long, int>>> v(n);
    for(int i=0;i<n;i++){
        string c;
        cin>>c;
        v[i]={c,{my_hash(c),0}};
    }
    bool ok = true;
    int last=0;
    for(int i=last;i<s.size();i++){
        if(ok && last<i){
            cout<<"NO";
            return 0;
        }
        bool ok=true;
        for(int j = 0; j < n; j++){
            long long k = my_hash(s.substr(i,v[j].first.size()));
            if(v[j].second.first==k){
                v[j].second.second++;
                ok=false;
                last=i+v[j].first.size();
            }
        }
    }
   
    if(last==s.size()){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}