#include <iostream> 
#include <string> 
using namespace std; 


 
int main(){ 
    // freopen("arrange.in", "r", stdin);
    // freopen("arrange.out", "w", stdout);
    int t; 
    cin>>t; 
    int a=65; 
    int cnt=0; 
    int maxi=0; 
    for(int i=0;i<=t;i++){ 
        string s; 
        getline(cin,s); 
         
        if(int(s[0]) == a){ 
            cnt++;
            if(cnt > maxi) maxi = cnt; 
            a++; 
            if(a==91){
                a = 65;
            }
        }else{
            if(int(s[0] == a-1)){
                cnt=1; 
                continue;
            }
            if(int(s[0]) == 65){
                a = 66;
                cnt=1;
                continue;
            }
            cnt=0; 
            a=65; 
        }

    }    
    cout<<maxi; 
}