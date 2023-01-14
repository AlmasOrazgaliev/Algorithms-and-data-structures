#include<bits/stdc++.h>
using namespace std;
long long p=1000000007;
long long pow2(long long i, long long n){
    long long h=i;
    for(long long j=0;j<n;j++){
        h=(h*11)%p;
    }
    return h;
}
long long my_hash(string s) {
	long long  h = 0;
	for (long long i = 0; i < s.length(); i++) {
		h = (h + pow2(s[i] - 47 , i)) % p;

	}
	return h;
}
int main(){
    long long n;
    cin>>n;
    //  value hash
    map<string,long long> mp;
    vector<pair<string,long long>> v;
    string s,c;
    for(long long i=0;i<n*2;i++){
        cin>>s;
        long long h=my_hash(s);
        v.push_back({s,h});
        mp[s]=h;
    }
    int cnt=0;
    for(int i=0;i<v.size();i++){
        if(cnt==n){
            break;
        }
        auto it2=mp.find(to_string(v[i].second));
        if(it2!=mp.end()){
            cnt++;
            cout<<"Hash of string \""<<v[i].first<<"\" is "<<v[i].second<<endl;
        }
    }
    
}