#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long pm=1;
    string s="";
    long long h;
    long long sum=0;
    long long last=0;
    for(int i=0;i<n;i++){
        cin>>h;
        last=h;
        h=h-sum;
        sum=last;       
        //cout<<h<<" "<<sum<<endl;
        
        h=h/pm;
        h=h+97;
        s+=char(h);
        pm=pm*2;
    }
    cout<<s;

}