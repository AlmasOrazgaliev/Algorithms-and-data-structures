#include <iostream>
#include <vector>
using namespace std;
vector<int> prefix_function(string a){
    vector<int> res(a.size());
    res[0]=0;   
    for(int i=1;i<a.size();i++){
        int j=res[i-1];
        while(j>0 && a[j]!=a[i]){
            j=res[j-1];
        }
        if(a[j]==a[i]){
            res[i]=j+1;
        } 
        else{
            res[i]=0;
        }
    }
    return res;
}

int main(){
    string a,b;
    cin>>a>>b;
    string s=a;
    a="";
    vector<int> n;
    string pattern;
    string text;
    if(s.size()>b.size()){
        n=prefix_function(b+'#'+s);
        text=s;
        pattern=b;
    }else{
        n=prefix_function(s+'#'+b);
        text=b;
        pattern=s;
    }
    for(int i=0;i<n.size();i++){
        cout<<n[i]<<" ";
    }
    cout<<endl;
    vector<int> res;
    for (int i=0;i<n.size();i++){
        if(n[i]==text.size()){
            res.push_back(i-2*pattern.size());
            cout<<i<<" ";
        }
    }
    if(res.size()==0){
        return -1;
    }
    vector<int> temp;
    if(res[0]!=0){
        temp=prefix_function(pattern+'#'+text.substr(0,res[0]));
        if(temp.size()==0){
            return -1;
        }
    }
    if(res[res.size()-1]!=text.size()-pattern.size()-1){
        cout<<"mynda kate"<<endl;
        temp=prefix_function(pattern+'#'+text.substr(res[res.size()-1],text.size()-res[res.size()-1]));
        if(temp.size()==0){
            return -1;
        }
    }
    for(int i=0;i<res.size()-1;i++){
        cout<<"ily mynda"<<endl;
        temp=prefix_function(pattern+'#'+text.substr(res[i]+pattern.size(),res[i+1]-res[i]));
        if(temp.size()==0){
            return -1;
        }
    }
    res.clear();
    int cnt=0;
    while(res.size()==0){
        vector<int> v;
        cnt++;
        a+=s;
        v=prefix_function(a+'#'+b);
        cout<<" myna jerge letty "<<endl;
        for (int i=0;i<a.size();i++){
            if(v[i]==b.size()){
                res.push_back(i-2*b.size());
            }
        }        
    }
    cout<<cnt;
}
