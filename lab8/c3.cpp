#include<bits/stdc++.h>
using namespace std;
long long p = 26;
long long q = 1e9+7;
int main(){
    string s;
    cin>>s;
    int a[s.size()];
    for(int i=0;i<s.size();i++){
        a[i]=0;
    }
    int n;
    cin>>n;
    string c;
    for(int i=0;i<n;i++){
        cin>>c;
        long long pm=1;
        long long h=0;
        long long k=0;
        for(int j=0;j<c.size()-1;j++){
            pm=(pm*p)%q;
        }
        for(int j=0;j<c.size();j++){
            k=(k*p+s[j])%q;
            h=(h*p+c[j])%q;
        }
        for(int j=0;j<=s.size()-c.size();j++){
            if(h==k){
                //cout<<j<<" found"<<endl;
                for(int l=j;l<c.size()+j;l++){
                    //cout<<l<<" ";
                    a[l]+=1;
                }
                //cout<<endl;
            }
            if(j < s.size() - c.size()){ 
                k=(((k-s[j]*pm)*p)+s[j+c.size()])%q;
                //t = (((t - s[i] * h) * d) + s[i + pattern.size()]) % q; 
                if(k < 0){ 
                    k += q; 
                } 
            }
            //k=((k-s[j]*pm)*p+s[j+c.size()])%q;
        }
    }
    for(int i=0;i<s.size();i++){
        if(a[i]==0){
            //cout<<i<<" ";
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}