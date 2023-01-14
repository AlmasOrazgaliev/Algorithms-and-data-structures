#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cntS=0;
    int cntK=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='S'){
            cntK++;
        }else{
            cntS++;
        }
    }
    cout<<cntK<<" "<<cntS<<endl;
    if(s.size()==1){
        if(cntS==1){
            cout<<"KATSURAGI";
        }else{
           cout<<"SAKAYANAGI"; 
        }
        return 0;
    }
    if(cntK==cntS){
        if(s[n-1]=='S'){
            cout<<"KATSURAGI";
        }else{
           cout<<"SAKAYANAGI"; 
        }
        return 0;
    }
    if(cntK>(n/2) && cntK>cntS){
        cout<<"KATSURAGI";
    }else{
        cout<<"SAKAYANAGI";
    }
}