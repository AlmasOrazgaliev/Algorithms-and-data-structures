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
    string s;
    cin>>s;
    int n;
    cin>>n;
    int l,r;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        string t = s.substr(l-1,r-l+1);
        long long pm=1;
        for(int i=0;i<t.size()-1;i++){
            pm=pm*31;
        }
        long long h=my_hash(t);
        long long k=my_hash(s.substr(0,t.size()));
        int cnt=0;
        for(int i=0;i+t.size()<=s.size();i++){
            if(h==k){
                cnt++;
            }
            k=(k-pm*s[i])*31+s[i+t.size()];
        }
        cout<<cnt<<endl;
    }
}