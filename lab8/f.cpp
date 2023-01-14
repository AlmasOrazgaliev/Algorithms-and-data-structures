#include<bits/stdc++.h>
using namespace std;
long long p = 256;
long long q = 9007199254740881;
int main(){
    string s;
    cin>>s;
    unordered_map<long long, int> mp;
    int cnt=0;
   long long mod=1e9+7;
    for(int i=0;i<s.size();i++){
        long long h=0;
        for(int j=i;j<s.size();j++){
            h=(h*p+s[j]) % q;
            //cout<<c<<endl;
            mp[h]++;
            //cnt++;
        }
        
    }
    cout<<mp.size();
}