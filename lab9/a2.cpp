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
    a=s;
    vector<int> res;
    int cnt=0;
    while(a.size()<b.size()){
        a+=s;
        cnt++;
    }
    int n=2;
    while(n--){        
        cnt++;

        vector<int> v;
        v=prefix_function(b+'#'+a);
        for (int i=0;i<v.size();i++){
            if(v[i]==b.size()){
                res.push_back(i-2*b.size());
            }
        }
        if(res.size()!=0){
            return cnt;
        }
        a+=s;
    }
    if(res.size()==0){
        cout<< -1;
    }
    cout<<cnt;
}