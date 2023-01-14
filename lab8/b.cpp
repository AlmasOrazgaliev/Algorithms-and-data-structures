#include<bits/stdc++.h>
using namespace std;
long long my_hash(string s){
    long long h=0;
    long long pm=1;
    for(int i=0;i<s.size();i++){
        h=h*31+s[i];
    }
    return h;
}
int main(){
    string s,c,v;
    cin>>s>>c>>v;
    long long h=my_hash(v);
    long long j=my_hash(s.substr(0,v.size()));
    long long k=my_hash(c.substr(0,v.size()));
    long long pm=1;
    int cnt=0;
    for(int i=0;i<v.size()-1;i++){
        pm=pm*31;
    }
    for(int i=0;i+v.size()<=s.size();i++){
        if(j==h && k==h){
            cnt++;
            j=(j-pm*s[i])*31 + s[i + v.size()];
            k=(k-pm*c[i])*31 + c[i+v.size()];
        }else{
            j=(j-pm*s[i])*31 + s[i + v.size()];
            k=(k-pm*c[i])*31 + c[i+v.size()];
        }
    }
    cout<<cnt;
}