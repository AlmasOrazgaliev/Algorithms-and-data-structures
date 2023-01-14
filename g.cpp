#include<bits/stdc++.h>
using namespace std;

int primeIndex(int n){

    int index=1;
    int i=2;
    int index2=0;
    while(index2!=n){
        i++;
        bool ok=true;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                ok=false;
            }
        }
        if(ok){
            index++;
        }
        for(int j=2;j<=sqrt(index);j++){
            if(index%j==0){
                ok=false;
            }
        }
        if(ok){
            index2++;
        }
    }
    
    return i;
}
int main(){
    int n;
    cin>>n;
    cout<<primeIndex(n)<<endl;
    
}