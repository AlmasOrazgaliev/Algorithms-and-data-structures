#include<bits/stdc++.h>
using namespace std;
long long my_hash(string s){
    long long h=0;
    for(int i=0;i<s.size();i++){
        h=h*31+s[i];
    }
    return h;
}
int main(){
    int n;
    while(cin>>n && n!=0){
        vector<pair<string,int>> v;
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            v.push_back({s,0});
        }
        string test;
        cin>>test;
        int max=0;
        for(int i=0;i<v.size();i++){
            long long h=my_hash(v[i].first);
            long long pm=1;
            for(int j=0;j<v[i].first.size()-1;j++){
                pm=pm*31;
            }
            int cnt=0;
            long long k=my_hash(test.substr(0,v[i].first.size()));
            for(int j=0;j+v[i].first.size()<=test.size();j++){
                if(h==k){
                    //cout<<j<<" "<<v[i].first<<endl;
                    cnt++;
                }
                k=(k-pm*test[j])*31+test[j+v[i].first.size()];
            }
            v[i].second=cnt;
            if(cnt>max){
                max=cnt;
            }
        }
        cout<<max<<endl;
        for(int i=0;i<v.size();i++){
            if(v[i].second==max){
                cout<<v[i].first<<endl;
            }
        }
    }
}